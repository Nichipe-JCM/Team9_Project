#pragma once
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class StatusManager; 
class Character; 

struct Achievement {
 string name;
 bool achieved;
 string description;
};

class AchievementManager
{
public:
 unordered_map<string, Achievement> m_Achievements;
 vector<string> m_AchievementOrder = {
	 "첫걸음",
	 "레벨10달성",
	 "이제나도부자",
	 "진짜개발자",
	 "내배캠지배자",
	 "알고리즘 마스터",
	 "레퍼런스 마스터",
	 "템플릿 마스터",
	 "내배캠행동대장",
	 "청출어람",
	 "전투 마스터",
	 "전설의 개발자"
 };
 int achievedCount = 0;
 AchievementManager();
 ~AchievementManager();
 void Init();
 void UpdateAchievements(Character* player, StatusManager* sm);
};
