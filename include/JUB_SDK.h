#ifndef JUB_SDK_H
#define JUB_SDK_H

// Generic helper definitions for shared library support
#if defined _MSC_VER || defined __CYGWIN__
#define JUB_COINCORE_DLL_IMPORT extern "C" __declspec(dllimport)
#define JUB_COINCORE_DLL_EXPORT extern "C" __declspec(dllexport)
#define JUB_COINCORE_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define JUB_COINCORE_DLL_IMPORT __attribute__((visibility("default")))
#define JUB_COINCORE_DLL_EXPORT __attribute__((visibility("default")))
#define JUB_COINCORE_DLL_LOCAL __attribute__((visibility("internal")))
#else
#define JUB_COINCORE_DLL_IMPORT
#define JUB_COINCORE_DLL_EXPORT
#define JUB_COINCORE_DLL_LOCAL
#endif
#endif

// Tag to deprecate functions and methods.
// Gives a compiler warning when they are used.
#if defined _MSC_VER || defined __CYGWIN__
#define BC_DEPRECATED __declspec(deprecated)
#else
#if __GNUC__ >= 4
#define JUB_DEPRECATED __attribute__((deprecated))
#else
#define JUB_DEPRECATED
#endif
#endif

// Avoid namespace conflict between boost::placeholders and std::placeholders.
#define BOOST_BIND_NO_PLACEHOLDERS

// Define so we can have better visibility of lcov exclusion ranges.
#define LCOV_EXCL_START(text)
#define LCOV_EXCL_STOP()


/* === Library typedef: === */
#ifndef IN
    #define IN
#endif

#ifndef OUT
    #define OUT
#endif

#ifndef INOUT
    #define INOUT
#endif

#define JUB_TRUE 1
#define JUB_FALSE 0

#ifndef JUB_DISABLE_TRUE_FALSE
#ifndef FALSE
    #define FALSE JUB_FALSE
#endif

#ifndef TRUE
    #define TRUE JUB_TRUE
#endif
#endif

/* an unsigned 8-bit value */
typedef unsigned char JUB_BYTE;

/* an unsigned 8-bit character */
typedef JUB_BYTE JUB_UCHAR;

/* an unsigned/signed 8-bit character, decide by complie*/
typedef char JUB_CHAR;

/* an 8-bit UTF-8 character */
typedef JUB_BYTE JUB_UTF8UCHAR;

/* a BYTE-sized Boolean flag */
typedef JUB_BYTE JUB_BBOOL;

/* an unsigned value, at least 32 bits long */
typedef unsigned long int JUB_ULONG;

/* a signed value, the same size as a JUB_ULONG */
typedef signed long int  JUB_LONG;

typedef unsigned int JUB_UINT32;

typedef unsigned short JUB_UINT16;

/* uint64 */
typedef unsigned long long JUB_UINT64;

/* signed uint64 */
typedef signed long long JUB_INT64;

#define JUB_PTR *
typedef JUB_CHAR JUB_PTR            JUB_CHAR_PTR;
typedef JUB_CHAR_PTR JUB_PTR        JUB_CHAR_PTR_PTR;
typedef const JUB_CHAR JUB_PTR      JUB_CHAR_CPTR;
typedef const JUB_BYTE JUB_PTR      JUB_BYTE_CPTR;

typedef JUB_BYTE JUB_PTR            JUB_BYTE_PTR;
typedef JUB_UCHAR JUB_PTR           JUB_UCHAR_PTR;
typedef JUB_UTF8UCHAR JUB_PTR       JUB_UTF8UCHAR_PTR;
typedef JUB_ULONG JUB_PTR           JUB_ULONG_PTR;
typedef JUB_UINT64 JUB_PTR			JUB_UINT64_PTR;
typedef void JUB_PTR                JUB_VOID_PTR;

/* Pointer to a JUB_VOID_PTR-- i.e., pointer to pointer to void */
typedef JUB_VOID_PTR JUB_PTR JUB_VOID_PTR_PTR;

typedef JUB_ULONG JUB_RV;

#define MAX_DEVICE                  8

#define JUBR_OK                     0x00000000UL
#define JUBR_ERROR                  0x00000001UL
#define JUBR_HOST_MEMORY            0x00000002UL
#define JUBR_ARGUMENTS_BAD          0x00000003UL
#define JUBR_IMPL_NOT_SUPPORT		0x00000004UL
#define JUBR_MEMORY_NULL_PTR		0x00000005UL
#define JUBR_DATABASE_ERROR			0x00000006UL
#define JUBR_DATABASE_EMPTY			0x00000007UL
#define JUBR_INVALID_MEMORY_PTR		0x00000008UL
#define JUBR_REPEAT_MEMORY_PTR		0x00000009UL
#define JUBR_BUFFER_TOO_SMALL		0x0000000AUL

#define JUBR_COIN_TYPE_ALREADY_EXIST 0x00000010UL
#define JUBR_COIN_TYPE_NOT_EXIST	0x00000011UL
#define JUBR_ADD_COIN_TYPE_ERROR	0x00000012UL
#define JUBR_UNKNOWN_COIN_TYPE	    0x00000013UL


#define JUBR_WALLET_ALREADY_EXIST	0x00000020UL
#define JUBR_CREATE_WALLET_ERROR	0x00000021UL
#define JUBR_WALLET_NOT_EXIST    	0x00000022UL
#define JUBR_WALLET_LOADED    		0x00000023UL
#define JUBR_WALLET_NOT_LOAD		0x00000024UL
#define JUBR_WALLETS_EMPTY          0x00000025UL

#define JUBR_INVALID_BIP_PATH		0x00000030UL
#define JUBR_INVALID_MNEMONIC		0x00000031UL
#define JUBR_INVALID_ADDRESS		0x00000032UL
#define JUBR_INSUFFICIENT_COINS		0x00000033UL
#define JUBR_TOO_MANY_INPUTS		0x00000034UL
#define JUBR_NOT_SUPPORT_INPUTS		0x00000035UL
#define JUBR_INVAIDE_TRANSACTION	0x00000036UL
#define JUBR_NO_REDEEMSCRIPT		0x00000037UL

#define JUBR_VERIFY_PIN_ERROR		0x00000040UL
#define JUBR_CHANGE_PIN_ERROR		0x00000041UL
#define JUBR_PIN_NOT_SET			0x00000042UL

#define JUBR_INIT_DEVICE_LIB_ERROR	0x00000060UL
#define JUBR_CONNECT_DEVICE_ERROR	0x00000061UL
#define JUBR_TRANSMIT_DEVICE_ERROR	0x00000062UL
#define JUBR_NOT_CONNECT_DEVICE	    0x00000063UL

#define JUBR_ACCT_SYNC_DATA_FINISH  0x00000070UL

#define JUBR_CUSTOM_DEFINED         0x80000000UL

#ifdef __cplusplus
extern "C" {
#endif
enum JUB_ENUM_BOOL
{
    BOOL_FALSE = 0,
    BOOL_TRUE,
    BOOL_NR_ITEMS
};


enum JUB_BTC_TRANS_TYPE
{
	p2pkh = 0,
	//p2pwpkh,
	p2sh_p2wpkh
	/*
	p2sh_multisig,
	p2wsh_multisig,
	p2sh_p2wsh_multisig,
	*/
};
struct CONTEXT_CONFIG_BTC {
	JUB_CHAR_PTR		main_path;
	JUB_UINT16			forkID;
	JUB_BTC_TRANS_TYPE	type;
};

struct INPUT_BTC
{
	JUB_CHAR_PTR	preHash;
	JUB_UINT16      preIndex;
	JUB_UINT64		amount;
	JUB_UINT16		addressIndex;
};

struct OUTPUT_BTC
{
	JUB_CHAR_PTR	address;
	JUB_UINT64		amount;
	JUB_BBOOL		change;
	JUB_CHAR_PTR	path;
};


/*****************************************************************************
* @function name : Jub_ListDeviceHid
* @in param : 
* @out param : deviceIDs device list
* @last change : 
*****************************************************************************/
JUB_COINCORE_DLL_EXPORT
JUB_RV Jub_ListDeviceHid(OUT JUB_UINT16 deviceIDs[MAX_DEVICE]);


/*****************************************************************************
* @function name : Jub_ConnetDeviceHid
* @in param : 
* @out param : 
* @last change : 
*****************************************************************************/
JUB_COINCORE_DLL_EXPORT
JUB_RV Jub_ConnetDeviceHid(IN JUB_UINT16 deviceID);


/*****************************************************************************
* @function name : Jub_DisconnetDeviceHid
* @in param : 
* @out param : 
* @last change : 
*****************************************************************************/
JUB_COINCORE_DLL_EXPORT
JUB_RV Jub_DisconnetDeviceHid(IN JUB_UINT16 deviceID);


/*****************************************************************************
* @function name : Jub_DisconnetDeviceHid
* @in param :
* @out param :
* @last change :
*****************************************************************************/
JUB_COINCORE_DLL_EXPORT
JUB_RV Jub_CreateContextBTC(IN CONTEXT_CONFIG_BTC cfg , IN JUB_UINT16 deviceID,  OUT JUB_UINT16* contextID);


/*****************************************************************************
* @function name : JUB_ClearContext
* @in param : 
* @out param : 
* @last change : 
*****************************************************************************/
JUB_COINCORE_DLL_EXPORT
JUB_RV JUB_ClearContext(IN JUB_UINT16 contextID);


/*****************************************************************************
* @function name : JUB_SignTransactionBTC
* @in param : 
* @out param : 
* @last change : 
*****************************************************************************/
JUB_COINCORE_DLL_EXPORT
JUB_RV JUB_SignTransactionBTC(IN JUB_UINT16 contextID ,IN INPUT_BTC inputs[], IN JUB_UINT16 iCount, IN OUTPUT_BTC outputs[],  IN JUB_UINT16 oCount, IN JUB_UINT32 locktime, OUT JUB_CHAR_PTR_PTR raw);

#ifdef __cplusplus
}
#endif
#endif /* JUB_CORE_H */
