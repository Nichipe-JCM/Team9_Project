#pragma once
#include <string>

enum class ItemCategory { Weapon, Throwing, HPotion, BPotion, Cash };
enum class Rarity { Common, Rare, Epic, Legendary };

class Item {
protected:
	std::string m_name;
	int m_value;
	int m_attack;
	int m_heal;
	int m_buff;
	ItemCategory m_itemType;
	Rarity m_rarity;

public:
	Item(const std::string& name, int value, int attack, int heal, int buff,
		ItemCategory itemType, Rarity rarity);

	std::string getName() const;
	int getValue() const;
	int getAttack() const;
	int getHeal() const;
	int getBuff() const;
	ItemCategory getItemType() const;
	Rarity getRarity() const;

	std::string getRarityColor(Rarity rarity) const;
	std::string rarityToString(Rarity rarity) const;

	virtual std::string getType() const { return "아이템"; }
	virtual void PrintInfo() const;
	virtual void setEquipped(bool equipped) {}
	virtual bool getEquipped() = 0;
	virtual ~Item() = default;
	virtual Item* clone() const = 0;
};
