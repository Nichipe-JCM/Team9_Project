#include "Character.h"
#include "Item.h"
#include "Monster.h"
#include "Inventory.h"
#include "HealingPotion.h"
#include "Potion.h"
#include "BuffPotion.h"
#include "Utils.h"
#include "Windows.h"
#include <iostream>
#include <string>
using namespace std;

Character::Character(string name, int hp, int maxHp, int atk, int level, int gold, int exp)
	:m_name(name), m_HP(hp), m_MaxHP(maxHp), m_ATK(atk), m_Level(level), m_Gold(gold), m_EXP(exp),
	m_EXPToLevelUp(100), m_MaxLevel(10), m_Wepatk(0), m_Throw(false), m_Alive(true),
	m_Equippeditem(nullptr), m_EquippedThrow(nullptr), m_EquippedPotion(nullptr), m_HasPotion(false)
{
	m_Inventory = new Inventory(20);
	cout << "캐릭터 [" << m_name << "]이(가) 생성되었습니다." << endl;

	if (name.length() > 12) {
		m_name = name.substr(0, 12);
	} // 닉네임 글자수 제한
}

Character::~Character() {
	if (m_Inventory != nullptr) {
		delete m_Inventory;
		m_Inventory = nullptr;
	}
}

bool Character::isAlive() const { return m_Alive; }

void Character::showStatus() {
	cout << "--- " << m_name << " (Lv." << m_Level << ") ---" << endl;
	cout << "HP: " << m_HP << " / " << m_MaxHP << endl;
	cout << "코딩력: " << getATK() << " (기본 " << m_ATK << " + 무기 " << m_Wepatk << ")" << endl;
	cout << "경험치: " << m_EXP << " / 100" << endl;
	cout << "보유 골드: " << m_Gold << " G" << endl;
	cout << "-----------------------" << endl;
}

void Character::usePotion(Potion* potion) {
	if (potion->getItemType() == ItemCategory::HPotion) {
		m_HP += potion->getEffectAmount();
		if (m_HP > m_MaxHP) {
			int overheal = m_HP - m_MaxHP;
			m_HP = m_MaxHP;
			cout << m_name << "이(가) " << Color::OLIVE << potion->getName()
				<< "을 사용하여" << Color::LIME <<  "HP를 " << potion->getEffectAmount() - overheal
				<< " 회복했습니다. "<< Color::CRIMSON << "(현재 HP : " << m_HP << ")" <<Color::RESET << endl;
		}
		else {
			cout << Color::WHITE << m_name << "이(가) " << potion->getName()
				<< "을 사용하여"<<Color::LIME << "HP를" << potion->getEffectAmount()
				<< " 회복했습니다."<<Color::CRIMSON << "(현재 HP : " << m_HP << ")" <<Color::RESET<< endl;
		}
	}
	else if (potion->getItemType() == ItemCategory::BPotion) {
		m_ATK += potion->getEffectAmount();
		cout <<Color::WHITE << m_name << "이(가) " <<Color::RESET<< Color::GOLD << potion->getName()
			<< "을(를) 사용하여"<<Color::RESET<<Color::PURPLE << "코딩력이 " << potion->getEffectAmount()
			<< " 증가했습니다."<<Color::RESET <<Color::LAVENDER<< "(현재 코딩력 : " << m_ATK << ")" <<Color::RESET<< endl;
	}
}

void Character::manageEquipment(int action, Item* item, int slot) {
	switch (action) {
	case 0:
		cout <<Color::SILVER<< "[" << m_name << "]의 장비창" <<Color::RESET<< endl;
		cout << "무기: " << (m_Equippeditem ? m_Equippeditem->getName() : "착용중인 무기 없음") << endl;
		cout << "투척류: " << (m_EquippedThrow ? m_EquippedThrow->getName() : "착용중인 투척류 없음") << endl;
		cout <<Color::OLIVE<<"포션: " << (m_EquippedPotion ? m_EquippedPotion->getName() : "착용중인 포션 없음") <<Color::RESET<< endl;
		break;

	case 1:
		if (item != nullptr) {
			if (item->getItemType() == ItemCategory::Weapon) {
				if (m_Equippeditem != nullptr) {
					cout << "장착중인 " << m_Equippeditem->getName() << "을(를) 해제했습니다." << endl;
					m_Equippeditem->setEquipped(false);
					m_Equippeditem = nullptr;
					m_Wepatk = 0;
				}
				m_Equippeditem = item;
				m_Wepatk = item->getAttack();
				cout << item->getName() << "을(를) 장착했습니다." << endl;
				item->setEquipped(true);
			}
			else if (item->getItemType() == ItemCategory::Throwing) {
				if (m_EquippedThrow != nullptr) {
					cout << "장착중인 " << m_EquippedThrow->getName() << "을(를) 해제했습니다." << endl;
					m_EquippedThrow->setEquipped(false);
					m_EquippedThrow = nullptr;
					m_Throw = false;
				}
				m_EquippedThrow = item;
				m_Throw = true;
				cout << item->getName() << "을(를) 장착했습니다." << endl;
				item->setEquipped(true);
			}
			else if (item->getItemType() == ItemCategory::HPotion) {
				cout <<Color::OLIVE<< "체력 포션" <<Color::RESET << "을 어떻게 하시겠습니까?" << endl;
				cout << "1. 포션 슬롯에 장착  2. 포션 즉시 사용" << endl;
				int choice = Utils::GetSafeInput();

				if (choice == 2) {
					if (m_HP == m_MaxHP) {
						cout <<Color::LIME << "체력" <<Color::RESET<< "이 가득 차 있습니다." <<Color::OLIVE<<"포션을 사용할 수 없습니다."<<Color::RESET << endl;
						break;
					}
					usePotion(dynamic_cast<Potion*>(item));
					m_Inventory->RemoveItemFromPointer(item);
					break;
				}
				if (choice == 1) {
					if (m_EquippedPotion != nullptr) {
						cout << "장착중인 " << m_EquippedPotion->getName() << "을(를) 해제했습니다." << endl;
						m_EquippedPotion->setEquipped(false);
						m_EquippedPotion = nullptr;
						m_HasPotion = false;
					}
					m_EquippedPotion = item;
					m_HasPotion = true;
					cout << item->getName()
						<< "을(를)"<<Color::OLIVE<< "포션 슬롯에 장착했습니다."<<Color::RESET << "(전투 중 "<<Color::CRIMSON<<"HP 50 % 이하일 때" <<Color::RESET << "자동 사용)"<< endl;
					item->setEquipped(true);
					break;
				}
				else {
					cout << "잘못된 선택입니다." << endl;
					break;
				}
			}
		}
		break;

	case 2:
		if (slot == 1 && m_Equippeditem != nullptr) {
			cout << m_Equippeditem->getName() << "을(를) 해제했습니다." << endl;
			m_Equippeditem->setEquipped(false);
			m_Equippeditem = nullptr;
			m_Wepatk = 0;
		}
		else if (slot == 2 && m_EquippedThrow != nullptr) {
			cout << m_EquippedThrow->getName() << "을(를) 해제했습니다." << endl;
			m_EquippedThrow->setEquipped(false);
			m_EquippedThrow = nullptr;
			m_Throw = false;
		}
		else if (slot == 3 && m_EquippedPotion != nullptr) {
			cout << m_EquippedPotion->getName() << "을(를) 해제했습니다." << endl;
			m_EquippedPotion->setEquipped(false);
			m_EquippedPotion = nullptr;
			m_HasPotion = false;
		}
		break;
	}
}

bool Character::AutoUsePotion(Potion* potion) {//체력 50%이하일경우 포션 사용
	if (m_HP > 0 && m_HP <= m_MaxHP * 0.5 && m_HasPotion) {
		Potion* equippedPotion = dynamic_cast<Potion*>(m_EquippedPotion);
		if (equippedPotion != nullptr && equippedPotion->getType() == "회복포션") {
			usePotion(equippedPotion);
			m_EquippedPotion = nullptr;
			m_HasPotion = false;
			return true; //턴 소모후 포션 사용
		}
	}
	return false;//포션을 사용하지 않음
}

string Character::getName()const { return m_name; }
int Character::getHP()const { return m_HP; }
int Character::getMaxHP()const { return m_MaxHP; }
int Character::getATK()const { return m_ATK + m_Wepatk; }
int Character::getEXP()const { return m_EXP; }
int Character::getEXPToLevelUp()const { return m_EXPToLevelUp; }
int Character::getLevel()const { return m_Level; }
int Character::getGold()const { return m_Gold; }
Inventory* Character::getInventory()const { return m_Inventory; } // 신규 함수
Item* Character::getEquippeditem() { return m_Equippeditem; }
Item* Character::getEquippedThrow() { return m_EquippedThrow; }
Item* Character::getEquippedPotion() { return m_EquippedPotion; }


void Character::setHP(int hp) {
	if (hp < 0) hp = 0;//음수 방지
	if (hp > m_MaxHP) hp = m_MaxHP;//최대 HP 초과 방지
	m_HP = hp;
}
void Character::setMaxHP(int maxHp) { m_MaxHP = maxHp; }
void Character::setATK(int atk) { m_ATK = atk; }
void Character::setEXP(int exp) { m_EXP = exp; }



void Character::GainEXP(int amount) {//얻는 경험치
	m_EXP += amount;
	cout <<Color::YELLOW << amount << "의 경험치를 얻었습니다." <<Color::RESET<<Color::BG_BRIGHT_YELLOW << "(현재: " << m_EXP << " / 100)" <<Color::RESET<< endl;
	LevelUp();
}
void Character::setLevel(int level) { m_Level = level; }
void Character::setGold(int gold) { m_Gold = gold; }
void Character::GainGold(int amount) {//얻는 zep코인
	m_Gold += amount;
	if (m_Gold < 0) {
		m_Gold = 0;//zep코인 음수 방지
	}
	cout <<Color::BEIGE << " Zep코인을 " << amount << " 획득했습니다! (보유 Zep코인: " << m_Gold << "Zep 코인)" <<Color::RESET << endl;
}
void Character::LevelUp() {
	while (m_EXP >= m_EXPToLevelUp){
		if (m_Level < m_MaxLevel) {
			m_Level++;
			m_MaxHP += m_Level * 20;//체력 레벨 x 20
			m_ATK += m_Level * 5;//공격력 레벨 x 5
			m_HP = m_MaxHP;//레벨업시 풀피
			m_EXP -= m_EXPToLevelUp;//초과 되는 경험치 다음 레벨에 유지
			m_EXPToLevelUp = 100;
			if (m_Level == m_MaxLevel) {
				cout << "이제 일반 몬스터는 상대도 안된다." << endl;//만렙 달성시 대사
			}
			else {
				cout <<Color::GREEN << "레벨 업! 현재 레벨:" << m_Level <<Color::RESET << endl;//레벨업시 대사
			}
		}
		else {
			break;
		}
	}
	Sleep(1000);
}
void Character::Attack(Monster* target) {
	if (AutoUsePotion(dynamic_cast<Potion*>(m_EquippedPotion))) {
		cout << m_name << "은(는) 이번 턴에" <<Color::OLIVE << "포션을 사용했습니다!" <<Color::RESET<< endl;
		return;
	}

	if (m_Throw && m_EquippedThrow != nullptr) {//투적 무기 사용
		cout << m_name << "이(가)" << target->getName() << "에게" << m_EquippedThrow->getName() << "을(를) 던졌습니다!" << endl;
		Sleep(300);
		target->GetHit(m_ATK + m_EquippedThrow->getAttack());//투척무기 자체 피해량 적용
		m_Throw = false;//사용후 비활성화
		m_Inventory->RemoveItemFromPointer(m_EquippedThrow);//인벤토리에서 제거
		m_EquippedThrow = nullptr;
	}
	else {
		cout << m_name << "이(가)" << target->getName() << "을(를) 공격합니다!" << endl;
		Sleep(300);
		target->GetHit(getATK());//캐릭터의 기본공격력 + 무기 공격력 포함
	}
}
void Character::GetHit(int damage) {
	m_HP -= damage;
	if (m_HP < 0) m_HP = 0;//캐릭터 체력 음수 방지
	cout << m_name << "이(가)" << damage << "의 피해를 입었습니다." << Color::RED << "(남은 HP : " << m_HP << ")" << Color::RESET << endl;
	if (m_HP == 0) {
		m_Alive = false; //사망처리
		cout << m_name << "이(가) 사망하였습니다." << endl;
	}
}
