#include "FinalBoss.h"
#include "UIManager.h"
#include <iostream>
#include <random>

using namespace std;

// FinalBoss 생성자
// Monster 생성자에 직접 값 전달
FinalBoss::FinalBoss()
    : Monster(
        "강창민 튜터",  // [1] 이름 (스토리상 최종 보스)
        25,            // [2] 레벨 (MidBoss 최대가 20이므로 그보다 높게 설정)
        3000,          // [3] 드랍 골드 (최종 보스 보상)
        2000           // [4] 드랍 경험치
    )
{

    // ===== 최종 보스 스탯 강화 =====

    static random_device rd;
    static mt19937 gen(rd());

   
    uniform_real_distribution<float> hpRatioDist(2.0f, 2.3f); // 체력: 1.5 ~ 2.0 배
  
    uniform_real_distribution<float> atkRatioDist(1.5f, 1.8f); // 공격력: 1.5 ~ 1.8 배

    float hpRatio = hpRatioDist(gen);
    float atkRatio = atkRatioDist(gen);

    m_MaxHP = static_cast<int>(m_MaxHP * hpRatio);
    m_HP = m_MaxHP; // 체력은 최대치로 초기화
    m_ATK = static_cast<int>(m_ATK * atkRatio);
    // ===== 최종 보스 스탯 강화 완료 =====

}

// FinalBoss 공격
void FinalBoss::attack(Character* player, UIManager* ui)
{
    // [6] 최종 보스 전용 공격 메시지
    cout << Color::BRIGHT_CYAN << "강창민 튜터님의 압도적인 C++ 전체 복습 공격!" << Color::RESET << endl;

    // [7] 실제 데미지 계산은 Monster에게 위임
    Monster::attack(player, ui);
}

// FinalBoss 피격 처리
void FinalBoss::GetHit(int damage, UIManager* ui)
{
    // [8] 최종 보스 전용 피격 연출
    cout << Color::BRIGHT_CYAN <<"강창민 튜터님은 아직 쓰러지지 않았다!" << Color::RESET << endl;

    // [9] HP 감소 및 사망 판정은 Monster 로직 사용
    Monster::GetHit(damage, ui);

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
