#pragma once
#include <map>
#include <string>
#include <vector>

using namespace std;

class StatusManager; 
class Character;  

class AchievementManager
{
private:

    map<string, bool> m_Achievements;

public:
    AchievementManager();
    ~AchievementManager();
    void Init();
    void UpdateAchievements(Character* player, StatusManager* sm);
    void ShowAchievements();
};
