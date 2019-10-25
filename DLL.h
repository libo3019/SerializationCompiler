#ifndef __DLL_h__
#define __DLL_h__

#ifndef WIN32
#define WIN32
#endif

#ifdef WIN32
#define DLL_EXPORT _declspec(dllexport)
#define DLL_IMPORT _declspec(dllexport)

#ifdef IMPORT_DLL
#define DLL_EXPORT_IMPORT DLL_IMPORT
#else
#define DLL_EXPORT_IMPORT DLL_EXPORT
#endif	

#else //linux
#define DLL_EXPORT
#define DLL_IMPORT

#ifdef IMPORT_DLL
#define DLL_EXPORT_IMPORT DLL_IMPORT
#else
#define DLL_EXPORT_IMPORT DLL_EXPORT
#endif	

#endif

#endif //DLL_h__