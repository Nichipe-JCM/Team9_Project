#include "BuffPotion.h"
#include <iostream>

BuffPotion::BuffPotion(const string& name, int value, int buffAmount)
	: Potion(name, value), m_buffAmount(buffAmount) {
}

int BuffPotion::getEffectAmount() const
{
	return m_buffAmount;
}
void BuffPotion::PrintInfo() const {
	Item::PrintInfo();
	cout << "타입: 코딩력 상승, 증가량: " << getBuff() << ", 판매 가격: " << getValue() << "코인" << endl;
}