#include "AchievementManager.h"
#include "Character.h"
#include "StatusManager.h"
#include "Utils.h"
#include <iostream>
AchievementManager::AchievementManager() {
    Init();
}

static int midBossKill = 0;

AchievementManager::~AchievementManager() {}
void AchievementManager::Init() {
    // m_Achievements["업적 이름"] = false; 양식으로 추가
    m_Achievements["첫걸음"] = false;
    m_Achievements["레벨10달성"] = false;
    m_Achievements["이제나도부자"] = false;
    m_Achievements["진짜개발자"] = false;
    m_Achievements["내배캠지배자"] = false;
    m_Achievements["알고리즘 마스터"] = false;
    m_Achievements["레퍼런스 마스터"] = false;
    m_Achievements["템플릿 마스터"] = false;
    m_Achievements["내배캠행동대장"] = false;
    // m_Achievements["청출어람"] = false;

}
void AchievementManager::UpdateAchievements(Character* player, StatusManager* sm) {
    //if (!m_Achievements["업적 이름"] && 업적 조건) {} 양식으로 작성
    if (!m_Achievements["첫걸음"] && player->getATK() >= 50) {
        m_Achievements["첫걸음"] = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] '첫걸음' - 코딩력 50 달성!" << endl;
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
        && player->getATK() >= 100
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

    if (!m_Achievements["레퍼런스 마스터"]
        && sm->m_KillCounts["레퍼런스"] >= 5) {

        m_Achievements["레퍼런스 마스터"] = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 레퍼런스 처치 5회 달성!" << endl;
        Utils::DrawLine();
        cout << endl;
    }

    if (!m_Achievements["알고리즘 마스터"]
        && sm->m_KillCounts["알고리즘"] >= 5) {

        m_Achievements["알고리즘 마스터"] = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 알고리즘 처치 5회 달성!" << endl;
        Utils::DrawLine();
        cout << endl;
    }

    if (!m_Achievements["템플릿 마스터"]
        && sm->m_KillCounts["템플릿"] >= 5) {

        m_Achievements["템플릿 마스터"] = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 템플릿 처치 5회 달성!" << endl;
        Utils::DrawLine();
        cout << endl;
    }

    if (!m_Achievements["내배캠행동대장"]
        && sm->m_KillCounts["레퍼런스"] >= 3
        && sm->m_KillCounts["알고리즘"] >= 3
        && sm->m_KillCounts["템플릿"] >= 3) {

        m_Achievements["내배캠행동대장"] = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 내배캠행동대장 - 다양한 C++ 문법을 해결했습니다!" << endl;
        Utils::DrawLine();
        cout << endl;
    }

    /* if (!m_Achievements["청출어람"]
        && sm->m_KillCounts["튜터"] >= 3) {

        m_Achievements["청출어람"] = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 템플릿 처치 5회 달성!" << endl;
        Utils::DrawLine();
        cout << endl;
    }
    */
}
