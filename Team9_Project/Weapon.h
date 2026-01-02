#pragma once
#include "Item.h"
#include "Monster.h"
class Weapon : public Item
{
public:
	Weapon(const std::string& m_name, int m_value, int m_damage, ItemCategory type, Rarity rarity);
	int Damage() const;
	std::string getType() const override { return "무기"; }
	void PrintInfo() const override;

private:
	int m_damage;
};
