#pragma once
#include "Item.h"
using namespace std;

class CashableItem : public Item
{
public:
	CashableItem(const string& m_name, int value, ItemCategory type, Rarity rarity);
	string getType() const override { return "환금아이템"; }
	void PrintInfo() const override;
};