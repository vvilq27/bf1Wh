#include "Mem.h"
#include "Player.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include "globals.h"

char* FuncVehicleId(char* id)
{
	//eg: Gameplay/Vehicles/RU_PutilovGarford/RU_PutilovGarford/...
	char* s;
	char* retV;
	strtok_s(id, "/", &s);
	strtok_s(NULL, "/", &s);
	retV = strtok_s(NULL, "/", &s);
	return retV;
}
Globals* globalVars;

int main()
{
	using namespace std;
	printf("[+] Start\n");
	HWND window = FindWindowW(nullptr, L"Battlefield™ 1");
	DWORD pid = 0;
	GetWindowThreadProcessId(window, &pid);
	printf("[+] pid:%d\n", pid);

	Globals* globalVars = new Globals();

	Mem* mem = new  Mem(OpenProcess(PROCESS_ALL_ACCESS, false, pid));
	Player* playersMan = new Player(mem);

	//system("cls");
	while (true) {
		vector<Player::PlayerInfo*> ps = playersMan->GetPlayerInVehicle();
		Sleep(50);
		system("cls");

		if (GetAsyncKeyState(VK_F3) & 0x80000)
			globalVars->enableCheats = 1;
		if (GetAsyncKeyState(VK_F4) & 0x80000)
			globalVars->enableCheats = 0;
		
	}
	

//		for (Player::PlayerInfo* p : ps)
//		{
//#pragma region CoreFunction
//			for (int i = 0; i < 40; i++)
//			{
//				uintptr_t tempMultiUnlockAsset = mem->ReadMem<uintptr_t>(p->ClientPlayer + i * 0x8 + 0x13D8);
//				if (!ValidPointer(tempMultiUnlockAsset))
//					continue;
//				else
//				{
//					uintptr_t vtable = mem->ReadMem<uintptr_t>(tempMultiUnlockAsset);
//					if (vtable == 0x142B8CFA8)
//					{
//						char* cmpVehicleName = mem->ReadMemStr(mem->ReadMem<uintptr_t>(tempMultiUnlockAsset + 0x10), 100);
//						cmpVehicleName = FuncVehicleId(cmpVehicleName);
//
//						if (string(p->VehicleID).find(cmpVehicleName) != string::npos)
//						{
//							p->VehicleName = mem->ReadMemStr(mem->ReadMem<uintptr_t>(tempMultiUnlockAsset + 0x20), 50);
//							break;
//						}
//					}
//				}
//			}
//#pragma endregion
//			if (ValidPointer(p->VehicleName))
//			{
//				/*cout << "\tPlayerName:" << endl;
//				cout << "\t\t" << p->PlayerName << endl;
//				cout << "\tVehicleName:" << endl;
//				cout << "\t\t" << p->VehicleName << endl;
//				printf("\n");*/
//				delete[] p->VehicleName;
//			}
//
//			delete[] p->PlayerName;
//			delete[] p->VehicleID;
//
//			delete p;
//		}

		Sleep(1 * 1000);
	

}
