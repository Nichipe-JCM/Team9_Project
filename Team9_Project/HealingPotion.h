#pragma once
#include "Potion.h"
#include "Monster.h"

class HealingPotion : public Potion
{
public:
	HealingPotion(const string& m_name, int m_value, int m_healAmount, ItemCategory type, Rarity rarity)
		: Potion(m_name, m_value, m_healAmount, 0, ItemCategory::HPotion, rarity) {}
	int getEffectAmount() const override;
	string getType() const override { return "회복포션"; }
	void PrintInfo() const override;

private:
	int m_healAmount{ 0 }; // healamount 변수 초기화
};
