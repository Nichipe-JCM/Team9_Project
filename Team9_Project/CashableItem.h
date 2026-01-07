#pragma once
#include "Item.h"
using namespace std;

class CashableItem : public Item
{
public:
	CashableItem(const string& m_name, int value, ItemCategory type, Rarity rarity);
	string getType() const override { return "환금아이템"; }
	void PrintInfo() const override;
	Item* clone() const override {
		return new CashableItem(*this); // 복사 생성자 호출 (내용을 그대로 베낌)
	}
	bool getEquipped() { return false; }
};