#pragma once
#include <string>
#include <vector>
using namespace std;

class Player;

class Monster
{
public:
	// 레벨 기반 생성자
	Monster(const string& name, int level, int gold, int exp);

	virtual void attack(Player* player);
	void GetHit(int damage);

	Item* dropItem();

	// get
	string getName() const;
	int getHP() const;
	int getAttack() const;
	int getDropGold() const;
	int getDropEXP() const;

	// set
	void setName(const string name);
	void setHP(int m_HP);

protected:
	string name;
	int m_HP;
	int m_ATK;
	int m_dropGold;
	int m_dropEXP;
};
