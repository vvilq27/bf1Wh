#include "Mem.h"
#include "Player.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#include <stdio.h>


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
int enChts;

int main()
{
	using namespace std;
	printf("[+] Start\n");
	HWND window = FindWindowW(nullptr, L"Battlefield™ 1");
	DWORD pid = 0;
	GetWindowThreadProcessId(window, &pid);
	printf("[+] pid:%d\n", pid);

	Mem* mem = new  Mem(OpenProcess(PROCESS_ALL_ACCESS, false, pid));
	Player* playersMan = new Player(mem);

	//system("cls");
	while (true) {
		vector<Player::PlayerInfo*> ps = playersMan->GetPlayerInVehicle();
		Sleep(330);

		if (GetAsyncKeyState(VK_F3) & 0x80000) {
			enChts = 1;
			printf("cheats enabled");
		}
			
		if (GetAsyncKeyState(VK_F4) & 0x80000) {
			printf("cheats disabled");
			enChts = 0;
		}
			
	}
}
