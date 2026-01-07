#include "StatusManager.h"
#include "AchievementManager.h"
#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include "Utils.h"
#include <iostream>
#include <algorithm>
using namespace std;


StatusManager::StatusManager() {
	m_KillCounts["포인터"] = 0;
	m_KillCounts["레퍼런스"] = 0;
	m_KillCounts["템플릿"] = 0;
	m_KillCounts["변수"] = 0;
	m_KillCounts["함수"] = 0;
	m_KillCounts["배열"] = 0;
	m_KillCounts["알고리즘"] = 0;
	m_KillCounts["객체"] = 0;
	m_KillCounts["부동소수점"] = 0;
	m_KillCounts["클래스"] = 0;
	m_KillCounts["김조은 튜터"] = 0;
	m_KillCounts["김극민 튜터"] = 0;
	m_KillCounts["김봉재 튜터"] = 0;
	m_KillCounts["손승현 튜터"] = 0;
	m_KillCounts["강창민 튜터"] = 0;
}
StatusManager::~StatusManager() {}
void StatusManager::AddKill(const string& name) {
	m_KillCounts[name]++;
	totalKills++;
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
	cout << Color::BRIGHT_GREEN << "\n총 처치 횟수: " << totalKills << "회" << Color::RESET << endl;
	Utils::DrawLine();
	Utils::WaitForKeypress();
}
void StatusManager::DisplayAchievements(AchievementManager* am) {
	int index = 1;
	Utils::DrawLine();
	cout << Color::GOLD << "[ 업적 목록 ]" << endl;
	for (auto const& str : am->m_AchievementOrder) {
		const Achievement& a = am->m_Achievements[str];
		if (a.achieved) {
			cout << Color::BRIGHT_WHITE << index << Color::LIME << ". [V] " << Color::BRIGHT_WHITE << a.name << " (달성 완료) - " << a.description << endl;
		}
		else {
			cout << Color::BRIGHT_WHITE << index << Color::OLIVE <<". [ ] " << Color::BRIGHT_WHITE << a.name << " (미달성) - " << a.description << endl;
		}
		index++;
	}
	cout << Color::BRIGHT_GREEN << "\n총 완료 업적: " << am->achievedCount << "개" << Color::RESET << endl;
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
		cout << Color::GOLD <<"인벤토리가 비었습니다." << endl;
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
