#pragma once
#include "Potion.h"

class HealingPotion : public Potion
{
public:
	HealingPotion(const string& m_name, int m_value, int m_healAmount);
	int getEffectAmount() const override;
	string getType() const override { return "회복포션"; }
	void PrintInfo() const override;

private:
	int m_healAmount;
};
