#include "Inventory.h"
#include "StatusManager.h"
#include "Character.h"
#include "Utils.h"
#include "Item.h"
#include "Windows.h"
#include "Potion.h"
#include <iostream>
#include <algorithm>

using namespace std;

Inventory::Inventory(int slot) : m_MaxInventorySlot(slot) {}
Inventory::~Inventory(){
    for(int i = 0; i < m_Inventory.size(); i++) {
        delete m_Inventory[i];
	}
}
bool Inventory::AddItem(Item* item) {
	if (m_Inventory.size() >= m_MaxInventorySlot) {
		cout << "인벤토리가 가득 찼습니다! 어떻게 하시겠습니까?" << endl;
		cout << "1. 소지중인 아이템 제거 후 획득  2. 아이템 획득 포기" << endl;
		int choice = Utils::GetSafeInput();
        if (choice == 1) {
            Utils::DrawLine();
            int index = 1;
            for (const Item* i : m_Inventory) {
                cout << index << ". ";
                i->PrintInfo();
                index++;
            }
			Utils::DrawLine();
           cout << "제거할 아이템의 번호를 입력하세요: ";
            while(true) {
                int itemIndex = Utils::GetSafeInput();
                if (itemIndex < 1 || itemIndex >= m_Inventory.size() + 1) {
                    cout << "잘못된 아이템 번호입니다. 다시 입력하세요: ";
                }
                else {
                    RemoveItemFromIndex(itemIndex);
                    cout << "아이템을 제거하고 새로운 아이템을 획득했습니다." << endl;
                    m_Inventory.push_back(item);
                    return true;
                    break;
                }
			}
        }
        delete item;
		return false;
	}
	m_Inventory.push_back(item);
	return true;
}
void Inventory::RemoveItemFromIndex(int index) {
    if (index < 1 || index >= m_Inventory.size() + 1) {
        return;
    }
    m_Inventory.erase(m_Inventory.begin() + index - 1);
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
    while (true) {
        sm->DisplayInventory(this);
        Utils::DrawLine();
        cout << "1. 아이템 사용/장착  2. 아이템 제거  3. 나가기" << endl;
        Utils::DrawLine();
        int choice = Utils::GetSafeInput();
        switch (choice) {
        case 1: {
            cout << "사용/장착할 아이템의 번호를 입력하세요: ";
            int itemIndex = Utils::GetSafeInput();
            Item* item = GetItem(itemIndex);
            if (item == nullptr) {
                cout << "잘못된 아이템 번호입니다." << endl;
                break;
            }
            if (item->getItemType() == ItemCategory::Weapon) {
                ch->manageEquipment(1, item, 1); // 무기 슬롯
            }
            else if (item->getItemType() == ItemCategory::Throwing) {
                ch->manageEquipment(1, item, 2); // 투척무기 슬롯
            }
            else if (item->getItemType() == ItemCategory::HPotion) {
                ch->manageEquipment(1, item, 3); // 포션 슬롯
            }
            else if (item->getItemType() == ItemCategory::BPotion) {
				ch->usePotion(dynamic_cast<Potion*>(item));
                RemoveItemFromIndex(itemIndex);
                delete item;
			}
            else {
                cout << "이 아이템은 장착하거나 사용할 수 없습니다." << endl;
            }
            break;
        }
        case 2: {
            cout << "제거할 아이템의 번호를 입력하세요: ";
            int itemIndex = Utils::GetSafeInput();
            Item* item = GetItem(itemIndex);
            if (item == nullptr) {
                cout << "잘못된 아이템 번호입니다." << endl;
                return;
            }
            if (item == ch->getEquippeditem() || item == ch->getEquippedThrow() || item == ch->getEquippedPotion()) {
                cout << "장착 중인 아이템은 제거할 수 없습니다. 먼저 장착을 해제하세요." << endl;
                return;
            }
            RemoveItemFromIndex(itemIndex);
            cout << item->getName() << "이(가) 인벤토리에서 제거되었습니다." << endl;
            delete item; // 메모리 해제
            break;
        }
        case 3:
			cout << "이전 메뉴로 돌아갑니다." << endl;
            return;
        default:
            cout << "잘못된 선택입니다." << endl;
            break;
        }
		system("pause");
    }
}