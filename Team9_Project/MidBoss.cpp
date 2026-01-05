#include "MidBoss.h" // MidBoss 클래스 구현을 위해 헤더 포함

#include <iostream>

using namespace std;


// 미드보스 데이터 테이블 정의 // static 멤버 변수는 cpp 파일에서 반드시 한 번 정의해야 함
map<int, MidBossData> MidBoss::midBossTable =  // key : id (1~4) // value : 해당 id에 대응하는 미드보스 정보
//  미드보스 데이터 테이블
{
    { 1, { "김조은 튜터",  5,  200, 75 } },   // Stage 5
    { 2, { "김극민 튜터",     10,  300, 100 } },   // Stage 10
    { 3, { "김봉재 튜터",     15,  600, 150 } },   // Stage 15
    { 4, { "손승현 튜터",     20, 1000, 175 } }   // Stage 20
};


// MidBoss 생성자
MidBoss::MidBoss(int id)  // id 값에 따라 midBossTable에서 데이터를 가져와 // Monster 생성자에 전달
    : Monster(
        midBossTable.at(id).name,      // 몬스터 이름
        midBossTable.at(id).level,     // 몬스터 레벨
        midBossTable.at(id).dropGold,  // 드랍 골드
        midBossTable.at(id).dropExp    // 드랍 경험치
    )
{

    cout << "이제 일반 몬스터는 상대도 안 된다.." << endl; // 미드보스 등장 연출
    cout << "[MID BOSS] " << name << " 등장!" << endl; // 미드보스 등장 연출
}




void MidBoss::attack(Character* player) // 미드보스 공격 // Monster의 기본 공격에 미드보스 전용 메시지를 오버라이드
{
    cout << "[MID BOSS] " << name << "의 과제 공격!" << endl;

    // 실제 공격 로직은 부모 클래스에게 맡김
    Monster::attack(player);
}



void MidBoss::GetHit(int damage) // 미드보스 피격 시 전용 메시지를 출력한 뒤 // 실제 데미지 계산은 Monster에게 위임
{
    cout << "[MID BOSS] " << name << "는 쉽게 쓰러지지 않는다!" << endl;

    Monster::GetHit(damage);
}

/*bool MidBoss::checkDeath()
{
    // 부모의 사망 처리 먼저 실행
    if (Monster::checkDeath())
    {
        cout << "[MID BOSS] " << name << " 격파!" << endl;
        cout << "강력한 기운이 사라진다..." << endl;

        // 튜터 처치 카운트 증가
        StatusManager::GetInstance()->AddKill("튜터");

        return true;
    }
}
*/
