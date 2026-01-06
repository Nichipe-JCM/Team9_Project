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
	int height;
};


class UIManager
{
public:
    UIManager();
    ~UIManager();
	std::map<std::string, ASCIIPicture> MonsterArt;

    int GetArtHeight(const std::string& monsterName);
    void RenderBattleScreen(const Character* player, const Monster* monster);
    void OpeningScene();
    void EndingScene();
    void FinalBossAppearance();
	void Mainscreen();
	std::string RenderMonsterArt(const std::string& monsterName);
};