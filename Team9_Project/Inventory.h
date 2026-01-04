#pragma once
#include "Item.h"
#include <vector>
using namespace std;

class StatusManager;
class Character;

class Inventory
{
private:
	vector<Item*> m_Inventory;
	const int m_MaxInventorySlot;
public:
	Inventory(int slot);
	~Inventory();
	bool AddItem(Item* item);
	void RemoveItemFromIndex(int index);
	void RemoveItemFromPointer(Item* item);
	Item* GetItem(int index);
	vector<Item*>& GetInventory();
	int GetMaxInventorySlot() const { return m_MaxInventorySlot; }
	int GetCurrentInventorySize() const { return m_Inventory.size(); }
	void ManageInventory(StatusManager* sm, Character* ch);
};

