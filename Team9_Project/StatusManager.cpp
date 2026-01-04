#include "StatusManager.h"
#include "AchievementManager.h"
#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include "Utils.h"
#include <iostream>
#include <algorithm>
using namespace std;

StatusManager::StatusManager() {}
StatusManager::~StatusManager() {}
void StatusManager::AddKill(const string& name) {
	m_KillCounts[name]++;
}
void StatusManager::DisplayCharacterStatus(Character* ch) {
	Utils::DrawLine();
	cout << "캐릭터 정보를 출력합니다." << endl;
	cout << "이름: " << ch->getName() << ", 레벨: " << ch->getLevel() << ", HP: " << ch->getHP() << "/" << ch->getMaxHP() << endl;
	cout << "코딩력: " << ch->getATK() << ", Zep 코인: " << ch->getGold() << ", 경험치: " << ch->getEXP() << "/" << ch->getEXPToLevelUp() << endl;
	Utils::DrawLine();
}
void StatusManager::DisplayBattleStatus() {
	Utils::DrawLine();
	for (auto const& namecount : m_KillCounts) {
		cout << "[" << namecount.first << "] 처치: " << namecount.second << "회" << endl;
	}
	Utils::DrawLine();
}
void StatusManager::DisplayAchievements(AchievementManager* am) {
	int index = 1;
	Utils::DrawLine();
	cout << "[ 업적 목록 ]" << endl;
	for (auto const& pair : am->m_Achievements) {
		if (pair.second) {
			cout << index << ". [V] " << pair.first << " (달성 완료)" << endl;
		}
		else {
			cout << index << ". [ ] " << pair.first << " (미달성)" << endl;
		}
	}
	Utils::DrawLine();
}
void StatusManager::DisplayInventory(Inventory* inv) {
	Utils::DrawLine();
	vector<Item*>& vec = inv->GetInventory();
	sort(vec.begin(), vec.end(), [](Item* a, Item* b) {
		if (a == nullptr) return false;
		if (b == nullptr) return true;
		if (a->getItemType() != b->getItemType()) {
			return a->getItemType() < b->getItemType();
		}
		return a->getName() < b->getName();
		});
	int index = 1;
	if (vec.empty()) {
		cout << "인벤토리가 비었습니다." << endl;
		Utils::DrawLine();
		return;
	}
	else {
		for (const Item* i : vec) {
			cout << index << ". ";
			i->PrintInfo();
			index++;
		}
	}
	Utils::DrawLine();
}