// MidBoss.cpp
/* 우선 Monster class 상속 필요
#include "MidBoss.h"
#include <iostream>

using namespace std;

// 🔹 미드보스 데이터 테이블
map<int, MidBossData> MidBoss::midBossTable =
{
    { 1, { "김조은 튜터", 300, 50, 100, 200 } },
    { 2, { "김극민", 500, 100, 300, 500 } },
    { 3, { "김봉재", 800, 150, 600, 900 } },
    { 4, { "손승현", 1200, 200, 1000, 1500 } }
};

MidBoss::MidBoss(int id)
    : Monster(
        midBossTable.at(id).name,
        midBossTable.at(id).hp,
        midBossTable.at(id).atk,
        midBossTable.at(id).dropGold,
        midBossTable.at(id).dropExp
    ),
    //dropItemId(id) //Drop 아이템은 아이템 class 상속 예정
{
    cout << "[MID BOSS] " << name << " 등장!" << endl;
}

void MidBoss::Attack()
{
    cout << "[MID BOSS] " << name << "의 공격!" << endl;
}

void MidBoss::GetHit(int damage)
{
    cout << "[MID BOSS] " << name << "는 쉽게 쓰러지지 않는다!" << endl;
    Monster::GetHit(damage);
}
*/