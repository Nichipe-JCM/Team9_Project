#include "Inventory.h"

using namespace std;

Inventory::Inventory(int slot) : m_MaxInventorySlot(slot) {}
Inventory::~Inventory(){}
void Inventory::AddItem(Item* item) {

}
void Inventory::RemoveItem(int index) {

}
void Inventory::UseItem(int index) {

}
vector<Item*> Inventory::GetItem() {
	return m_Inventory;
}