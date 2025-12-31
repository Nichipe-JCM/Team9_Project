#pragma once

#include "Monster.h" // MidBoss는 Monster를 상속받기 때문에 부모 클래스 포함

#include <map>
#include <string>  // midBossTable(map)과 이름(string)을 사용하기 위해 포함


// 미드보스 데이터 구조체
// 미드보스마다 다른 고정 데이터를 묶어서 관리하기 위한 구조체
struct MidBossData
{
    string name; // 미드보스 이름
    int level;        // 미드보스 레벨 (Monster 생성자에서 HP/ATK 계산에 사용)
    int dropGold;     // 처치 시 획득 골드
    int dropExp;      // 처치 시 획득 경험치
};


// MidBoss 클래스 선언
class MidBoss : public Monster // Monster 클래스를 상속받아 미드보스 전용 몬스터를 구현
{
private:     // 모든 MidBoss가 공유하는 데이터 테이블/  key : id (1~4) / value : 해당 미드보스의 고정 데이터
    static map<int, MidBossData> midBossTable;

public:
    MidBoss(int id); // 생성자 // id : GameManager에서 stage / 5 로 계산된 값 (1~4) //id에 따라 다른 미드보스가 생성됨

 
    void attack(Player* player) override;  // Monster의 attack 함수를 오버라이드 // 미드보스 전용 공격 메시지 출력

  
    void GetHit(int damage) override; // Monster의 GetHit 함수를 오버라이드 // 미드보스만의 피격 연출 메세지 출력
};
