#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Utils.h"

class Character;
class Inventory;
class Monster;

class UIManager
{
public:
    UIManager();
    ~UIManager();

    void RenderBattleScreen(const Character* player, const Monster* monster);
};