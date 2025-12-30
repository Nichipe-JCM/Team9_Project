#pragma once
#include "Item.h"
using namespace std;

class Potion : public Item
{
public:
	Potion(const string& name, int value, int healAmount);
	int getHealAmount() const;
	string getType() const override { return "Æ÷¼Ç"; }

private:
	int healAmount;
};