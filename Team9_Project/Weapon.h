#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
	Weapon(const string& name, int value, int damage);
	int Damage() const;
	string getType() const override { return "무기"; }

private:
	int damage;
};
