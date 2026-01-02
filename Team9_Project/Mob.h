#pragma once
#include "Monster.h"

class Character;

class Mob :
    public Monster
{
public:
    Mob(const std::string& name, int level, int gold, int exp)
        : Monster(name, level, gold, exp) { }

    static Monster* createRandomMonster(Character* Player);
};

