#pragma once
#include "Item.h"
using namespace std;

class ThrowingWeapon : public Item
{
public:
	ThrowingWeapon(const string& name, int value, int damage, int quantity);
	int getDamage() const;
	int getQuantity() const;
	string getType() const override { return "ÅõÃ´¹«±â"; }

private:
	int damage;
	int quantity; // ÅõÃ´È½¼ö
};