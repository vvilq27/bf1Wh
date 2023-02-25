#pragma once
#include <cstdint>

//class ClientSoldierEntity
//{
//public:
//    char pad_0000[464]; //0x0000
//    HealthComponent* healthcomponent; //0x01D0
//    char pad_01D8[696]; //0x01D8
//    BoneCollisionComponent* bonecollisioncomponent; //0x0490
//    char pad_0498[363]; //0x0498
//    uint8_t N00000670; //0x0603
//    float authorativeYaw; //0x0604
//    char pad_0608[41]; //0x0608
//    uint8_t N00000521; //0x0631
//    char pad_0632[6]; //0x0632
//    uint8_t poseType; //0x0638
//    char pad_0639[176]; //0x0639
//    uint8_t N00000538; //0x06E9
//    uint8_t N0000022B; //0x06EA
//    uint8_t occluded; //0x06EB
//    char pad_06EC[669]; //0x06EC
//    uint8_t N0000058C; //0x0989
//    char pad_098A[6]; //0x098A
//    D3DXVECTOR3 location; //0x0990
//    char pad_099C[1712]; //0x099C
//    ClientSoldierWeaponsComponent* GETsoldierWeaponsComponent()
//    {
//        return *(ClientSoldierWeaponsComponent**)((BYTE*)this + 0x698);
//    };
//    bool IsValid()
//    {
//        return (this->healthcomponent->m_Health > 0.1f && this->healthcomponent->m_Health <= this->healthcomponent->m_MaxHealth);
//    }
//    bool IsDead()
//    {
//        return !(this->healthcomponent->m_Health > 0.1f);
//    }
//    bool IsVisible()
//    {
//        return (this->occluded == false);
//    }
//    AxisAlignedBox GetAABB()
//    {
//        AxisAlignedBox aabb = AxisAlignedBox();
//        if (this->poseType == 0) // standing
//        {
//            aabb.Min = D3DXVECTOR4(-0.350000f, 0.000000f, -0.350000f, 0);
//            aabb.Max = D3DXVECTOR4(0.350000f, 1.700000f, 0.350000f, 0);
//        }
//        if (this->poseType == 1) // crouching
//        {
//            aabb.Min = D3DXVECTOR4(-0.350000f, 0.000000f, -0.350000f, 0);
//            aabb.Max = D3DXVECTOR4(0.350000f, 1.150000f, 0.350000f, 0);
//        }
//        if (this->poseType == 2) // prone
//        {
//            aabb.Min = D3DXVECTOR4(-0.350000f, 0.000000f, -0.350000f, 0);
//            aabb.Max = D3DXVECTOR4(0.350000f, 0.400000f, 0.350000f, 0);
//        }
//        return aabb;
//    }
//    bool GetBonePos(int BoneId, D3DXVECTOR3* vOut);
//
//
//}; //Size: 0x104C
//
//class ClientPlayer
//{
//public:
//    virtual ~ClientPlayer();
//    virtual DWORD_PTR GetCharacterEntity(); //=> ClientSoldierEntity + 0x268 
//    virtual DWORD_PTR GetCharacterUserData(); //=> PlayerCharacterUserData
//    virtual class EntryComponent* GetEntryComponent();
//    virtual bool InVehicle();
//    virtual unsigned int getId();
//    char _0x0008[16];
//    char* name; //0x0018
//    char pad_0020[32]; //0x0020
//    char szName[8]; //0x0040
//    char pad_0048[7144]; //0x0048
//    uint8_t N00000393; //0x1C30
//    uint8_t N0000042C; //0x1C31
//    char pad_1C32[2]; //0x1C32
//    uint8_t teamId; //0x1C34
//    char pad_1C35[259]; //0x1C35
//    ClientVehicleEntity* clientVehicleEntity; //0x1D38
//    char pad_1D40[8]; //0x1D40
//    ClientSoldierEntity* clientSoldierEntity; //0x1D48
//    char pad_1D50[736]; //0x1D50
//};
//
//class ClientVehicleEntity
//{
//public:
//    virtual void Function0(); //
//    virtual void Function1(); //
//    virtual void Function2(); //
//    virtual void Function3(); //
//    virtual void Function4(); //
//    virtual void Function5(); //
//    virtual void Function6(); //
//    virtual void Function7(); //
//    virtual void Function8(); //
//    virtual void Function9(); //
//    virtual void Function10(); //
//    virtual void Function11(); //
//    virtual void Function12(); //
//    virtual void Function13(); //
//    virtual void Function14(); //
//    virtual void Function15(); //
//    virtual void Function16(); //
//    virtual void Function17(); //
//    virtual void Function18(); //
//    virtual void Function19(); //
//    virtual void Function20(); //
//    virtual void Function21(); //
//    virtual void Function22(); //
//    virtual void Function23(); // 
//    virtual void Function24();
//    virtual void GetTransformAABB(LinearTransform_AABB& mTransform);// 26
//    HealthComponent* GetHealthComponent()
//    {
//        return *(HealthComponent**)((BYTE*)this + 0x1D0);
//    };
//
//    VehicleEntityData* GetEntityData()
//    {
//        return *(VehicleEntityData**)((BYTE*)this + 0x30);
//    };
//}; //Size: 0x0048