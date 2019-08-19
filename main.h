#ifndef __MAIN_H__
#define __MAIN_H__

#include <winsock2.h>
#include <stdio.h>



#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

int DLL_EXPORT ReverShell(char* ip, int port);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
