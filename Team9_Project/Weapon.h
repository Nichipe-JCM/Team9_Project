#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
	Weapon(const string& m_name, int m_value, int m_damage);
	int Damage() const;
	string getType() const override { return "무기"; }
	void PrintInfo() const override;

private:
	int m_damage;
};
