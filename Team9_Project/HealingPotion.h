#pragma once
#include "Potion.h"
#include "Monster.h"

class HealingPotion : public Potion
{
public:
	HealingPotion(const string& m_name, int m_value, int m_healAmount, ItemCategory type, Rarity rarity);
	int getEffectAmount() const override;
	string getType() const override { return "회복포션"; }
	void PrintInfo() const override;
	Item* clone() const override {
		return new HealingPotion(*this); // 복사 생성자 호출 (내용을 그대로 베낌)
	}
	void setEquipped(bool status) { m_isEquipped = status; }
	bool getEquipped() override { return m_isEquipped; }

private:
	int m_healAmount{ 0 }; // healamount 변수 초기화
	bool m_isEquipped{ false }; // m_isEquipped 초기화 추가
};
