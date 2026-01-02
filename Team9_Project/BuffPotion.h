#pragma once
#include "Potion.h"

class BuffPotion : public Potion
{
public:
	BuffPotion(const string& m_name,
		int m_value,
		int m_buffAmount,
		Rarity rarity)
		: Potion(m_name, m_value, 0, m_buffAmount, ItemCategory::BPotion, rarity),
		m_buffAmount(m_buffAmount)
	{
	}

	int getEffectAmount() const override { return m_buffAmount; }
	string getType() const override { return "버프아이템"; }
	void PrintInfo() const override;

private:
	int m_buffAmount;
};
