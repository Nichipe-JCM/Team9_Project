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
	m_Achievements["업적1"] = false;
	m_Achievements["업적2"] = false;
	m_Achievements["업적3"] = false;
}

void AchievementManager::UpdateAchievements(Character* player, StatusManager* sm) {
    //if (!m_Achievements["업적 이름"] && 업적 조건) {} 양식으로 작성

    if (!m_Achievements["업적1"] && player->getLevel() >= 10) {
        m_Achievements["업적1"] = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] '업적1' - 레벨 10 달성!" << endl;
        Utils::DrawLine();
        cout << endl;
    }

    if (!m_Achievements["업적2"] && player->getGold() >= 1000) {
        m_Achievements["업적2"] = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] '업적2' - 1000골드 수집!" << endl;
        Utils::DrawLine();
        cout << endl;
    }   
    
    if (!m_Achievements["업적3"] && sm->m_KillCounts["강창민 튜터님"] >= 1) {
        m_Achievements["업적3"] = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] '업적3' - 강창민 튜터님 1회 격파!" << endl;
        Utils::DrawLine();
        cout << endl;
    }

}