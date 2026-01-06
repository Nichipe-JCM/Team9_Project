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
	cout << Color::BRIGHT_YELLOW << "=== 캐릭터 정보 ===" << Color::RESET << endl;

	cout << Color::CYAN << "이름: " << Color::BRIGHT_WHITE << ch->getName()
		<< Color::GRAY << " | "
		<< Color::CYAN << "레벨: " << Color::BRIGHT_GREEN << ch->getLevel()
		<< Color::GRAY << " | "
		<< Color::CYAN << "HP: " << Color::BRIGHT_WHITE << ch->getHP() << "/" << ch->getMaxHP() << endl;

	cout << Color::CYAN << "코딩력: " << Color::BRIGHT_WHITE << ch->getATK()
		<< Color::GRAY << " | "
		<< Color::CYAN << "Zep 코인: " << Color::GOLD << ch->getGold() << " Z" << Color::RESET
		<< Color::GRAY << " | "
		<< Color::CYAN << "경험치: " << Color::BRIGHT_WHITE << ch->getEXP() << "/" << ch->getEXPToLevelUp() << endl;

	Utils::DrawLine();
	Utils::WaitForKeypress();
}
void StatusManager::DisplayBattleStatus() {
	Utils::DrawLine();
	cout << Color::BRIGHT_YELLOW << "=== 전적 목록 ===" << Color::RESET << endl;
	for (auto const& namecount : m_KillCounts) {
		cout << Color::BRIGHT_WHITE << "[" << namecount.first << "] "
			<< Color::GRAY << "처치: "
			<< Color::RED << namecount.second << Color::RESET << "회" << endl;
	}
	Utils::DrawLine();
	Utils::WaitForKeypress();
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
		index++;
	}
	Utils::DrawLine();
	Utils::WaitForKeypress();
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