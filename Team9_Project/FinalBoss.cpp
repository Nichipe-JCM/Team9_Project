#include "FinalBoss.h"
#include <iostream>
#include <random>

using namespace std;

// FinalBoss 생성자
// Monster 생성자에 직접 값 전달
FinalBoss::FinalBoss()
    : Monster(
        "강창민 튜터님",  // [1] 이름 (스토리상 최종 보스)
        25,            // [2] 레벨 (MidBoss 최대가 20이므로 그보다 높게 설정)
        3000,          // [3] 드랍 골드 (최종 보스 보상)
        2000           // [4] 드랍 경험치
    )
{

    // ===== 최종 보스 스탯 강화 =====

    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<float> ratioDist(1.5f, 2.0f);  // 기존 몬스터 스탯의 1.5 ~ 2.0배

    float hpRatio = ratioDist(gen);
    float atkRatio = ratioDist(gen);

    m_MaxHP = static_cast<int>(m_MaxHP * hpRatio);
    m_HP = m_MaxHP;
    m_ATK = static_cast<int>(m_ATK * atkRatio);
    // ===== 최종 보스 스탯 강화 완료 =====
     
    // [5] 최종 보스 등장 연출
    cout << "===================================" << endl;
    cout << " [FINAL BOSS] 강창민 튜터님 등장!" << endl;
    cout << "===================================" << endl;
}

// FinalBoss 공격
void FinalBoss::attack(Character* player)
{
    // [6] 최종 보스 전용 공격 메시지
    cout << "강창민 튜터님의 압도적인 C++ 전체 복습 공격!" << endl;

    // [7] 실제 데미지 계산은 Monster에게 위임
    Monster::attack(player);
}

// FinalBoss 피격 처리
void FinalBoss::GetHit(int damage)
{
    // [8] 최종 보스 전용 피격 연출
    cout << "강창민 튜터님은 아직 쓰러지지 않았다!" << endl;

    // [9] HP 감소 및 사망 판정은 Monster 로직 사용
    Monster::GetHit(damage);

    // [10] 체력이 0이 되었을 때 최종 메시지 출력
    if (m_HP <= 0)
    {
        cout << endl;
        cout << "===================================" << endl;
        cout << " [FINAL BOSS DEFEATED]" << endl;
        cout << " 강창민 튜터님을 쓰러뜨렸다!" << endl;
        cout << "===================================" << endl;
    }
}
