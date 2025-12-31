#pragma once
#include "Item.h"
#include <vector>

class Inventory
{
private:
	vector<Item*> m_Inventory;
	const int m_MaxInventorySlot;
public:
	Inventory(int slot);
	~Inventory();
	void AddItem(Item* item);
	void RemoveItem(int index);
	void UseItem(int index);
	vector<Item*> GetItem();
};

