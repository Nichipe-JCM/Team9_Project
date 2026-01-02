#include "BuffPotion.h"
#include <iostream>

BuffPotion::BuffPotion(const string& name, int value, int buffAmount, ItemCategory type, Rarity rarity)
	: Potion(name, value, buffAmount, ItemCategory::BPotion, Rarity(rarity)), m_buffAmount(buffAmount) {
}

int BuffPotion::getEffectAmount() const
{
	return m_buffAmount;
}
void BuffPotion::PrintInfo() const {
	Item::PrintInfo();
	cout << "타입: 코딩력 상승, 증가량: " << getBuff() << ", 판매 가격: " << getValue() << "코인" << endl;
}