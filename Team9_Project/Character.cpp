#include "Character.h"
#include "Item.h"
#include "Monster.h"
#include "Inventory.h"
#include "HealingPotion.h"
#include "Potion.h"
#include "BuffPotion.h"
#include <iostream>
#include <string>
using namespace std;
Character::Character(string name, int hp, int maxHp, int atk, int level, int gold, int exp)
	:m_name(name), m_HP(hp), m_MaxHP(maxHp), m_ATK(atk), m_Level(level), m_Gold(gold), m_EXP(exp), m_EXPToLevelUp(100), m_MaxLevel(10), m_Wepatk(0), m_Throw(false), m_Alive(true)
{
	m_Equippeditem = nullptr;
	m_EquippedThrow = nullptr;
	m_Inventory = new Inventory(20); // 임시로 생성자에 20칸의 인벤토리를 넣었습니다

	m_Wepatk = 0;
	m_Throw = false;
	cout << "캐릭터 [" << m_name << "]이(가) 생성되었습니다." << endl;
	if (name.length() < 2) {
	}
	else if (name.length() > 12) {
		m_name = name.substr(0, 12);
	}//닉네임의 글자수 2글자 이상 12글자 이하
}
Character::~Character() {
	if (m_Inventory != nullptr) {
		delete m_Inventory;
		m_Inventory = nullptr;
	}
}//동적할당 메모리누수 방지
bool Character::isAlive() const {
	return m_Alive;
}
void Character::showStatus() {
	cout << "--- " << m_name << " (Lv." << m_Level << ") ---" << endl;
	cout << "HP: " << m_HP << " / " << m_MaxHP << endl;
	cout << "코딩력: " << getATK() << " (기본 " << m_ATK << " + 무기 " << m_Wepatk << ")" << endl;
	cout << "경험치: " << m_EXP << " / 100" << endl;
	cout << "보유 골드: " << m_Gold << " G" << endl;
	cout << "-----------------------" << endl;
}
void Character::usePotion(Potion& potion)
{
	if (potion.getType() == "회복포션")
	{
		m_HP += potion.getEffectAmount();
		if (m_HP > m_MaxHP) m_HP = m_MaxHP;
		cout << m_name << "이(가)" << potion.getName() << "을 사용하여 HP를 " << potion.getEffectAmount() << "회복했습니다. (현재 HP: " << m_HP << " ) " << endl;
	}
}
void Character::manageEquipment(int action, Item* item, int slot)
{
	switch (action)
	{
	case 0:
		cout << "[" << m_name << "]의 장비창" << endl;
		cout << "무기: " << (m_Equippeditem ? m_Equippeditem->getName() : "착용중인 무기 없음") << endl;
		cout << "투척류: " << (m_EquippedThrow ? m_EquippedThrow->getName() : "착용중인 투척류 없음") << endl;
		break;
	case 1:
		if (item != nullptr)
		{
			if (item->getType() == "Weapon")
			{
				if (m_Equippeditem != nullptr) manageEquipment(2, nullptr, 1);
				m_Equippeditem = item;
				m_Wepatk = item->getAttack();
				cout << item->getName() << "을(를) 장착했습니다." << endl;
			}
			else if (item->getType() == "Throw")
			{
				m_EquippedThrow = item;
				m_Throw = true;
				cout << item->getName() << "을(를) 장착했습니다." << endl;
			}
		}
		break;
	case 2:
		if (slot == 1 && m_Equippeditem != nullptr)
		{
			cout << m_Equippeditem->getName() << "을(를) 해제했습니다" << endl;
			m_Equippeditem = nullptr;
			m_Wepatk = 0;
		}
		else if (slot == 2 && m_EquippedThrow != nullptr)
		{
			cout << m_EquippedThrow->getName() << "을(를) 해제했습니다" << endl;
			m_EquippedThrow = nullptr;
			m_Throw = false;
		}
		break;
	}
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
void Character::setHP(int hp) { m_HP = hp; }
void Character::setMaxHP(int maxHp) { m_MaxHP = maxHp; }
void Character::setATK(int atk) { m_ATK = atk; }
void Character::setEXP(int exp) { m_EXP = exp; }
void Character::GainEXP(int amount) {//얻는 경험치
	m_EXP += amount;
	cout << amount << "의 경험치를 얻었습니다. (현재: " << m_EXP << "/100)" << endl;
	LevelUp();
}
void Character::setLevel(int level) { m_Level = level; }
void Character::setGold(int gold) { m_Gold = gold; }
void Character::GainGold(int amount) {//얻는 골드
	m_Gold += amount;
	if (m_Gold < 0) {
		m_Gold = 0;//zep코인 음수 방지
	}
	cout << "Zep코인을" << amount << "획득했습니다!(보유 Zep코인: " << m_Gold << "Zep 코인)" << endl;
}
void Character::LevelUp() {
	if (m_Level < m_MaxLevel && m_EXP >= m_EXPToLevelUp) {
		m_Level++;
		m_MaxHP += m_Level * 20;//체력 레벨 x 20
		m_ATK += m_Level * 5;//공격력 레벨 x 5
		m_HP = m_MaxHP;//레벨업시 풀피
		m_EXP = 0;
		m_EXPToLevelUp = 100;
		if (m_Level == m_MaxLevel) {
			cout << "이제 일반 몬스터는 상대도 안된다." << endl;//만렙 달성시 대사
		}
		else {
			cout << "레벨 업! 현재 레벨:" << m_Level << endl;//레벨업시 대사
		}
	}
}
void Character::Attack(Monster* target) {
	if (m_Throw && m_EquippedThrow != nullptr) {//투적 무기 사용
		cout << m_name << "이(가)" << m_EquippedThrow->getName() << "을(를) 던졌습니다!" << endl;
		target->GetHit(m_ATK + m_EquippedThrow->getAttack());//투척무기 자체 피해량 적용
		m_Throw = false;//사용후 비활성화
		m_EquippedThrow = nullptr;
	}
	else {
		cout << m_name << "이(가)" << target->getName() << "을(를) 공격합니다!" << endl;
		target->GetHit(getATK());//캐릭터의 기본공격력 + 무기 공격력 포함
	}
}
void Character::GetHit(int damage) {
	m_HP -= damage;
	if (m_HP < 0) m_HP = 0;//캐릭터 체력 음수 방지
	cout << m_name << "이(가)" << damage << "의 피해를 입었습니다. (남은 HP: " << m_HP << ")" << endl;
	if (m_HP == 0) {
		cout << m_name << "이(가) 사망하였습니다." << endl;
	}
}