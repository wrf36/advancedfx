#ifndef ADVANCEDFX_TYPES_H
#define ADVANCEDFX_TYPES_H



// Platform definitions ////////////////////////////////////////////////////////


#if (_WIN32 || _WIN64) && _WIN64 || __GNUC__ && __x86_64__ || __ppc64__
#define ADVANCEDFX_ENV64
#else
#define ADVANCEDFX_ENV32
#endif



// UUID related macros /////////////////////////////////////////////////////////


#define ADVANCEDFX_UUID_APPLY_FN(fn,time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) fn(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0)

#define ADVANCEDFX_UUID_BYTE_F(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)((time_low & 0xff000000) >> 12))
#define ADVANCEDFX_UUID_BYTE_E(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)((time_low & 0x00ff0000) >> 8))
#define ADVANCEDFX_UUID_BYTE_D(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)((time_low & 0x0000ff00) >> 4))
#define ADVANCEDFX_UUID_BYTE_C(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)((time_low & 0x000000ff)))
#define ADVANCEDFX_UUID_BYTE_B(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)((time_mid & 0xff00) >> 4))
#define ADVANCEDFX_UUID_BYTE_A(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)((time_mid & 0x00ff)))
#define ADVANCEDFX_UUID_BYTE_9(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)((time_hi_and_version & 0xff00) >> 4))
#define ADVANCEDFX_UUID_BYTE_8(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)((time_hi_and_version & 0x00ff)))
#define ADVANCEDFX_UUID_BYTE_7(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)((clock_seq_hi_and_res__clock_seq_low & 0xff00) >> 4))
#define ADVANCEDFX_UUID_BYTE_6(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)((clock_seq_hi_and_res__clock_seq_low & 0x00ff)))
#define ADVANCEDFX_UUID_BYTE_5(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)node_uc5)
#define ADVANCEDFX_UUID_BYTE_4(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)node_uc4)
#define ADVANCEDFX_UUID_BYTE_3(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)node_uc3)
#define ADVANCEDFX_UUID_BYTE_2(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)node_uc2)
#define ADVANCEDFX_UUID_BYTE_1(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)node_uc1)
#define ADVANCEDFX_UUID_BYTE_0(time_low,time_mid,time_hi_and_version,clock_seq_hi_and_res__clock_seq_low,node_uc5,node_uc4,node_uc3,node_uc2,node_uc1,node_uc0) ((AdvancedfxUInt8)node_uc0)



// Primitive types /////////////////////////////////////////////////////////////


#define ADVANCEDFX_NULLPTR ((void *)0)


//
// AdvancedfxVoid

#define AdvancedfxVoid_UUID_FN(fn) ADVANCEDFX_UUID_APPLY_FN(fn,0x6C51D0CF0,x3653,0x43AE,0xB753,0xC1,0x07,0x33,0xDD,0x19,0x9E)


//
// AdvancedfxBool

typedef unsigned char AdvancedfxBool;

#define ADVANCEDFX_FALSE 0
#define ADVANCEDFX_True 1

#define AdvancedfxBool_UUID_FN(fn) ADVANCEDFX_UUID_APPLY_FN(fn,0xF5E02116,0xD623,0x499F,0xABBF,0x2B7EAA4AB8DF)


//
// AdvancedfxUInt8

typedef unsigned char AdvancedfxUInt8;

#define AdvancedfxUInt8_UUID_FN(fn) ADVANCEDFX_UUID_APPLY_FN(fn,0x5760F402,0xCF8D,0x436F,0xB38A,0x0B,0x34,0x0E,0xE4,0x53,0x6C)


//
// AdvancedfxUInt32

typedef unsigned long AdvancedfxUInt32;

#define AdvancedfxUInt32_UUID_FN(fn) ADVANCEDFX_UUID_APPLY_FN(fn,0x2C0330F6,0xEBD2,0x4C4B,0xAB0F,0x57,0x22,0x08,0x0C,0x59,0x92)


//
// AdvancedfxInt32

typedef signed long AdvancedfxInt32;

#define AdvancedfxInt32_UUID_FN(fn) ADVANCEDFX_UUID_APPLY_FN(fn,0xBA19A48B,0x6780,0x4391,0x84A5,0x38,0x3D,0x8C,0x55,0xD9,0x0B)


//
// AdvancedfxSize

#ifdef ADVANCEDFX_ENV64
typedef unsigned __int64 AdvancedfxSize;
#else
typedef unsigned int AdvancedfxSize;
#endif

#define AdvancedfxSize_UUID_FN(fn) ADVANCEDFX_UUID_APPLY_FN(fn,0x0C5AFAAD,0xF01F,0x4D60,0x8051,0x86,0xC9,0xBE,0x78,0xFE,0xEF)


//
// AdvancedfxCString

typedef const char* AdvancedfxCString;

#define AdvancedfxCString_UUID_FN(fn) ADVANCEDFX_UUID_APPLY_FN(fn,0x9C6932EB,0x17A1,0x49C0,0xA484,0x59,0x08,0xEB,0x59,0xB8,0x69)

typedef void (*AdvancedfxCString_Set)(AdvancedfxCString value);


//
// AdvancedfxFloat

typedef float AdvancedfxFloat;

#define AdvancedfxFloat_UUID_FN(fn) ADVANCEDFX_UUID_APPLY_FN(fn,0x271da19, 0xc021, 0x43c3, 0xb0, 0xc9, 0xc6, 0xd9, 0xb5, 0x98, 0x48, 0xd9)


////////////////////////////////////////////////////////////////////////////////


//
// AdvancedfxUuid

struct AdvancedfxUuid
{
	AdvancedfxUInt8 ucF;
	AdvancedfxUInt8 ucE;
	AdvancedfxUInt8 ucD;
	AdvancedfxUInt8 ucC;
	AdvancedfxUInt8 ucB;
	AdvancedfxUInt8 ucA;
	AdvancedfxUInt8 uc9;
	AdvancedfxUInt8 uc8;
	AdvancedfxUInt8 uc7;
	AdvancedfxUInt8 uc6;
	AdvancedfxUInt8 uc5;
	AdvancedfxUInt8 uc4;
	AdvancedfxUInt8 uc3;
	AdvancedfxUInt8 uc2;
	AdvancedfxUInt8 uc1;
	AdvancedfxUInt8 uc0;
};

#define AdvancedfxUuid_UUID_FN(fn) ADVANCEDFX_UUID_APPLY_FN(fn,0x9A58B3EA,0xB183,0x44DE,0x8B92,0x3F,0x7D,0xF1,0x25,0x7F,0xF7)


//
// AdvancedfxVersion

struct AdvancedfxVersion {
	AdvancedfxUInt32 major;
	AdvancedfxUInt32 minor;
	AdvancedfxUInt32 revison;
	AdvancedfxUInt32 build;
};

#define AdvancedfxVersion_UUID_FN(fn) ADVANCEDFX_UUID_APPLY_FN(fn, 0x2b5d73af, 0xc50b, 0x4182, 0x8c, 0xee, 0xc4, 0x9f, 0xc9, 0x6d, 0xa5, 0xa0)


////////////////////////////////////////////////////////////////////////////////

struct AdvancedfxEventClass {

	void (*AddRef)(void * This);
	
	void (*Release)(void * This);

	void (*Trigger)(void * This);
}:

struct AdvancedfxStringClass {
	void (*AddRef)(void * This);
	
	void (*Release)(void * This);

	AdvancedfxCString (*Get)(void * This);

	AdvancedfxBool (*Set)(void * This, AdvancedfxCString value);
};

struct AdvancedfxFunctionClass {

	void (*AddRef)(void * This);
	
	void (*Release)(void * This);

	/**
	 * @param event will remain strongly referenced by This.
	 */
	AdvancedfxBool (*DeletingAdd)(void * This, struct AdvancedfxEventClass ** event);

	void (*DeletingRemove)(void * This, struct AdvancedfxEventClass ** event);

	void (*Call)(void * This, void * arg);
};

struct AdvancedfxRegistryClass {

	void (*AddRef)(void * This);

	void (*Release)(void * This);

	/**
	 * @param event will remain strongly referenced by This.
	 */
	AdvancedfxBool (*DeletingAdd)(void * This, struct AdvancedfxEventClass ** event);

	void (*DeletingRemove)(void * This, struct AdvancedfxEventClass ** event);

	/**
	 * @param function will remain strongly referenced by This.
	 */
	AdvancedfxBool (*AddFunction)(void * This, struct AdvancedfxUuid * uuid, struct AdvancedfxFunctionClass ** function);

	void (*RemoveFunction)(void * This, struct AdvancedfxUuid * uuid);

	struct AdvancedfxFunctionClass ** (*GetFunction)(void * This, struct AdvancedfxUuid * uuid);
};

#endif // ADVANCEDFX_TYPES_H
