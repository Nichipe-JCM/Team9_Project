#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Item.h"

class Character;
class Item;


// 아이템과 드랍확률을 그냥 묶어버리기...
struct DropEntry
{
	std::shared_ptr<Item> item;
	Rarity rarity;
	double dropRate;
	ItemCategory category;

	DropEntry(std::shared_ptr<Item> item, Rarity rarity, double dropRate, ItemCategory category)
		: item(item), rarity(rarity), dropRate(dropRate), category(category)
	{
		// 생성자에서 레어리티 검증
		if (item->getRarity() != rarity) {
			throw std::invalid_argument("아이템 레어리티와 DropEntry 레어리티가 일치하지 않습니다.");
		}
	}
}; // 검증은 ai에게 물어봄


class Monster
{

public:
	// 레벨 기반 생성자
	Monster(const std::string& name, int level, int gold, int exp);
	virtual ~Monster() = default; // 임시 가상 소멸자

	virtual void attack(Character* target);
	virtual void GetHit(int damage);

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
