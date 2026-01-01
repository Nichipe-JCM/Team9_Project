#include "StatusManager.h"
#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include "Utils.h"
#include <iostream>
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
void StatusManager::DisplayAchievements(AchievementManager* acm) {
	//아직 대기
}
void StatusManager::DisplayInventory(Inventory* inv) {
	Utils::DrawLine();
	const vector<Item*>& vec = inv->GetInventory();
	if (vec.empty()) {
		cout << "인벤토리가 비었습니다." << endl;
		Utils::DrawLine();
		return;
	}
	else {
		for (const Item* i : vec) {
			i->PrintInfo();
		}
	}
	Utils::DrawLine();
}