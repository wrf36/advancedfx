# Based originally on https://gitlab.com/jhamberg/cmake-examples/-/blob/master/cmake/FileEmbed.cmake

function(FileEmbedSetup embed_project_name)

    if (NOT EXISTS ${CMAKE_BINARY_DIR}/../${embed_project_name})
        file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/../${embed_project_name})
    endif ()

    if (NOT EXISTS ${CMAKE_BINARY_DIR}/../${embed_project_name}/file_embed_empty.c)
        file(WRITE ${CMAKE_BINARY_DIR}/../${embed_project_name}/file_embed_empty.c "")
    endif ()

    add_library(${embed_project_name} ${CMAKE_BINARY_DIR}/../${embed_project_name}/file_embed_empty.c)
    target_include_directories(${embed_project_name} PUBLIC ${CMAKE_BINARY_DIR}/../${embed_project_name})
endfunction()

function(FileEmbedAdd embed_project_name file)
    FileEmbedGenerate(${embed_project_name} ${file} var)
    target_sources(${embed_project_name} PUBLIC ${var})

    add_custom_command(
            OUTPUT ${var}
            COMMAND ${CMAKE_COMMAND}
            -DRUN_FILE_EMBED_GENERATE=1
            -DFILE_EMBED_PROJECT_NAME=${embed_project_name}
            -DFILE_EMBED_GENERATE_PATH=${file}
            -P ${CMAKE_SOURCE_DIR}/cmake/FileEmbed.cmake
            MAIN_DEPENDENCY ${file}
    )
endfunction()

function(FileEmbedGenerate embed_project_name file generated_c)

    get_filename_component(base_filename ${file} NAME)
    set(output_filename "${base_filename}.c")
    string(MAKE_C_IDENTIFIER ${base_filename} c_name)
    file(READ ${file} content HEX)
    message(${content})

    # Separate into individual bytes.
    string(REGEX MATCHALL "([A-Fa-f0-9][A-Fa-f0-9])" SEPARATED_HEX ${content})

    set(output_c "")

    set(counter 0)
    foreach (hex IN LISTS SEPARATED_HEX)
        string(APPEND output_c "0x${hex},")
        MATH(EXPR counter "${counter}+1")
        if (counter GREATER 16)
            string(APPEND output_c "\n    ")
            set(counter 0)
        endif ()
    endforeach ()

    set(output_c "
#include \"${c_name}.h\"
uint8_t ${c_name}_data[] = {
    ${output_c}
}\;
unsigned ${c_name}_size = sizeof(${c_name}_data)\;
")

    set(output_h "
#ifndef ${c_name}_H
#define ${c_name}_H
#include \"stdint.h\"
extern uint8_t ${c_name}_data[]\;
extern unsigned ${c_name}_size\;
#endif // ${c_name}_H
    ")


    if (NOT EXISTS ${CMAKE_BINARY_DIR}/../${embed_project_name})
        file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/../${embed_project_name})
    endif ()


    file(WRITE ${CMAKE_BINARY_DIR}/../${embed_project_name}/${c_name}.c
            ${output_c})

    file(WRITE ${CMAKE_BINARY_DIR}/../${embed_project_name}/${c_name}.h
            ${output_h})

    set(${generated_c} ${CMAKE_BINARY_DIR}/../${embed_project_name}/${c_name}.c PARENT_SCOPE)

endfunction()

if (RUN_FILE_EMBED_GENERATE)
    FileEmbedGenerate(${FILE_EMBED_PROJECT_NAME} ${FILE_EMBED_GENERATE_PATH} var)
endif ()
