#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <tchar.h>
#include <string>
#include "sddl.h"

#include "../OS15_HTCOM_LIB/pch.h"
#include "../OS15_HTCOM_LIB/OS15_HTCOM_LIB.h"

#define SERVICENAME L"OS15_HTService"
#define HTPATH L"C:/storage/HTspace.ht"

#define USERNAME L"HTUser01"
#define PASSWORD L"1337"

#define TRACEPATH L"C:/storage/service.trace"

VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);
VOID WINAPI ServiceHandler(DWORD fdwControl);

SECURITY_ATTRIBUTES getSecurityAttributes();
HANDLE createStopEvent(const wchar_t* stopEventName);
void startService();
void trace(const char* msg, int r = std::ofstream::app);
