// MidBoss.h
/* 우선 Monster class 상속 필요
* 
#pragma once
#include "Monster.h"
#include "MidBossData.h"
#include <map>

class MidBoss : public Monster //MidBoss는 Monster 상속
{
private:
    int m_dropItemId; // CashableItems 대체 (ID로 관리)

    static std::map<int, MidBossData> midBossTable;

public:
    MidBoss(int id);

    void Attack() override;
    void GetHit(int damage) override;
};

*/
