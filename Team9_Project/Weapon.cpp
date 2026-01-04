#include "Weapon.h"
#include <iostream>
using namespace std;


Weapon::Weapon(const string& m_name, int m_value, int m_damage, ItemCategory type, Rarity rarity)
	: Item(m_name, m_value, m_damage, 0, 0, ItemCategory::Weapon, Rarity(rarity)), m_damage(m_damage)
{
	m_isEquipped = false;
}


int Weapon::Damage() const
{
	return m_damage;
}

void Weapon::PrintInfo() const {
	if (m_isEquipped) std::cout << "\033[36m" << "[장착중] " << "\033[0m";
	Item::PrintInfo();
	cout << "타입: 무기   코딩력: " << getAttack() << "   판매 가격: " << getValue()*0.6 << "코인" << endl;
}
