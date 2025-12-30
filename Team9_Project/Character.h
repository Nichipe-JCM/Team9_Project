#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Character
{
private:
	string Name;
	int HP, MaxHP;
	int ATK;
	int EXP;
	int EXPToLevelUp;
	int Level;
	int MaxLevel;
	int Gold;
	int MaxInventorySize;

	vector<Item> Inventory;


public:
	Character(string name, int maxHp, int atk);

	string getName()const;
	int getHP()const;
	int getMaxHP()const;
	int getATK()const;
	int getEXP()const;
	int getLevel()const;
	int getEXPToLevelUp()const;
	int getGold()const;
	vector<Item> getInventory()const;

	void setHP(int Hp);
	void setMaxHP(int MaxHp);
	void setATK(int atk);
	void setEXP(int exp);
	void setLevel(int level);
	void setGold(int gold);

	void LevelUp();
	void Attack(Character& target);
	void GetHit(int damage);

};

