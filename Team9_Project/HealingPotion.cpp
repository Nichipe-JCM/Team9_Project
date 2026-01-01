#include "HealingPotion.h"
#include <iostream>

HealingPotion::HealingPotion(const string& name, int value, int healAmount) // 여기도 전체적으로 고쳐서 레어리티를 넘겨줘야 할 것으로 보입니다
	: Potion(name, value, healAmount, 0, ItemCategory::HPotion), m_healAmount(healAmount) {}

int HealingPotion::getEffectAmount() const
{
	return m_healAmount;
}
void HealingPotion::PrintInfo() const {
	Item::PrintInfo();
	cout << "타입: 회복 포션, 회복량: " << getHeal() << ", 판매 가격: " << getValue() << "코인" << endl;
}