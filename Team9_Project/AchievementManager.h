#pragma once
#include <map>
#include <string>
#include <vector>

using namespace std;

class StatusManager; 
class Character;  

class AchievementManager
{
public:
    map<string, bool> m_Achievements;
    AchievementManager();
    ~AchievementManager();
    void Init();
    void UpdateAchievements(Character* player, StatusManager* sm);
};
