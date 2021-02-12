cmake_minimum_required (VERSION 3.15)

project (injector LANGUAGES C CXX)

if (NOT ${PROJECT_NAME}-MultiBuild)
  include(ExternalProject)

  macro (setup_arch arch)
    set(CMAKE_GENERATOR_PLATFORM ${arch})  
    ExternalProject_Add (${PROJECT_NAME}-${arch}
      DEPENDS afxhook afxhook_x64
      BINARY_DIR "../${PROJECT_NAME}-${arch}"
      SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}"      
      CMAKE_ARGS
        -D${PROJECT_NAME}-MultiBuild=ON
        -DPROJECT_NAME_MULTI=${PROJECT_NAME}-${arch}
        -Dafxhook_BINARY_DIR=${afxhook_BINARY_DIR}
      BUILD_COMMAND
        ${CMAKE_COMMAND} --build . --config $<CONFIG> -- -r
      INSTALL_COMMAND
        ${CMAKE_COMMAND} -P cmake_install.cmake        
    )
  endmacro()

  setup_arch(Win32)
  setup_arch(x64)

  add_custom_target(injector
    DEPENDS injector-Win32 injector-x64
  )

  return()
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17 /D_UNICODE /DUNICODE")

add_executable(${PROJECT_NAME_MULTI}
    "main.cpp"
)

include(../cmake/FileEmbed.cmake)
FileEmbedSetup(${PROJECT_NAME_MULTI}-embed)

if("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "Win32")
FileEmbedAdd(${PROJECT_NAME_MULTI}-embed "${afxhook_BINARY_DIR}/AfxHook.dat")
else()
FileEmbedAdd(${PROJECT_NAME_MULTI}-embed "${afxhook_BINARY_DIR}/x64/AfxHook.dat")
endif()

target_link_libraries(${PROJECT_NAME_MULTI} ${PROJECT_NAME_MULTI}-embed)
