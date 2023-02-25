#pragma once
#include <Windows.h>
#include "Mem.h"
#define ValidPointer( pointer ) ( pointer != NULL && (DWORD_PTR)pointer >= 0x10000 && (DWORD_PTR)pointer < 0x00007FFFFFFEFFFF /*&& some other checks*/ )
class Mem
{
public:
	Mem(HANDLE h)
	{
		pHandle = h;
	}
	template<typename T>
	T ReadMem(uintptr_t addr)
	{
		T buffer;
		SIZE_T buff{};
		ReadProcessMemory(Mem::pHandle, (void*)addr, &buffer, sizeof(T), &buff);
		return buffer;
	}

	template<typename T>
	void readbuff(uintptr_t addr, T buffer[], int size)
	{
		ReadProcessMemory(Mem::pHandle, (void*)addr, buffer, size, NULL);
	}

	char* ReadMemStr(uintptr_t addr, int length)
	{
		char* buffer = new char[length];
		SIZE_T buff{};
		ReadProcessMemory(Mem::pHandle, (void*)addr, buffer, length, &buff);
		return buffer;
	}

	template<typename T>
	bool WriteMem(uintptr_t addr, T buff)
	{
		SIZE_T temp;
		return WriteProcessMemory(Mem::pHandle, (LPVOID)addr, &buff, sizeof(T), &temp);
	}

	void writeShell(uintptr_t addr, BYTE* data) {
		DWORD oldprotect;
		VirtualProtectEx(Mem::pHandle, (LPVOID)addr, 1, PAGE_EXECUTE_READWRITE, &oldprotect);

		WriteProcessMemory(Mem::pHandle, (LPVOID)addr, data, 1, 0);

		VirtualProtectEx(Mem::pHandle, (LPVOID)addr, 1, oldprotect, &oldprotect);

		/*BYTE readData[8];
		ReadProcessMemory(hProc, (void*)0x141ae0151, readData, 8, 0);

		for (int i = 0; i < 10; ++i)
			printf("%02x ", data[i]);
		std::cout << std::endl;*/
	}


private:
	HANDLE pHandle;

};

