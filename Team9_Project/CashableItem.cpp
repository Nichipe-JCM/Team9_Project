#include "CashableItem.h"
#include <iostream>

CashableItem::CashableItem(const string& m_name, int value, ItemCategory type, Rarity rarity)
	: Item(m_name, value, 0, 0, 0, ItemCategory::Cash, rarity)
{}
	void CashableItem::PrintInfo() const {
		Item::PrintInfo();
		cout << "타입: 환금 아이템, 판매 가격: " << getValue()*0.6 << "코인" << endl;
	}