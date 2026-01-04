#pragma once
#include "Potion.h"

class BuffPotion : public Potion
{
public:
	BuffPotion(const string& m_name,
		int m_value,
		int m_buffAmount,
		ItemCategory type,
		Rarity rarity);

	int getEffectAmount() const override { return m_buffAmount; }
	string getType() const override { return "버프아이템"; }
	void PrintInfo() const override;
	Item* clone() const override {
		return new BuffPotion(*this); // 복사 생성자 호출 (내용을 그대로 베낌)
	}

private:
	int m_buffAmount;
};
