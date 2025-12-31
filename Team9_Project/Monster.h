#pragma once
#include <string>
#include <vector>
#include <memory>

class Character;
class Item;

// 아이템 희귀도 설정
enum class Rarity {
	Common,
	Rare,
	Epic,
	Legendary
};

// 아이템 카테고리 
enum class ItemCategory
{
	Weapon, Throwing, HPotion, BPotion, Cash
};


// 아이템과 드랍확률을 그냥 묶어버리기...
struct DropEntry
{
	std::shared_ptr<Item> item;
	Rarity rarity;
	double dropRate; // 확률 (0.0 ~ 1.0)
	ItemCategory category;
};


class Monster
{

public:
	// 레벨 기반 생성자
	Monster(const std::string& name, int level, int gold, int exp);

	virtual void attack(Character* target);
	void GetHit(int damage);

	std::shared_ptr<Item> dropItem();
	bool checkDeath();

	// get
	std::string getName() const;
	int getHP() const;
	int getAttack() const;
	int getDropGold() const;
	int getDropEXP() const;
	bool isAlive;

	// set
	void setName(const std::string name);
	void setHP(int m_HP);

protected:
	std::string name;
	int m_HP;
	int m_ATK;
	int m_dropGold;
	int m_dropEXP;
};
