#include "BuffPotion.h"
#include <iostream>

BuffPotion::BuffPotion(const string& name, int value, int buffAmount) // 여기도 전체적으로 고쳐서 레어리티를 넘겨줘야 할 것 같습니다
	: Potion(name, value, 0/*버프포션이라 힐량 0*/, buffAmount, ItemCategory::BPotion), m_buffAmount(buffAmount) {
}

int BuffPotion::getEffectAmount() const
{
	return m_buffAmount;
}
void BuffPotion::PrintInfo() const {
	Item::PrintInfo();
	cout << "타입: 코딩력 상승, 증가량: " << getBuff() << ", 판매 가격: " << getValue() << "코인" << endl;
}