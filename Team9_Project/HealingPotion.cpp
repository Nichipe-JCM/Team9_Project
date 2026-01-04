#include "HealingPotion.h"
#include <iostream>

HealingPotion::HealingPotion(const std::string& name, int value, int healAmount, ItemCategory type, Rarity rarity)
	: Potion(name, value, healAmount, 0, ItemCategory(type), Rarity(rarity)), m_healAmount(healAmount) {
	m_isEquipped = false;
}

int HealingPotion::getEffectAmount() const
{
	return m_healAmount;
}
void HealingPotion::PrintInfo() const {
	if (m_isEquipped) std::cout << "\033[36m" << "[장착중] " << "\033[0m";
	Item::PrintInfo();
	std::cout << "타입: 회복 포션   회복량: " << getEffectAmount() << "   판매 가격: " << getValue() * 0.6 << "코인" << std::endl;
}