#include "GameManager.h"
#include "MidBoss.h"
#include "Mob.h"
#include "FinalBoss.h"
#include "Utils.h"
#include "Inventory.h"
#include "Windows.h"
#include "Weapon.h"
#include "ThrowingWeapon.h"
#include "HealingPotion.h"
#include <iostream>
#include <cctype>

using namespace std;

GameManager::GameManager(StatusManager* sm, AchievementManager* am): m_SM(sm), m_AM(am),
m_Stage(0), m_Player(nullptr), m_CurrentMonster(nullptr) {

	m_Event = new EventManager();
	m_Shop = new Shop(this);
	m_UI = new UIManager();
}



GameManager::~GameManager() {
	if (m_Player != nullptr) {
		delete m_Player;
		m_Player = nullptr;
	}
	if (m_CurrentMonster != nullptr) {
		delete m_CurrentMonster;
		m_CurrentMonster = nullptr;
	}
	if (m_Event != nullptr) {
		delete m_Event;
		m_Event = nullptr;
	}
	if (m_Shop != nullptr) {
		delete m_Shop;
		m_Shop = nullptr;
	}
}



bool GameManager::DefaultMenuCheck(int choice) { //기본메뉴 체크. 기본메뉴에 대해서는 Utils.cpp 확인
	switch (choice) {
	case 7:
		OpenManageInventory(m_SM, m_Player->getInventory());
		return true;
	case 8:
		ViewCharacterStatus(m_SM);
		return true;
	case 9:
		ViewBattleStatus(m_SM);
		return true;
	case 0:
		ViewAchievements(m_SM);
		return true;
	default:
		return false; // "7,8,9,0 아님
	}
}



void GameManager::RunGame() { // 게임의 전체적인 프로세스 진행
	m_Stage = 1; // 스테이지 초기화


	////인벤토리 테스트 케이스
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("오토바이", 3000, 9999, 1, ItemCategory::Throwing, Rarity::Legendary));
	//m_Player->getInventory()->AddItem(new HealingPotion("쓰리샷 추가한 커피", 55, 45, ItemCategory::HPotion, Rarity::Common));
	//m_Player->getInventory()->AddItem(new Weapon("키보드워리어의 너덜너덜한 키보드였던 것", 10, 10, ItemCategory::Weapon, Rarity::Common));
	//m_Player->getInventory()->AddItem(new HealingPotion("스누피 초코우유", 50, 55, ItemCategory::HPotion, Rarity::Rare));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("분노에 찬 마우스", 40, 40, 1, ItemCategory::Throwing, Rarity::Common));
	//m_Player->getInventory()->AddItem(new Weapon("전설적인 C++ 마스터의 키보드", 500, 50, ItemCategory::Weapon, Rarity::Legendary));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("투척용 플로피디스크", 20, 10, 3, ItemCategory::Throwing, Rarity::Common));
	//m_Player->getInventory()->AddItem(new HealingPotion("빨간 날", 1000, 100, ItemCategory::HPotion, Rarity::Legendary));
	//m_Player->getInventory()->AddItem(new Weapon("독거미 키보드 60% 배열", 30, 30, ItemCategory::Weapon, Rarity::Rare));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("구겨진 음료캔", 20, 30, 2, ItemCategory::Throwing, Rarity::Common));
	//m_Player->getInventory()->AddItem(new HealingPotion("에너지드링크", 40, 50, ItemCategory::HPotion, Rarity::Common));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("찌르기", 50, 30, 3, ItemCategory::Throwing, Rarity::Rare));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("찌르기", 50, 30, 3, ItemCategory::Throwing, Rarity::Rare));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("찌르기", 50, 30, 3, ItemCategory::Throwing, Rarity::Rare));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("찌르기", 50, 30, 3, ItemCategory::Throwing, Rarity::Rare));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("찌르기", 50, 30, 3, ItemCategory::Throwing, Rarity::Rare));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("찌르기", 50, 30, 3, ItemCategory::Throwing, Rarity::Rare));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("찌르기", 50, 30, 3, ItemCategory::Throwing, Rarity::Rare));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("찌르기", 50, 30, 3, ItemCategory::Throwing, Rarity::Rare));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("찌르기", 50, 30, 3, ItemCategory::Throwing, Rarity::Rare));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("찌르기", 50, 30, 3, ItemCategory::Throwing, Rarity::Rare));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("찌르기", 50, 30, 3, ItemCategory::Throwing, Rarity::Rare));
	//m_Player->getInventory()->AddItem(new ThrowingWeapon("찌르기", 50, 30, 3, ItemCategory::Throwing, Rarity::Rare));
	

	while (true) {
		SpawnMonster(m_Stage); // 스테이지 기준 몬스터 생성
		cout << "현재 스테이지: " << m_Stage << endl;
		Sleep(1000);
		Battle(); // 전투
		if (m_Player->getHP() <= 0) { // 플레이어 사망시 게임오버 출력 후 RunGame 종료
			Sleep(1000);
			GameOver();
			Sleep(1000);
			return;
		}
		BattleVictory(); // 전투 승리시 보상 지급 및 상점 or 이벤트
		Sleep(1000);
		m_AM->UpdateAchievements(m_Player, m_SM);
		m_Stage++;
		Sleep(1000);
		if (m_Stage > 21) { // 스테이지가 22이상일 경우(최종보스를 잡았을 경우) 엔딩 출력 후 처음으로
			Sleep(1000);
			Ending();
			Sleep(1000);
			m_AM->UpdateAchievements(m_Player, m_SM);
			Sleep(1000);
			return;
		}
	}
}



void GameManager::SpawnMonster(int stage) {
	if (stage == 21) { // 최종보스
		m_CurrentMonster = new FinalBoss();
	}
	else if (stage % 5 == 0) { // 중간보스
		int midBossId = stage / 5;
		m_CurrentMonster = new MidBoss(midBossId);
	}
	else if (stage < 21) { // 일반몹
		m_CurrentMonster = Mob::createRandomMonster(m_Player);
	}
	else {
		cout << "**예상치 못한 오류가 발생하였습니다. stage를 1로 리셋하고 일반 몬스터를 소환합니다.**" << endl;
		m_Stage = 1;
		m_CurrentMonster = Mob::createRandomMonster(m_Player);
	} // stage가 범위 밖일 경우 : 치명적 오류!
}



void GameManager::Battle() { // 전투 판정. 몹 또는 플레이어의 체력이 0이 될때까지 반복 루프
	system("cls");
	if (m_Stage % 5 == 0) cout << "앗! 갑자기 실력 점검으로" << m_CurrentMonster->getName() << " 님이 등장했다!!!" << endl;
	else if (m_Stage == 21) m_UI->FinalBossAppearance();
	else cout << "앗! 오늘의 코드카타로 " << m_CurrentMonster->getName() << "이(가) 문제로 나왔다!" << endl;
	Sleep(2000);
	m_UI->RenderBattleScreen(m_Player, m_CurrentMonster);
	while (true) { // 둘중 하나의 체력이 0이 될때까지 반복
		if (m_Player->getHP() <= 0) break;
		m_Player->Attack(m_CurrentMonster);
		m_UI->RenderBattleScreen(m_Player, m_CurrentMonster);
		Sleep(300);
		if (m_CurrentMonster->getHP() <= 0) break;
		m_CurrentMonster->attack(m_Player);
		m_UI->RenderBattleScreen(m_Player, m_CurrentMonster);
		Sleep(2000);
	}

}



void GameManager::BattleVictory() { // 전투승리시
	cout << "\n이겼다! 오늘도 열심히 공부했다!\n" << endl;
	if (m_Stage < 21) {
		m_Player->setEXP(m_Player->getEXP() + m_CurrentMonster->getDropEXP());
		m_Player->setGold(m_Player->getGold() + m_CurrentMonster->getDropGold());
		m_Player->LevelUp();
		Item* dropitem = m_CurrentMonster->dropItem();
		if (dropitem != nullptr) m_Player->getInventory()->AddItem(dropitem);
		m_SM->AddKill(m_CurrentMonster->getName());
		delete m_CurrentMonster; // 현재 몬스터 삭제
		m_CurrentMonster = nullptr;
		Sleep(1000);
		m_AM->UpdateAchievements(m_Player, m_SM);
	}
	Utils::WaitForKeypress();
	while (m_Stage < 21) { // 선택지. 최종보스 이하 스테이지일때만 나오게
		system("cls");
		cout << "다음 공부를 하기전에 뭘 할까? (둘 중 하나만 선택 가능)" << endl;
		cout << "==================================" << endl;	
		cout << "1. 상점으로" << endl;
		cout << "2. 시간을 때운다(무작위 이벤트)" << endl;
		cout << "==================================" << endl;
		int select = Utils::DefaultMenu(); // 기본 선택지 아래에 기본메뉴 표시 + 안전한 입력 받음
		if (GameManager::DefaultMenuCheck(select)) { // 기본 선택지를 골랐으면 while문 반복
			continue;
		}
		if (select == 1) { // 상점이나 이벤트 골라서 진행
			VisitShop();
			break;
		}
		else if (select == 2) {
			VisitEvent();
			break;
		}
		else { // 범위 외 입력 감지시 다시
			cout << "잘못된 입력입니다." << endl;
		}
	}
}



void GameManager::GameOver() {
	cout << "당신은 주겄슴다 ㅡㅡ;" << endl;
}



void GameManager::VisitShop() {
	m_Shop->ShopSelect(m_Player);
}



void GameManager::VisitEvent() {
	m_Event->StartEvent(m_Player, this);
}



void GameManager::Opening() {
	m_UI->Mainscreen();
	m_UI->OpeningScene();
	string name;
	while (true) { // 이름 유효성 검사 프로세스
		cout << ">> 이름을 입력하세요 (특수문자/공백 불가, 12글자 이내): ";
		getline(cin, name);
		if (cin.fail()) { // 모종의 사유로 cin이 fail했을 때
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "잘못된 입력입니다." << endl;
			continue;
		}
		if (name.length() > 12) { // 길이가 너무 길 때
			cout << "이름이 너무 깁니다. 12글자 이내로 해주세요." << endl;
			continue;
		}
		bool isValid = true;
		for (char c : name) {
			if ((unsigned char)c < 128) { // char를 unsigned char로 변환했을때 128 이하면 숫자, 영어, 특문 중 하나임
				if (isalnum(c) == 0) { // cctype 라이브러리의 isalnum(알파벳이나 숫자인지) 확인
					isValid = false;
					break;
				}
			}
			else {
				continue;
			}
		}
		if (!isValid) { // 위에서 한 특문검사 체크
			cout << "특수문자 또는 공백은 사용할 수 없습니다." << endl;
		}
		if (name == "") { // 빈 문자열 검사
			cout << "이름을 입력해주세요." << endl;
		}
		else {
			break;
		}
	}
	m_Player = new Character(name); // 캐릭터 생성
	cout << "당신의 캐릭터 " << name << "이(가) 생성되었습니다!" << endl;
	Sleep(1000);
}



void GameManager::Ending() {
	m_UI->EndingScene();
	cout << "YOU WIN!" << endl; // 임시
}



void GameManager::ViewCharacterStatus(StatusManager* sm) {
	sm->DisplayCharacterStatus(m_Player);
}



void GameManager::ViewBattleStatus(StatusManager* sm) {
	sm->DisplayBattleStatus();
}



void GameManager::ViewAchievements(StatusManager* sm) {
	sm->DisplayAchievements(m_AM);
}



void GameManager::OpenManageInventory(StatusManager* sm, Inventory* Inv) {
	Inv->ManageInventory(sm, m_Player);
}



