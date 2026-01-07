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
    m_Achievements["첫걸음"] = {"첫걸음", false, "코딩력 100 달성"};
    m_Achievements["레벨10달성"] = {"레벨10달성", false, "레벨10 달성"};
    m_Achievements["이제나도부자"] = {"이제나도부자", false, "10000 Zep코인 수집"};
    m_Achievements["진짜개발자"] = {"진짜개발자", false, "코딩력300, 체력1000, Zep코인 1000 달성"};
    m_Achievements["내배캠지배자"] = {"내배캠지배자", false, "강창민 튜터 1회 처치"};
    m_Achievements["알고리즘 마스터"] = {"알고리즘 마스터", false, "알고리즘 처치5회"};
    m_Achievements["레퍼런스 마스터"] = {"레퍼런스 마스터", false, "레퍼런스 처치5회"};
    m_Achievements["템플릿 마스터"] = {"템플릿 마스터", false, "템플릿 처치5회"};
    m_Achievements["내배캠행동대장"] = {"내배캠행동대장", false, "레퍼런스/알고리즘/템플릿 각각3회 처치"};
    m_Achievements["청출어람"] = {"청출어람", false, "김조은/김극민/김봉재/손승현 튜터 각1회 처치"};
    m_Achievements["전투 마스터"] = {"전투 마스터", false, "전체 전투에서 50회 승리"};
    m_Achievements["전설의 개발자"] = { "전설의 개발자", false, "강창민 튜터 5회 처치" };

}
void AchievementManager::UpdateAchievements(Character* player, StatusManager* sm) {
    //if (!m_Achievements["업적 이름"].achieved && 업적 조건) {} 양식으로 작성
    if (!m_Achievements["첫걸음"].achieved && player->getATK() >=50) {
        m_Achievements["첫걸음"].achieved = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] '첫걸음' - 코딩력 100 달성!" << endl;
        Utils::DrawLine();
        cout << endl;
		achievedCount++;
    }
    if (!m_Achievements["레벨10달성"].achieved && player->getLevel() >=10) {
        m_Achievements["레벨10달성"].achieved = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 레벨 10 달성!" << endl;
        Utils::DrawLine();
        cout << endl;
        achievedCount++;
    }
    if (!m_Achievements["이제나도부자"].achieved && player->getGold() >=10000) {
        m_Achievements["이제나도부자"].achieved = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 10000 Zep 수집!" << endl;
        Utils::DrawLine();
        cout << endl;
        achievedCount++;
    }
    if (!m_Achievements["진짜개발자"].achieved
        && player->getATK() >=300
        && player->getHP() >=1000
        && player->getGold() >=1000) {
        m_Achievements["진짜개발자"].achieved = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] '진짜 개발자' - 코딩력, 체력, Zep 모두 증명!" << endl;
        Utils::DrawLine();
        cout << endl;
		achievedCount++;
    }
    if (!m_Achievements["내배캠지배자"].achieved && sm->m_KillCounts["강창민 튜터"] >=1) {
        m_Achievements["내배캠지배자"].achieved = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 내배캠지배자 - 강창민 튜터님 격파!" << endl;
        Utils::DrawLine();
        cout << endl;
        achievedCount++;
    }

    if (!m_Achievements["레퍼런스 마스터"].achieved
        && sm->m_KillCounts["레퍼런스"] >=5) {

        m_Achievements["레퍼런스 마스터"].achieved = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 레퍼런스 마스터 - 레퍼런스 처치 5회 달성!" << endl;
        Utils::DrawLine();
        cout << endl;
        achievedCount++;
    }

    if (!m_Achievements["알고리즘 마스터"].achieved
        && sm->m_KillCounts["알고리즘"] >=5) {

        m_Achievements["알고리즘 마스터"].achieved = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 알고리즘 마스터 - 알고리즘 처치 5회 달성!" << endl;
        Utils::DrawLine();
        cout << endl;
        achievedCount++;
    }

    if (!m_Achievements["템플릿 마스터"].achieved
        && sm->m_KillCounts["템플릿"] >=5) {

        m_Achievements["템플릿 마스터"].achieved = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 템플릿 마스터 - 템플릿 처치 5회 달성!" << endl;
        Utils::DrawLine();
        cout << endl;
        achievedCount++;
    }

    if (!m_Achievements["내배캠행동대장"].achieved
        && sm->m_KillCounts["레퍼런스"] >=3
        && sm->m_KillCounts["알고리즘"] >=3
        && sm->m_KillCounts["템플릿"] >=3) {

        m_Achievements["내배캠행동대장"].achieved = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 내배캠행동대장 - 다양한 C++ 문법을 해결했습니다!" << endl;
        Utils::DrawLine();
        cout << endl;
        achievedCount++;
    }

    if (!m_Achievements["청출어람"].achieved
        && sm->m_KillCounts["김조은 튜터"] >=1
        && sm->m_KillCounts["김극민 튜터"] >=1
        && sm->m_KillCounts["김봉재 튜터"] >=1
        && sm->m_KillCounts["손승현 튜터"] >=1)
    {
        m_Achievements["청출어람"].achieved = true;

        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 청출어람 - 튜터님들의 실력을 넘어섰습니다!" << endl;
        Utils::DrawLine();
        cout << endl;
        achievedCount++;
    }

    if (!m_Achievements["전투 마스터"].achieved && sm->totalKills >= 50) {
        m_Achievements["전투 마스터"].achieved = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 전투 마스터 - 당신은 진정한 전투의 마스터!!" << endl;
        Utils::DrawLine();
        cout << endl;
        achievedCount++;
	}

    if (!m_Achievements["전설의 개발자"].achieved && sm->m_KillCounts["강창민 튜터"] >= 5) {
        m_Achievements["전설의 개발자"].achieved = true;
        cout << endl;
        Utils::DrawLine();
        cout << "[업적 달성!] 전설의 개발자 - 강창민 튜터님을 5번이나 격파했다니!!" << endl;
        Utils::DrawLine();
        cout << endl;
        achievedCount++;
	}

}
