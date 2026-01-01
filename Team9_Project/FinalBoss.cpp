#include "FinalBoss.h"
#include <iostream>

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
