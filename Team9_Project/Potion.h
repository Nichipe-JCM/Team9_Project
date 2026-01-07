#pragma once
#include "Item.h"
using namespace std;

class Potion : public Item
{
public:
	Potion(const string& m_name, 
		int m_value, 
		int heal, 
		int buff, 
		ItemCategory type, 
		Rarity rarity) // 레어리티 인자 추가
		: Item(m_name, m_value, 0, heal, buff, type, rarity) {
	}
	// 추상으로 두고 외부에서 제작
	virtual int getEffectAmount() const = 0;
	virtual string getType() const override = 0;
	
};
