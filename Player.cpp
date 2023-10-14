#include "Player.h"
#include <iostream>
#include <string>


#define Long unsigned long long
#define OFFSET_OBFUSCATIONMGR 0x14351D058
#define OFFSET_CLIENTGAMECONTEXT 0x1437F7758

typedef struct D3DXVECTOR3 {
	FLOAT x;
	FLOAT y;
	FLOAT z;
} D3DXVECTOR3, * LPD3DXVECTOR3;

class Enemy {
public:
	Enemy(D3DXVECTOR3 location, float health, char* name) {
		locationX = location.x;
		locationY = location.y;
		this->health = health;
		this->name = name;
	}

	Enemy() {
		locationX = 0.0;
		locationY = 0.0;
		this->health = 0.0;
		this->name = nullptr;
	};

	void print() {
		std::cout << ((std::string)name).substr(0, 6);
		std::cout << "\t" << locationX << "\t";
		std::cout << locationY << " ";
		std::cout << "\n";
	}

private:
	float locationX, locationY, health;
	char* name;
};

std::vector<Player::PlayerInfo*> Player::GetPlayerInVehicle()
{
	int myTeamId = 1;
	int playerIdx = 0;
	float myLocationX = 0.0;
	float myLocationY = 0.0;
	std::vector<Enemy*> enemies;
		
	std::vector<PlayerInfo*>retValue;
	for (int i = 0; i < 70; i++)
	{
		PlayerInfo* p = GetPlayerById(i);
		if (!ValidPointer(p))
			continue;
		//try to read whole player/clientPlayer data at once
		if (((std::string)p->PlayerName).find("lKod") != std::string::npos) {
			uint64_t clientSoldierEntity = mem->ReadMem<Long>(p->ClientPlayer + 0x1D48);
			uint8_t position = mem->ReadMem<uint8_t>(clientSoldierEntity + 0x0638);
			uint64_t HealthComponent = mem->ReadMem<Long>(clientSoldierEntity + 0x1D0);
			D3DXVECTOR3 loc = mem->ReadMem<D3DXVECTOR3>(clientSoldierEntity + 0x0990);
			float health = (float)mem->ReadMem<float>(HealthComponent + 0x0020);

			myTeamId = mem->ReadMem<BYTE>(p->ClientPlayer + 0x1C34);

			myLocationX = (float)loc.x;
			myLocationY = (float)loc.z;
			/*if (health > 0.1) {
				std::cout << p->PlayerName << " " << myTeamId;
				std::cout << " " << myLocationX << " ";
				std::cout << " " << myLocationY << " ";
				std::cout << " " << unsigned(position) << " ";
				if (p->isInVehicle)
					std::cout << " " << p->VehicleID << " ";
				std::cout << " health: ";
				std::cout << health << std::endl;
			}*/


			retValue.push_back(p);
		}
		
		delete[] p->PlayerName;
		delete p;
	}// end for loop

	system("cls");

	for (int i = 0; i < 70; i++)
	{
		PlayerInfo* p = GetPlayerById(i);
		if (!ValidPointer(p))
			continue;
			
		int playerTeamId = mem->ReadMem<BYTE>(p->ClientPlayer + 0x1C34);		

		if (playerTeamId != myTeamId) {
			uint64_t clientSoldierEntity = mem->ReadMem<Long>(p->ClientPlayer + 0x1D48);
			uint64_t HealthComponent = mem->ReadMem<Long>(clientSoldierEntity + 0x1D0);
			uint64_t vehEntityData = mem->ReadMem<Long>(p->ClientVehicleEntity + 0x30);

			//D3DXVECTOR3 location = mem->ReadMem<D3DXVECTOR3>(clientSoldierEntity + 0x0990);
			float health = (float)mem->ReadMem<float>(HealthComponent + 0x0020);
			//float distance = sqrt(pow(myLocationX - location.x, 2) + pow(myLocationY - location.z, 2));
			
			//std::cout << p->PlayerName << std::endl;
			if(p->isInVehicle ){
			//if ( (((std::string)p->PlayerName).find("JaxWax") != std::string::npos)) {
			
			//if(strcmp(p->PlayerName, "AlenDelonRU\0")==0){
			
			//if (((uint8_t)mem->ReadMem<uint8_t>(clientSoldierEntity + 0x324) == 0xf1) || (((std::string)p->PlayerName).find("reael") != std::string::npos)) {
				//std::cout << playerIdx++ << " ";//<< playerTeamId << " ";

				std::cout << std::endl;
				std::cout << ((std::string)p->PlayerName) << std::endl;	
				//std::cout << std::hex << clientSoldierEntity << "\n";
				uint8_t buf[2 * 1024];
				mem->readbuff(p->ClientVehicleEntity, buf, 2*1024);
				unsigned long long vname = mem->ReadMem<unsigned long long>(vehEntityData + 0x02f8);
				char* vnamestring = mem->ReadMemStr(vname, 44);

				/*if (((std::string)vnamestring).find("HORSE") != std::string::npos) {
					continue;
				}*/

				
					uint64_t vehHpComp = mem->ReadMem<Long>(p->ClientVehicleEntity + 0x1d0);


					float vehHp = (float)mem->ReadMem<float>(vehHpComp + 0x0040);
					std::cout << "vehicle hp: " << vehHp << std::endl;
					std::cout << std::hex << vnamestring << std::endl;

					//set vehicle outline
					BYTE x[] = { 0xf1 };
					mem->writeShell(p->ClientVehicleEntity + 0x50d, x);
				

				for (int i = 0; i < 2 * 1024; i++) {
				/*	if (i == 0x50d) {
						std::cout << std::endl;
					}
					std::cout << std::hex << static_cast<int>(buf[i]) << ",";
					if (i == 0x50d) {
						std::cout << std::endl;
					}*/

					/*if (i % 32 == 0) {
						std::cout << std::endl;
						std::cout << std::dec << unsigned(i) << ".\t";
					}*/
				}
				std::cout << std::endl;
				



			}

			if (health > 0.1f ) {
				//if(playerTeamId == myTeamId) {
				//	std::cout << "\t\t\t";
				//}
				

				
				//show enemy outlines
				if (true) {
					BYTE x[] = { 0xf1 };
					mem->writeShell(clientSoldierEntity + 0x324, x);
				}
				else {
					BYTE x[] = { 0 };
					mem->writeShell(clientSoldierEntity + 0x324, x);
				}




				//for (int i = 0; i < sizeof(data); i++) {
				//	//printf("%x02,", (BYTE)*((uint64_t*)clientSoldierEntity+i));
				//	//std::cout << std::hex << (uint8_t) data[i];
				//	printf("%x.%x ",i, data[i]);
				//	if (i % 30 == 30)
				//		printf("\n");
				//}
				//std::cout << "\t";//<< (float)location.x << "\t";
				//std::cout << location.z << " ";
				//std::cout << distance;
				/*std::cout << "\n";*/
			}
		}

		delete[] p->PlayerName;
		delete p;
	}// end for loop

	return retValue;
}

	
/// <summary>
/// 获得全部玩家
/// </summary>
/// <param name="id"></param>
/// <returns>记得Free返回值</returns>
Player::PlayerInfo* Player::GetPlayerById(int id)
{

	PlayerInfo* info = new PlayerInfo;
	info->ClientPlayer = GetClientPlayerById(id);
	if (!ValidPointer(info->ClientPlayer))
	{
		delete info;
		return nullptr;
	}

	info->PlayerName = mem->ReadMemStr(mem->ReadMem<Long>(info->ClientPlayer + OFFSET_PlayerName), 40);
	
	/*
	std::string name = info->PlayerName;

	if (name.find("lKod") != std::string::npos) {
		for(int i = 0; i < 38; i++)
			printf("%c", info->PlayerName[i]);
		std::cout<<std::endl;
		std::cout << (std::string)info->PlayerName << " ";

		std::cout << std::hex << info->ClientPlayer << std::endl;

		std::cout << std::hex << info->ClientPlayer + OFFSET_PlayerName << std::endl;
	}*/

	Long tempVehicleEntity = mem->ReadMem<Long>(info->ClientPlayer + OFFSET_ClientVehicleEntity);
	if (ValidPointer(tempVehicleEntity))
	{
		info->ClientVehicleEntity = tempVehicleEntity;
		info->isInVehicle = true;

		Long tempVehicleEntityData = mem->ReadMem<Long>(info->ClientVehicleEntity + OFFSET_VehicleEntityData);
		if (ValidPointer(tempVehicleEntityData))
		{
			Long tempVeniceVehicleCustomizationAsset = mem->ReadMem<Long>(tempVehicleEntityData + OFFSET_VeniceVehicleCustomizationAsset);
			if (ValidPointer(tempVeniceVehicleCustomizationAsset))
			{
				info->VehicleID = mem->ReadMemStr(mem->ReadMem<Long>(tempVeniceVehicleCustomizationAsset + OFFSET_VehicleID), 100);
				if (ValidPointer(info->VehicleID))
				{
					return info;
				}
			}

		}
	}

	info->isInVehicle = false;

	return info;
}


Long Player::GetClientPlayerById(int id)
{
	Long pClientGameContext = mem->ReadMem<Long>(OFFSET_CLIENTGAMECONTEXT);
	if (!ValidPointer(pClientGameContext))
	{
		return 0;
	}

	Long pPlayerManager = mem->ReadMem<Long>(pClientGameContext + 0x68);
	if (!ValidPointer(pPlayerManager))
	{
		return 0;
	}

	Long pObfuscationMgr = mem->ReadMem<Long>(OFFSET_OBFUSCATIONMGR);
	if (!ValidPointer(pObfuscationMgr))
	{
		return 0;
	}

	Long PlayerListXorValue = mem->ReadMem<Long>(pPlayerManager + 0xF8);
	Long PlayerListKey = PlayerListXorValue ^ mem->ReadMem<Long>(pObfuscationMgr + 0x70);

	Long mpBucketArray = mem->ReadMem<Long>(pObfuscationMgr + 0x10);


	int mnBucketCount = mem->ReadMem<int>(pObfuscationMgr + 0x18);
	if (mnBucketCount == 0)
	{
		return 0;
	}

	int startCount = (int)PlayerListKey % mnBucketCount;

	Long mpBucketArray_startCount = mem->ReadMem<Long>(mpBucketArray + (Long)(startCount * 8));
	Long node_first = mem->ReadMem<Long>(mpBucketArray_startCount);
	Long node_second = mem->ReadMem<Long>(mpBucketArray_startCount + 0x8);
	Long node_mpNext = mem->ReadMem<Long>(mpBucketArray_startCount + 0x10);

	while (PlayerListKey != node_first)
	{
		mpBucketArray_startCount = node_mpNext;

		node_first = mem->ReadMem<Long>(mpBucketArray_startCount);
		node_second = mem->ReadMem<Long>(mpBucketArray_startCount + 0x8);
		node_mpNext = mem->ReadMem<Long>(mpBucketArray_startCount + 0x10);
	}

	Long EncryptedPlayerMgr = node_second;
	return EncryptedPlayerMgr_GetPlayer(EncryptedPlayerMgr, id);

}
Long Player::EncryptedPlayerMgr_GetPlayer(Long ptr, int id)
{
	Long XorValue1 = mem->ReadMem<Long>(ptr + 0x20) ^ mem->ReadMem<Long>(ptr + 0x8);
	Long XorValue2 = XorValue1 ^ mem->ReadMem<Long>(ptr + 0x10);
	if (!ValidPointer(XorValue2))
	{
		return 0;
	}

	return XorValue1 ^ mem->ReadMem<Long>(XorValue2 + 0x8 * id);
}
