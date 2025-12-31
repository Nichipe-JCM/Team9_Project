#pragma once
#include "Potion.h"

class BuffPotion : public Potion
{
public:
	BuffPotion(const string& m_name, int m_value, int m_buffAmount);
	int getEffectAmount() const override;
	string getType() const override { return "버프아이템"; }
	void PrintInfo() const override;

private:
	int m_buffAmount;
};
