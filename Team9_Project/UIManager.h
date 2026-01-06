#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Utils.h"

class Character;
class Inventory;
class Monster;

struct ASCIIPicture
{
    std::string art;
    int height = 0;
};

class UIManager
{
private:
	std::vector<std::string> m_battleLog;
	const int Max_DisplayLog = 10;
public:
    UIManager();
    ~UIManager();
	std::map<std::string, ASCIIPicture> MonsterArt;

    void AddLog(std::string message) { m_battleLog.push_back(message); }
	void ClearLog() { m_battleLog.clear(); }
    void PrintLogs();

    void RenderBattleScreen(const Character* player, const Monster* monster);
    void OpeningScene();
    void EndingScene();
    void FinalBossAppearance();
	void Mainscreen();
    int GetArtHeight(const std::string& monsterName);
	std::string RenderMonsterArt(const std::string& monsterName);




};