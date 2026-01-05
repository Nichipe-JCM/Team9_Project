#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Utils.h"

class Character;
class Inventory;
class Monster;

class UIManager
{
public:
    UIManager();
    ~UIManager();
	std::map<std::string, std::string> MonsterArt;

    void RenderBattleScreen(const Character* player, const Monster* monster);
    void OpeningScene();
    void EndingScene();
    void FinalBossAppearance();
	void Mainscreen();
	std::string RenderMonsterArt(const std::string& monsterName);
};