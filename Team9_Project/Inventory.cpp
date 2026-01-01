#include "Inventory.h"
#include "StatusManager.h"
#include <iostream>
#include <algorithm>

using namespace std;

Inventory::Inventory(int slot) : m_MaxInventorySlot(slot) {}
Inventory::~Inventory(){}
bool Inventory::AddItem(Item* item) {
	if (m_Inventory.size() >= m_MaxInventorySlot) {
		cout << "인벤토리가 가득 찼습니다!" << endl;
		return false;
	}
	m_Inventory.push_back(item);
	return true;
}
void Inventory::RemoveItemFromIndex(int index) {
    if (index < 1 || index >= m_Inventory.size()+1) {
        return;
    }
    m_Inventory.erase(m_Inventory.begin() + index -1);
}
void Inventory::RemoveItemFromPointer(Item* item) {
    auto it = find(m_Inventory.begin(), m_Inventory.end(), item);
    if (it != m_Inventory.end()) {
        m_Inventory.erase(it);
    }
}
Item* Inventory::GetItem(int index) {
    if (index < 1 || index >= m_Inventory.size()+1) {
        return nullptr;
    }
    return m_Inventory[index - 1];
}
vector<Item*>& Inventory::GetInventory() {
	return m_Inventory;
}
void Inventory::ManageInventory(StatusManager* sm, Character* ch) {
    sm->DisplayInventory(this);
    //이후 아이템 사용하기, 아이템 버리기 등 구현
}