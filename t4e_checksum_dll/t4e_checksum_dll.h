// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the T4E_CHECKSUM_DLL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// T4E_CHECKSUM_DLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef T4E_CHECKSUM_DLL_EXPORTS
#define T4E_CHECKSUM_DLL_API __declspec(dllexport)
#else
#define T4E_CHECKSUM_DLL_API __declspec(dllimport)
#endif

extern "C"
{
	T4E_CHECKSUM_DLL_API __int32 t4e_cal_chksum(BYTE *data, UINT16 offset, UINT16 size);
}
