#pragma once
#include <map>
#include <string>
using namespace std;
class Character;
class Inventory;
class AchievementManager;

class StatusManager
{
public:
	map<string, int> m_KillCounts;
	int totalKills = 0;
	StatusManager();
	~StatusManager();
	void AddKill(const string& name);
	void DisplayCharacterStatus(Character* ch);
	void DisplayBattleStatus();
    void DisplayAchievements(AchievementManager* acm);
	void DisplayInventory(Inventory* inv);
};

