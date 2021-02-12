#ifndef ADVANCEDFX_INJECTOR_H
#define ADVANCEDFX_INJECTOR_H

#include <interfaces/c/AdvancedfxTypes.h>

#define ADVANCEDFX_INJECTOR_RESULT_OK 0
#define ADVANCEDFX_INJECTOR_RESULT_QUESTION_CONTINUE 1

#define ADVANCEDFX_INJECTOR_RESULT_ERROR -1
#define ADVANCEDFX_INJECTOR_RESULT_ERROR_EXCEPTION -2
#define ADVANCEDFX_INJECTOR_RESULT_ERROR_WINAPI_OpenProcess -3
#define ADVANCEDFX_INJECTOR_RESULT_ERROR_WINAPI_VirtualAllocEx_ArgDllDir -4
#define ADVANCEDFX_INJECTOR_RESULT_ERROR_WINAPI_VirtualAllocEx_ArgDllFilePath -5
#define ADVANCEDFX_INJECTOR_RESULT_ERROR_WINAPI_VirtualAllocEx_ImageAfxHook -6
#define ADVANCEDFX_INJECTOR_RESULT_ERROR_WINAPI_WriteProcessMemory_ArgDllDir -7
#define ADVANCEDFX_INJECTOR_RESULT_ERROR_WINAPI_WriteProcessMemory_ArgDllFilePath -8
#define ADVANCEDFX_INJECTOR_RESULT_ERROR_WINAPI_FlushInstructionCache -9
#define ADVANCEDFX_INJECTOR_RESULT_ERROR_WINAPI_CreateRemoteThread -10
#define ADVANCEDFX_INJECTOR_RESULT_ERROR_WINAPI_GetExitCodeThread -11
#define ADVANCEDFX_INJECTOR_RESULT_ERROR_EXITCODE_INVALID -12
#define ADVANCEDFX_INJECTOR_RESULT_ERROR_EXITCODE_VALUE -13

#define ADVANCEDFX_INJECTOR_ARCH_x86 0
#define ADVANCEDFX_INJECTOR_ARCH_x64 1

typedef AdvancedfxInt32 AdvancedfxInjectorResult;

struct AdvancedfxInjectorClass {

	void (*AddRef)(void * This);
	
	void (*Release)(void * This);

	/**
	 * @param event will remain strongly referenced by This.
	 */
	AdvancedfxBool (*DeletingAdd)(void * This, struct AdvancedfxEventClass ** event);

	void (*DeletingRemove)(void * This, struct AdvancedfxEventClass ** event);

    AdvancedfxInjectorResult (*Inject)(void* This, AdvancedfxUInt32 processId, AdvancedfxCString * dllPath, AdvancedfxInt32 arch);

    AdvancedfxInjectorResult (*Continue)(void * This);

    AdvancedfxUInt32 * (*GetLastErrorCode)(void * This);

    struct AdvancedfxStringClass ** (*GetLastErrorText)(void * This);
};

// FUNCTION: AdvancedfxInjector_New:
// ARG: struct AdvancedfxInjectorClass ***
#define AdvancedfxInjector_New_UUID_FN(fn) ADVANCEDFX_UUID_APPLY_FN(fn, 0xf3941e6e, 0x377f, 0x4d5c, 0x97, 0xb9, 0xe4, 0xf8, 0x0, 0x17, 0x95, 0xfb)

#endif // ADVANCEDFX_INJECTOR_H
