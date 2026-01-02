#include "HealingPotion.h"
#include <iostream>

HealingPotion::HealingPotion(const std::string& name, int value, int healAmount, ItemCategory type, Rarity rarity)
	: Potion(name, value, healAmount, 0, type, rarity), m_healAmount(healAmount) { }

int HealingPotion::getEffectAmount() const
{
	return m_healAmount;
}
void HealingPotion::PrintInfo() const {
	Item::PrintInfo();
	cout << "타입: 회복 포션, 회복량: " << getHeal() << ", 판매 가격: " << getValue() << "코인" << endl;
}