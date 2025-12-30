#pragma once
#include "Item.h"
using namespace std;

class CashableItem : public Item
{
public:
	CashableItem(const string& name, int value);
	string getType() const override { return "환금아이템"; }
};