#pragma once
#include "Monster.h"
#include <string>

// FinalBoss 클래스
// - 게임에서 단 1번 등장하는 최종 보스
// - Stage 21에서만 출현
class FinalBoss : public Monster
{
public:
    // 기본 생성자
    // GameManager에서 new FinalBoss() 형태로 생성되기 때문에
    // 반드시 인자를 받지 않는 생성자가 필요함
    FinalBoss();

    // 최종 보스 전용 공격 연출
    void attack(Character* player) override;

    // 최종 보스 전용 피격 연출
    void GetHit(int damage) override;
};
