#include "AchievementManager.h"
#include "Character.h"
#include "StatusManager.h"
#include "Utils.h"
#include <iostream>
AchievementManager::AchievementManager() {
    Init();
}
AchievementManager::~AchievementManager() {}
void AchievementManager::Init() {
    // m_Achievements["업적 이름"] = false; 양식으로 추가
    m_Achievements["첫걸음"] = false;
    m_Achievements["레벨10달성"] = false;
    m_Achievements["이제나도부자"] = false;
    m_Achievements["진짜개발자"] = false;
    m_Achievements["내배캠지배자"] = false;
}
void AchievementManager::UpdateAchievements(Character* player, StatusManager* sm) {
    //if (!m_Achievements["업적 이름"] && 업적 조건) {} 양식으로 작성
    if (!m_Achievements["첫걸음"] && player->getATK() >= 100) {
        m_Achievements["첫걸음"] = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] '첫걸음' - 코딩력 100 달성!" << endl;
        Utils::DrawLine();
        cout << endl;
    }
    if (!m_Achievements["레벨10달성"] && player->getLevel() >= 10) {
        m_Achievements["레벨10달성"] = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 레벨 10 달성!" << endl;
        Utils::DrawLine();
        cout << endl;
    }
    if (!m_Achievements["이제나도부자"] && player->getGold() >= 1000) {
        m_Achievements["이제나도부자"] = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 1000 Zep 수집!" << endl;
        Utils::DrawLine();
        cout << endl;
    }
    if (!m_Achievements["진짜개발자"]
        && player->getATK() >= 300
        && player->getHP() >= 400
        && player->getGold() >= 500) {
        m_Achievements["진짜개발자"] = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] '진짜 개발자' - 코딩력, 체력, Zep 모두 증명!" << endl;
        Utils::DrawLine();
        cout << endl;
    }
    if (!m_Achievements["내배캠지배자"] && sm->m_KillCounts["강창민 튜터님"] >= 1) {
        m_Achievements["내배캠지배자"] = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 강창민 튜터님 격파!" << endl;
        Utils::DrawLine();
        cout << endl;
    }
}