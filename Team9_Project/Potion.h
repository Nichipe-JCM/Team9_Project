#pragma once
#include "Item.h"
using namespace std;

class Potion : public Item
{
public:
	Potion(const string& m_name, int m_value)
		: Item(m_name, m_value) {
	}
	// 추상으로 두고 외부에서 제작
	virtual int getEffectAmount() const = 0;
	virtual string getType() const override = 0;
};
