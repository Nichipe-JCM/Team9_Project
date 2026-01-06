#include "Item.h"
#include <iostream>

Item::Item(const std::string& name, int value, int attack, int heal, int buff,
	ItemCategory itemType, Rarity rarity)
	: m_name(name), m_value(value), m_attack(attack), m_heal(heal),
	m_buff(buff), m_itemType(itemType), m_rarity(rarity) {
}

std::string Item::getName() const { return m_name; }
int Item::getValue() const { return m_value; }
int Item::getAttack() const { return m_attack; }
int Item::getHeal() const { return m_heal; }
int Item::getBuff() const { return m_buff; }
ItemCategory Item::getItemType() const { return m_itemType; }
Rarity Item::getRarity() const { return m_rarity; }

std::string Item::getRarityColor(Rarity rarity) const{
	switch (rarity) {
	case Rarity::Common:    return "\033[97m"; // 흰색
	case Rarity::Rare:      return "\033[94m"; // 파란색
	case Rarity::Epic:      return "\033[35m"; // 보라색
	case Rarity::Legendary: return "\033[33m"; // 노란색
	}
	return "\033[0m"; // 기본색
}

std::string Item::rarityToString(Rarity rarity) const{
	switch (rarity) {
	case Rarity::Common: return "Common";
	case Rarity::Rare: return "Rare";
	case Rarity::Epic: return "Epic";
	case Rarity::Legendary: return "Legendary";
	}
	return "Unknown";
}

void Item::PrintInfo() const {
	std::cout << "[" << getName() << "]" << getRarityColor(getRarity()) << "(" << rarityToString(getRarity()) << ") " << "\033[0m" << std::endl;
}

