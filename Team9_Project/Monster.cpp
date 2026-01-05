#include "Monster.h"
#include "Character.h"
#include "Weapon.h"
#include "ThrowingWeapon.h"
#include "HealingPotion.h"
#include "BuffPotion.h"
#include "CashableItem.h"
#include "Windows.h"

#include <iostream>
#include <string>
#include <random>
#include <map>
#include <ctime>    

using namespace std;


Monster::Monster(const string& name, int level, int gold, int exp)
	: name(name), m_dropGold(gold), m_dropEXP(exp), isAlive(true)
{

	static random_device rd;
	static mt19937 gen(rd());


	uniform_int_distribution<int> hpDist(level * 20, level * 30);
	m_HP = hpDist(gen);

	uniform_int_distribution<int> atkDist(level * 5, level * 10);
	m_ATK = atkDist(gen);

	m_MaxHP = m_HP;
	m_Level = level;
}

void Monster::attack(Character* target)
{
	cout << name << "이(가)" << target->getName() << "을(를) 공격합니다!" << endl;
	Sleep(300);
	// player->gethit(m_atk)
	if (target != nullptr) {
		target->GetHit(m_ATK);
	}
}

void Monster::GetHit(int damage) // checkDeath 추가
{
	m_HP -= damage;
	if (m_HP < 0) m_HP = 0;
	cout << name << "이(가)" << damage << "의 피해를 입었습니다. (남은 HP: " << m_HP << ")" << endl;

	checkDeath(); // 해치웠나?
}

// 해치웠나? 의 몸통
bool Monster::checkDeath() {
	if (m_HP <= 0) {
		isAlive = false;
		Sleep(1000);
		cout << name << "이(가) 쓰러졌다!" << endl;
		Sleep(1000);
		cout << m_dropGold << " 골드와 " << m_dropEXP << " 경험치를 획득했다!" << endl;
		Sleep(1000);
		return true;
	}
	return false;
}



// 레어리티에 따른 드랍확률
double getDefaultDropRate(Rarity rarity)
{
	switch (rarity)
	{
	case Rarity::Common: return 0.3;   // 30%
	case Rarity::Rare: return 0.1;     // 10%
	case Rarity::Epic: return 0.05;    // 5%
	case Rarity::Legendary: return 0.01; // 1%
	}
	return 0.0;
}

// 드랍 테이블
// weapon - value / damage
// throwA - value / damage / quantity
// healing- value / healamount
// buffing- value / buffamount
// cashAb - value
static map<string, vector<DropEntry*>> monsterDrops =
{
	{"포인터", {
		new DropEntry(
			new Weapon("키보드워리어의 너덜너덜한 키보드였던 것", 10, 10, ItemCategory::Weapon, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Weapon
		),
		new DropEntry(
			new CashableItem("지폐", 77, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new CashableItem("500원 동전", 50, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new HealingPotion("쓰리샷 추가한 커피", 55, 45, ItemCategory::HPotion, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::HPotion
		),
		new DropEntry(
			new CashableItem("길가다 주운 복권", 10000, ItemCategory::Cash, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Cash
		),
		new DropEntry(
			new BuffPotion("코딩애플 숏츠", 20, 10, ItemCategory::BPotion, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::BPotion
		),
		new DropEntry(
			new Weapon("전설적인 C++ 마스터의 키보드", 500, 50, ItemCategory::Weapon, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Weapon
		),
	}},

	{"레퍼런스", {
		new DropEntry(
			new Weapon("키보드워리어의 너덜너덜한 키보드였던 것", 10, 10, ItemCategory::Weapon, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Weapon
		),
		new DropEntry(
			new CashableItem("지폐", 77, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new CashableItem("500원 동전", 50, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new HealingPotion("쓰리샷 추가한 커피", 55, 45, ItemCategory::HPotion, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::HPotion
		),
		new DropEntry(
			new BuffPotion("코딩애플 숏츠", 20, 10, ItemCategory::BPotion, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::BPotion
		),
		new DropEntry(
			new CashableItem("길가다 주운 복권", 10000, ItemCategory::Cash, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Cash
		),
		new DropEntry(
			new ThrowingWeapon("투척용 플로피디스크", 20, 10, 3, ItemCategory::Throwing, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Throwing
		),
		new DropEntry(
			new Weapon("전설적인 C++ 마스터의 키보드", 500, 50, ItemCategory::Weapon, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Weapon
		)
	}},

	{"템플릿", {
		new DropEntry(
			new Weapon("독거미 키보드 60% 배열", 30, 30, ItemCategory::Weapon, Rarity::Rare),
			Rarity::Rare,
			getDefaultDropRate(Rarity::Rare),
			ItemCategory::Weapon
		),
		new DropEntry(
			new CashableItem("지폐", 77, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new CashableItem("500원 동전", 50, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new HealingPotion("에너지드링크", 40, 50, ItemCategory::HPotion, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::HPotion
		),
		new DropEntry(
			new ThrowingWeapon("구겨진 음료캔", 20, 30, 2, ItemCategory::Throwing, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Throwing
		),
		new DropEntry(
			new CashableItem("길가다 주운 복권", 10000, ItemCategory::Cash, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Cash
		),
		new DropEntry(
			new Weapon("전설적인 C++ 마스터의 키보드", 500, 50, ItemCategory::Weapon, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Weapon
		)
	}},

	{ "변수", {
		new DropEntry(
			new Weapon("독거미 키보드 60% 배열", 30, 30, ItemCategory::Weapon, Rarity::Rare),
			Rarity::Rare,
			getDefaultDropRate(Rarity::Rare),
			ItemCategory::Weapon
		),
		new DropEntry(
			new CashableItem("지폐", 77, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new CashableItem("500원 동전", 50, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new HealingPotion("에너지드링크", 40, 50, ItemCategory::HPotion, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::HPotion
		),
		new DropEntry(
			new ThrowingWeapon("구겨진 음료캔", 20, 30, 2, ItemCategory::Throwing, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Throwing
		),
		new DropEntry(
			new CashableItem("길가다 주운 복권", 10000, ItemCategory::Cash, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Cash
		),
		new DropEntry(
			new Weapon("전설적인 C++ 마스터의 키보드", 500, 50, ItemCategory::Weapon, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Weapon
		)
	} },

	{ "함수", {
		new DropEntry(
			new Weapon("독거미 키보드 60% 배열", 30, 30, ItemCategory::Weapon, Rarity::Rare),
			Rarity::Rare,
			getDefaultDropRate(Rarity::Rare),
			ItemCategory::Weapon
		),
		new DropEntry(
			new CashableItem("지폐", 77, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new CashableItem("500원 동전", 50, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new ThrowingWeapon("구겨진 음료캔", 20, 30, 2, ItemCategory::Throwing, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Throwing
		),
		new DropEntry(
			new CashableItem("길가다 주운 복권", 10000, ItemCategory::Cash, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Cash
		),
		new DropEntry(
			new Weapon("전설적인 C++ 마스터의 키보드", 500, 50, ItemCategory::Weapon, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Weapon
		)
	} },


	{ "배열", {
		new DropEntry(
			new Weapon("독거미 키보드 60% 배열", 30, 30, ItemCategory::Weapon, Rarity::Rare),
			Rarity::Rare,
			getDefaultDropRate(Rarity::Rare),
			ItemCategory::Weapon
		),
		new DropEntry(
			new CashableItem("지폐", 77, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new CashableItem("500원 동전", 50, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new ThrowingWeapon("구겨진 음료캔", 20, 30, 2, ItemCategory::Throwing, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Throwing
		),
		new DropEntry(
			new CashableItem("길가다 주운 복권", 10000, ItemCategory::Cash, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Cash
		),
		new DropEntry(
			new Weapon("전설적인 C++ 마스터의 키보드", 500, 50, ItemCategory::Weapon, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Weapon
		)
	} },

	{ "알고리즘", {
		new DropEntry(
			new Weapon("독거미 키보드 60% 배열", 30, 30, ItemCategory::Weapon, Rarity::Rare),
			Rarity::Rare,
			getDefaultDropRate(Rarity::Rare),
			ItemCategory::Weapon
		),
		new DropEntry(
			new CashableItem("지폐", 77, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new CashableItem("500원 동전", 50, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new ThrowingWeapon("분노에 찬 마우스", 40, 40, 1, ItemCategory::Throwing, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common), ItemCategory::Throwing
		),
		new DropEntry(
			new CashableItem("길가다 주운 복권", 10000, ItemCategory::Cash, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Cash
		),
		new DropEntry(
			new Weapon("전설적인 C++ 마스터의 키보드", 500, 50, ItemCategory::Weapon, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Weapon
		)
	} },


	{ "객체", {
		new DropEntry(
			new Weapon("독거미 키보드 60% 배열", 30, 30, ItemCategory::Weapon, Rarity::Rare),
			Rarity::Rare,
			getDefaultDropRate(Rarity::Rare),
			ItemCategory::Weapon
		),
		new DropEntry(
			new CashableItem("지폐", 77, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new CashableItem("500원 동전", 50, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new ThrowingWeapon("구겨진 음료캔", 20, 30, 2, ItemCategory::Throwing, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Throwing
		),
		new DropEntry(
			new CashableItem("길가다 주운 복권", 10000, ItemCategory::Cash, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Cash
		),
		new DropEntry(
			new Weapon("전설적인 C++ 마스터의 키보드", 500, 50, ItemCategory::Weapon, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Weapon
		)
	} },

	{ "부동소수점", {
		new DropEntry(
			new Weapon("독거미 키보드 60% 배열", 30, 30, ItemCategory::Weapon, Rarity::Rare),
			Rarity::Rare,
			getDefaultDropRate(Rarity::Rare),
			ItemCategory::Weapon
		),
		new DropEntry(
			new CashableItem("지폐", 77, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new CashableItem("500원 동전", 50, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Cash
		),
		new DropEntry(
			new ThrowingWeapon("구겨진 음료캔", 20, 30, 2, ItemCategory::Throwing, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common),
			ItemCategory::Throwing
		),
		new DropEntry(
			new CashableItem("길가다 주운 복권", 10000, ItemCategory::Cash, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Cash
		),
		new DropEntry(
			new Weapon("전설적인 C++ 마스터의 키보드", 500, 50, ItemCategory::Weapon, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary),
			ItemCategory::Weapon
		)
	} },

	{ "클래스", {
		new DropEntry(
			new Weapon("독거미 키보드 60% 배열", 30, 30, ItemCategory::Weapon, Rarity::Rare),
			Rarity::Rare,
			getDefaultDropRate(Rarity::Rare), ItemCategory::Weapon),
		new DropEntry(
			new CashableItem("지폐", 77, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common), ItemCategory::Cash),
		new DropEntry(
			new CashableItem("500원 동전", 50, ItemCategory::Cash, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common), ItemCategory::Cash),
		new DropEntry(
			new ThrowingWeapon("분노에 찬 마우스", 40, 40, 1, ItemCategory::Throwing, Rarity::Common),
			Rarity::Common,
			getDefaultDropRate(Rarity::Common), ItemCategory::Throwing),
		new DropEntry(
			new CashableItem("길가다 주운 복권", 10000, ItemCategory::Cash, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary), ItemCategory::Cash),
		new DropEntry(
			new Weapon("전설적인 C++ 마스터의 키보드", 500, 50, ItemCategory::Weapon, Rarity::Legendary),
			Rarity::Legendary,
			getDefaultDropRate(Rarity::Legendary), ItemCategory::Weapon)
	}}
};




// 카테고리별... 출력..
void printDropsByCategory(const string& monsterName, ItemCategory category)
{
	auto it = monsterDrops.find(monsterName);
	if (it == monsterDrops.end()) return;

	cout << monsterName << "의 " << (category == ItemCategory::Weapon ? "무기" :
		category == ItemCategory::Throwing ? "투척무기" :
		category == ItemCategory::HPotion ? "회복포션" :
		category == ItemCategory::BPotion ? "버프아이템" :
		"환금아이템")
		<< "드랍 목록 :" << endl;

	for (const auto& drop : it->second)
	{
		if (drop->item->getItemType() == category)
		{
			cout << " - " << drop->item->getRarityColor(drop->item->getRarity())
				<< drop->item->getName()
				<< "\033[0m" << endl;
		}
	}
}



// 드랍 아이템 결정
Item* getRandomDrop(const string& monsterName) {
	auto it = monsterDrops.find(monsterName);
	if (it == monsterDrops.end()) return nullptr;

	// 난수 생성기
	static random_device rd;
	static mt19937 gen(rd());
	// uniform_real_distribution<> dis(0.0, 1.0);

	for (const auto& drop : it->second) {
		bernoulli_distribution dist(drop->dropRate);
		if (dist(gen)) {
			return drop->item;
		}
	}
	return nullptr;
}


Item* Monster::dropItem() {
	auto it = monsterDrops.find(name);
	if (it == monsterDrops.end()) return nullptr;

	static random_device rd;
	static mt19937 gen(rd());

	
	uniform_int_distribution<int> out(1, 100);
	int getout = out(gen);
	if (getout >= 31) {
		cout << "이겼지만 아무것도 나오지 않았다...\n";
		return nullptr;
	}

	double total = 0.0;
	for (auto& d : it->second) total += d->dropRate;

	uniform_real_distribution<> dist(0.0, total);
	double roll = dist(gen);

	double acc = 0.0;
	for (auto& d : it->second) {
		acc += d->dropRate;
		if (roll <= acc) {
			cout << name << "이(가) "
				<< d->item->getRarityColor(d->rarity)
				<< d->item->getName()
				<< "\033[0m 을 드랍했다!\n";
			return d->item;
		}
	}
	return nullptr;
}



// Getter
string Monster::getName() const { return name; }
int Monster::getHP() const { return m_HP; }
int Monster::getAttack() const { return m_ATK; }
int Monster::getDropGold() const { return m_dropGold; }
int Monster::getDropEXP() const { return m_dropEXP; }
int Monster::getMaxHP() const { return m_MaxHP; }
int Monster::getLevel() const { return m_Level; }

// Setter
void Monster::setName(const string name) { this->name = name; }
void Monster::setHP(int m_HP) { this->m_HP = m_HP; }