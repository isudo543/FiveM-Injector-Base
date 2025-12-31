#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <TlHelp32.h>

namespace Api {
	inline std::uintptr_t GetProcessByName(const char* name) {
		PROCESSENTRY32 entry{};
		entry.dwSize = sizeof(entry);

		HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (snap == INVALID_HANDLE_VALUE)
			return -1;

		if (Process32First(snap, &entry)) {
			do {
				char procname[MAX_PATH];
				wcstombs_s(nullptr, procname, entry.szExeFile, MAX_PATH);
				if (_stricmp(procname, name) == 0) {
					CloseHandle(snap);
					return entry.th32ProcessID;
				}
			} while (Process32Next(snap, &entry));
		}

		CloseHandle(snap);
		return 0;
	}
}