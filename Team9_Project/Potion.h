#pragma once
#include "Item.h"
using namespace std;

class Potion : public Item
{
public:
	Potion(const string& name, int value, int healAmount);
	int getHealAmount() const;
	string getType() const override { return "포션"; }

private:
	int healAmount;
};
