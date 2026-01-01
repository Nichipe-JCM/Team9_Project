#pragma once
#include "Item.h"
using namespace std;

class Potion : public Item
{
public:
	Potion(const string& m_name, int m_value, int heal, int buff, ItemCategory type) // 포션이 2개로 나뉘어져있어서 힐이나 버프 수치를 받아오지 못하면 item으로 넘겨줄수가 없습니다. 레어리티는 임시로 common으로 두었습니다
		: Item(m_name, m_value, 0, heal, buff, type, Rarity::Common) {
	}
	// 추상으로 두고 외부에서 제작
	virtual int getEffectAmount() const = 0;
	virtual string getType() const override = 0;
};
