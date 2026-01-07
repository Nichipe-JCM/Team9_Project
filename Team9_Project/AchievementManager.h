#pragma once
#include <map>
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
 map<string, Achievement> m_Achievements;
 int achievedCount = 0;
 AchievementManager();
 ~AchievementManager();
 void Init();
 void UpdateAchievements(Character* player, StatusManager* sm);
};
