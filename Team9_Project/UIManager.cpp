#include "UIManager.h"
#include "Character.h"
#include "Monster.h"



UIManager::UIManager() {}
UIManager::~UIManager() {}

//void UIManager::RenderBattleScreen(const Character* player, const Monster* monster) {
//	Utils::DrawLine();
//	std::cout << "=== 전투 화면 ===" << std::endl;
//	std::cout << "[플레이어]" << std::endl;
//	std::cout << "이름: " << player->getName() << ", 레벨: " << player->getLevel() 
//			  << ", HP: " << player->getHP() << "/" << player->getMaxHP() << std::endl;
//	std::cout << "코딩력: " << player->getATK() << ", Zep 코인: " << player->getGold() 
//			  << ", 경험치: " << player->getEXP() << "/" << player->getEXPToLevelUp() << std::endl;
//	Utils::DrawLine();
//	std::cout << "[몬스터]" << std::endl;
//	std::cout << "이름: " << monster->getName() << ", 레벨: " << monster->getLevel() 
//			  << ", HP: " << monster->getHP() << "/" << monster->getMaxHP() << std::endl;
//	std::cout << "공격력: " << monster->getAttack() << std::endl;
//	Utils::DrawLine();
//		}
