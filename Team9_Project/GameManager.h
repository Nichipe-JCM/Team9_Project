#pragma once
#include "Character.h"
#include "Monster.h"
#include "Shop.h"
#include "EventManager.h"
#include "StatusManager.h"

class Inventory;

class GameManager
{
private:
	int m_Stage;
	Character* m_Player;
	Monster* m_CurrentMonster;
	EventManager* m_Event;
	Shop* m_Shop;
	StatusManager* m_SM;

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
	void ViewCharacterStatus(StatusManager* sm);
	void ViewBattleStatus(StatusManager* sm);
	void ViewAchievements(StatusManager* sm);
	void ViewInventory(StatusManager* sm, Inventory* inv);
};

