#pragma once
#include "Item.h"
#include "Monster.h"
class Weapon : public Item
{
public:
	Weapon(const std::string& m_name, int m_value, int m_damage, ItemCategory type, Rarity rarity);
	int Damage() const;
	std::string getType() const override { return "무기"; }
	void PrintInfo() const override;
	Item* clone() const override {
		return new Weapon(*this); // 복사 생성자 호출 (내용을 그대로 베낌)
	}
	void setEquipped(bool status) { m_isEquipped = status; }
	bool getEquipped() { return m_isEquipped; }

private:
	int m_damage;
	bool m_isEquipped;
};
