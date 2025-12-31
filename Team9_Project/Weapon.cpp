#include "Weapon.h"
#include <iostream>
using namespace std;


Weapon::Weapon(const string& m_name, int m_value, int m_damage)
	: Item(m_name, m_value), m_damage(m_damage)
{}


int Weapon::Damage() const
{
	return m_damage;
}

void Weapon::PrintInfo() const {
	Item::PrintInfo();
	cout << "타입: 무기, 코딩력: " << getAttack() << ", 판매 가격: " << getValue() << "코인" << endl;
}
