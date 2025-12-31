#pragma once
#include "Character.h"
#include "Event.h"
#include "Monster.h"
#include "Shop.h"
class GameManager
{
private:
	int m_Stage;
	Character* m_Player;
	Monster* m_CurrentMonster;
public:
	GameManager();
	~GameManager();
	bool DefaultMenuCheck(int choice);
	void RunGame();
	void SpawnMonster(int stage);
	void Battle();
	void BattleVictory();
	void GameOver();
	void VisitShop();
	void VisitEvent();
	void Opening();
	void Ending();
	void ViewCharacterStatus();
	void ViewBattleStatus();
	void ViewAchievements();
	void ViewInventory();
};

