#ifndef ADVANCEDFX_MODULE_H
#define ADVANCEDFX_MODULE_H
#include "AdvancedfxTypes.h"

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define ADVANCEFDX_DLL_EXPORT __attribute__ ((dllexport))
#define ADVANCEFDX_DLL_IMPORT __attribute__ ((dllimport))
#else
#define ADVANCEFDX_DLL_EXPORT __declspec(dllexport)
#define ADVANCEFDX_DLL_IMPORT __declspec(dllimport)
#endif
#define ADVANCEFDX_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define ADVANCEFDX_DLL_EXPORT __attribute__ ((visibility ("default")))
#define ADVANCEFDX_DLL_IMPORT __attribute__ ((visibility ("default")))
#define ADVANCEFDX_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define ADVANCEFDX_DLL_EXPORT
#define ADVANCEFDX_DLL_IMPORT
#define ADVANCEFDX_DLL_LOCAL
#endif
#endif

#define ADVANCEDFX_MODULE_INIT_IDENTIFIER AdvancedfxModuleInit

#ifdef __cplusplus
#define ADVANCEDFX_EXTERNC extern "C"
#else
#define ADVANCEDFX_EXTERNC
#endif

struct AdvancedfxModuleClass
{
    /**
	 * @param event will remain strongly referenced by This.
	 */
	AdvancedfxBool (*DeletingAdd)(void * This, struct AdvancedfxEventClass ** event);

	void (*DeletingRemove)(void * This, struct AdvancedfxEventClass ** event);

	void (*AddRef)(void * This);

	void (*Release)(void * This);
};

#define ADVANCEDFX_MODULE_INIT_FN ADVANCEDFX_EXTERNC struct AdvancedfxModuleRefClass ** ADVANCEDFX_MODULE_INIT_IDENTIFIER (struct AdvancedfxRegistryClass ** registry)

#endif
