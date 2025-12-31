#include "Character.h"
#include "Item.h"
#include "Monster.h"
#include "Inventory.h"
#include <iostream>
#include <string>
using namespace std;

Character::Character(string name, int hp, int maxHp, int atk, int level, int gold, int exp)
	:m_name(name), m_HP(hp), m_MaxHP(maxHp), m_ATK(atk), m_Level(level), m_Gold(gold), m_EXP(exp), m_Equippeditem(nullptr), m_EquippedThrow(nullptr), m_EXPToLevelUp(100), m_MaxLevel(10)
{
	m_Equippeditem = nullptr;
	m_EquippedThrow = nullptr;

	m_Wepatk = 0;
	m_Throw = false;
	cout << "캐릭터 [" << m_name << "]이(가) 생성되었습니다." << endl;


	if (name.length() < 2) {
	}
	else if (name.length() > 12) {
		m_name = name.substr(0, 12);
	}//닉네임의 글자수 2글자 이상 12글자 이하
}

void Character::showStatus() {
	cout << "--- " << m_name << " (Lv." << m_Level << ") ---" << endl;
	cout << "HP: " << m_HP << " / " << m_MaxHP << endl;
	cout << "코딩력: " << getATK() << " (기본 " << m_ATK << " + 무기 " << m_Wepatk << ")" << endl;
	cout << "경험치: " << m_EXP << " / 100" << endl;
	cout << "보유 골드: " << m_Gold << " G" << endl;
	cout << "-----------------------" << endl;
}


void Character::showEquipment() {
	cout << "[" << m_name << "]의 장비창" << endl;
	cout << "무기: " << (m_Equippeditem ? m_Equippeditem->getName() : "착용중인 무기 없음") << endl;//장비창 UI기능
}
void Character::Equip(Item& item) {
	if (item.getType() == "Weapon") {
		if (m_Equippeditem != nullptr)UnEquip(1);//이미 장착중인 무기가 있다면 현재 장착중인 무기 해제
		m_Equippeditem = &item;
		/* 무기 장착시 공격력 증가 추가 예정*/
		cout << item.getName() << "을(를) 장착했습니다. 코딩력" << /*무기 공격력 변수추가 예정*/  "상승" << endl;
	}
	else if (item.getType() == "Throw") {
		m_EquippedThrow = &item;//투척류
		m_Throw = true;
		cout << item.getName() << "을(를) 장착했습니다." << endl;
	}
}
void Character::UnEquip(int slot) {
	if (slot == 1 && m_Equippeditem != nullptr) {//무기 장착 헤제
		/* 무기 장착 헤제시 무기 공격력 만큼 내려감 추가 예정 */
		cout << m_Equippeditem->getName() << "을(를) 헤제했습니다." << endl;
		m_Equippeditem = nullptr;
		m_Wepatk = 0;
	}
	else if (slot == 2 && m_EquippedThrow != nullptr) {//투척류 장착 해제
		cout << m_EquippedThrow->getName() << "을(를) 헤제했습니다." << endl;
		m_EquippedThrow = nullptr;
		m_Throw = false;
	}
}
void Character::useHealItem() {
	m_HP += 50;//Hp50회복
	if (m_HP > m_MaxHP)m_HP = m_MaxHP;//포션 사용시 최대체력 넘지 않게 설정
}

string Character::getName()const { return m_name; }
int Character::getHP()const { return m_HP; }
int Character::getMaxHP()const { return m_MaxHP; }
int Character::getATK()const { return m_ATK; }
int Character::getEXP()const { return m_EXP; }
int Character::getEXPToLevelUp()const { return m_EXPToLevelUp; }
int Character::getLevel()const { return m_Level; }
int Character::getGold()const { return m_Gold; }

void Character::setHP(int hp) { m_HP = hp; }
void Character::setMaxHP(int maxHp) { m_MaxHP = maxHp; }
void Character::setATK(int atk) { m_ATK = atk; }
void Character::setEXP(int exp) { m_EXP = exp; }
void Character::GainEXP(int amount) {//얻는 경험치
	m_EXP += amount;
	cout << amount << "의 경험치를 얻었습니다. (현재: " << m_EXP << "/100)" << endl;
}
void Character::setLevel(int level) { m_Level = level; }
void Character::setGold(int gold) { m_Gold = gold; }
void Character::GainGold(int amount) {//얻는 골드
	m_Gold += amount;
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
void Character::Attack(Monster& target) {
	if (m_Throw && m_EquippedThrow != nullptr) {//투적 무기 사용
		cout << m_name << "이(가)" << m_EquippedThrow->getName() << "을(를) 던졌습니다!" << endl;
		target.GetHit(m_ATK);
		m_Throw = false;//사용후 비활성화
		m_EquippedThrow = nullptr;
	}
	else {
		cout << m_name << "이(가)" << target.getName() << "을(를) 공격합니다!" << endl;
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