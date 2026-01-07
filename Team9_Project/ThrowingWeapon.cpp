#include "ThrowingWeapon.h"
#include <stdexcept>
#include <iostream>
using namespace std;

ThrowingWeapon::ThrowingWeapon(const string& m_name, int m_value, int m_damage, int m_quantity, ItemCategory type, Rarity rarity)
	: Item(m_name, m_value, m_damage, 0, 0, ItemCategory::Throwing, Rarity(rarity)), m_damage(m_damage), m_quantity(m_quantity)
{
	m_isEquipped = false;
}

// 공격력
int ThrowingWeapon::getDamage() const
{
	return m_damage;
}

// 남은 투척 횟수
int ThrowingWeapon::getQuantity() const
{
	return m_quantity;
}

void ThrowingWeapon::PrintInfo() const {
	if (m_isEquipped) std::cout << "\033[36m" << "[장착중] " << "\033[0m";
	Item::PrintInfo();
	cout << "타입: 투척 무기   코딩력: " << getAttack() << "   판매 가격: " << getValue()*0.6 << "코인" << endl;
}