#pragma once
#include "Item.h"
using namespace std;

class ThrowingWeapon : public Item
{
public:
	ThrowingWeapon(const string& m_name, int m_value, int m_damage, int m_quantity, ItemCategory type, Rarity rarity);
	int getDamage() const;
	int getQuantity() const;
	bool use();
	string getType() const override { return "투척무기"; }
	void PrintInfo() const override;
	Item* clone() const override {
		return new ThrowingWeapon(*this); // 복사 생성자 호출 (내용을 그대로 베낌)
	}

private:
	int m_damage;
	int m_quantity;
};
