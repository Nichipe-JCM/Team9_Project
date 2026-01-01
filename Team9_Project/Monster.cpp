#include "Monster.h"
#include "Character.h"
#include "Weapon.h"
#include "ThrowingWeapon.h"
#include "HealingPotion.h"
#include "BuffPotion.h"
#include "CashableItem.h"
#include "Item.h"

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

}

void Monster::attack(Character* target)
{
	cout << name << "의 공격! (공격력: " << m_ATK << ")" << endl;
	// player->gethit(m_atk)
	if (target != nullptr) {
		target->GetHit(m_ATK); // 나중에 character.h에 gethit 들어오면 오류 사라짐
	}
}

void Monster::GetHit(int damage) // checkDeath 추가
{
	m_HP -= damage;
	if (m_HP < 0) m_HP = 0;
	cout << name << "이(가) " << damage << " 피해를 입었습니다. 남은 HP: " << m_HP << endl;

	checkDeath(); // 해치웠나?
}

// 해치웠나? 의 몸통
bool Monster::checkDeath() {
	if (m_HP <= 0) {
		isAlive = false;

		cout << name << "이(가) 쓰러졌다!" << endl;

		cout << m_dropGold << " 골드와 " << m_dropEXP << " 경험치를 획득했다!" << endl;

		//auto dropped = dropItem();
		//if (dropped)
		//{
		//	cout << "플레이어가 "
		//		<< dropped->getName()
		//		<< "을(를) 획득했다!\n";
		//}
		//return true;
	}
	return false;
}



// 콘솔 글씨색 변경
string getRarityColor(Rarity rarity) {
	switch (rarity) {
	case Rarity::Common:    return "\033[37m"; // 흰색
	case Rarity::Rare:      return "\033[34m"; // 파란색
	case Rarity::Epic:      return "\033[35m"; // 보라색
	case Rarity::Legendary: return "\033[33m"; // 노란색
	}
	return "\033[0m"; // 기본색
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
static map<string, vector<DropEntry>> monsterDrops =
{
{"포인터", {
	{ make_shared <Weapon>("키보드워리어의 너덜너덜한 키보드였던 것", 10, 10),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Weapon },
	{ make_shared <CashableItem>("지폐", 77),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <CashableItem>("500원 동전", 50),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <HealingPotion>("쓰리샷 추가한 커피", 55, 45),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::HPotion },
	{ make_shared <CashableItem>("길가다 주운 복권", 10000),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Cash },
	{ make_shared <BuffPotion>("코딩애플 숏츠", 20, 10),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::BPotion },
	{ make_shared <Weapon>("전설적인 C++ 마스터의 키보드", 500, 50),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Weapon },
}},

{"레퍼런스", {
	{ make_shared <Weapon>("키보드워리어의 너덜너덜한 키보드였던 것", 10, 10),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Weapon },
	{ make_shared <CashableItem>("지폐", 77),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <CashableItem>("500원 동전", 50),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <HealingPotion>("쓰리샷 추가한 커피", 55, 45),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::HPotion },
	{ make_shared <BuffPotion>("코딩애플 숏츠", 20, 10),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::BPotion },
	{ make_shared <CashableItem>("길가다 주운 복권", 10000),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Cash },
	{ make_shared <ThrowingWeapon>("투척용 플로피디스크", 20, 10, 3),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Throwing },
	{ make_shared <Weapon>("전설적인 C++ 마스터의 키보드", 500, 50),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Weapon },

}},

{"템플릿", {
	{ make_shared <Weapon>("독거미 키보드 60% 배열", 30, 30),
		Rarity::Rare, getDefaultDropRate(Rarity::Rare), ItemCategory::Weapon },
	{ make_shared <CashableItem>("지폐", 77),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <CashableItem>("500원 동전", 50),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <HealingPotion>("에너지드링크", 40, 50),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::HPotion },
	{ make_shared <ThrowingWeapon>("구겨진 음료캔", 20, 30, 2),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Throwing },
	{ make_shared <CashableItem>("길가다 주운 복권", 10000),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Cash },
	{ make_shared <Weapon>("전설적인 C++ 마스터의 키보드", 500, 50),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Weapon },
}},

{"변수", {
	{ make_shared <Weapon>("독거미 키보드 60% 배열", 30, 30),
		Rarity::Rare, getDefaultDropRate(Rarity::Rare), ItemCategory::Weapon },
	{ make_shared <CashableItem>("지폐", 77),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <CashableItem>("500원 동전", 50),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <HealingPotion>("에너지드링크", 40, 50),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::HPotion },
	{ make_shared <ThrowingWeapon>("구겨진 음료캔", 20, 30, 2),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Throwing },
	{ make_shared <CashableItem>("길가다 주운 복권", 10000),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Cash },
	{ make_shared <Weapon>("전설적인 C++ 마스터의 키보드", 500, 50),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Weapon },
}},

{"함수", {
	{ make_shared <Weapon>("독거미 키보드 60% 배열", 30, 30),
		Rarity::Rare, getDefaultDropRate(Rarity::Rare), ItemCategory::Weapon },
	{ make_shared <CashableItem>("지폐", 77),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <CashableItem>("500원 동전", 50),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <ThrowingWeapon>("구겨진 음료캔", 20, 30, 2),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Throwing },
	{ make_shared <CashableItem>("길가다 주운 복권", 10000),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Cash },
	{ make_shared <Weapon>("전설적인 C++ 마스터의 키보드", 500, 50),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Weapon },
}},

{"배열", {
	{ make_shared <Weapon>("독거미 키보드 60% 배열", 30, 30),
		Rarity::Rare, getDefaultDropRate(Rarity::Rare), ItemCategory::Weapon },
	{ make_shared <CashableItem>("지폐", 77),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <CashableItem>("500원 동전", 50),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <ThrowingWeapon>("구겨진 음료캔", 20, 30, 2),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Throwing },
	{ make_shared <CashableItem>("길가다 주운 복권", 10000),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Cash },
	{ make_shared <Weapon>("전설적인 C++ 마스터의 키보드", 500, 50),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Weapon },
}},

{"알고리즘", {
	{ make_shared <Weapon>("독거미 키보드 60% 배열", 30, 30),
		Rarity::Rare, getDefaultDropRate(Rarity::Rare), ItemCategory::Weapon },
	{ make_shared <CashableItem>("지폐", 77),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <CashableItem>("500원 동전", 50),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <ThrowingWeapon>("구겨진 음료캔", 20, 30, 2),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Throwing },
	{ make_shared <CashableItem>("길가다 주운 복권", 10000),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Cash },
	{ make_shared <Weapon>("전설적인 C++ 마스터의 키보드", 500, 50),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Weapon },
}},

{ "객체", {
	{ make_shared <Weapon>("독거미 키보드 60% 배열", 30, 30),
		Rarity::Rare, getDefaultDropRate(Rarity::Rare), ItemCategory::Weapon },
	{ make_shared <CashableItem>("지폐", 77),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <CashableItem>("500원 동전", 50),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <ThrowingWeapon>("구겨진 음료캔", 20, 30, 2),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Throwing },
	{ make_shared <CashableItem>("길가다 주운 복권", 10000),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Cash },
	{ make_shared <Weapon>("전설적인 C++ 마스터의 키보드", 500, 50),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Weapon },
}},

{ "부동소수점", {
	{ make_shared <Weapon>("독거미 키보드 60% 배열", 30, 30),
		Rarity::Rare, getDefaultDropRate(Rarity::Rare), ItemCategory::Weapon },
	{ make_shared <CashableItem>("지폐", 77),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <CashableItem>("500원 동전", 50),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
	{ make_shared <ThrowingWeapon>("구겨진 음료캔", 20, 30, 2),
		Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Throwing },
	{ make_shared <CashableItem>("길가다 주운 복권", 10000),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Cash },
	{ make_shared <Weapon>("전설적인 C++ 마스터의 키보드", 500, 50),
		Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Weapon },
} },

	{ "클래스", {
		{ make_shared <Weapon>("독거미 키보드 60% 배열", 30, 30),
			Rarity::Rare, getDefaultDropRate(Rarity::Rare), ItemCategory::Weapon },
		{ make_shared <CashableItem>("지폐", 77),
			Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
		{ make_shared <CashableItem>("500원 동전", 50),
			Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Cash },
		{ make_shared <ThrowingWeapon>("구겨진 음료캔", 20, 30, 2),
			Rarity::Common, getDefaultDropRate(Rarity::Common), ItemCategory::Throwing },
		{ make_shared <CashableItem>("길가다 주운 복권", 10000),
			Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Cash },
		{ make_shared <Weapon>("전설적인 C++ 마스터의 키보드", 500, 50),
			Rarity::Legendary, getDefaultDropRate(Rarity::Legendary), ItemCategory::Weapon },
	} }
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
		if (drop.category == category)
		{
			cout << " - " << getRarityColor(drop.rarity)
				<< drop.item->getName()
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
		bernoulli_distribution dist(drop.dropRate);
		if (dist(gen)) {
			return drop.item.get();
		}
	}
	return nullptr;
}


shared_ptr<Item> Monster::dropItem() {
	//auto it = monsterDrops.find(name);
	//if (it == monsterDrops.end()) return nullptr;

	//static random_device rd;
	//static mt19937 gen(rd());

	//double total = 0.0;
	//for (auto& d : it->second) total += d.dropRate;

	//uniform_real_distribution<> dist(0.0, total);
	//double roll = dist(gen);

	//double acc = 0.0;
	//for (auto& d : it->second) {
	//	acc += d.dropRate;
	//	if (roll <= acc) {
	//		cout << name << "이(가) "
	//			<< getRarityColor(d.rarity)
	//			<< d.item->getName()
	//			<< "\033[0m 을 드랍했다!\n";
	//		return d.item;
	//	}
	//}

	cout << name << "아무것도 나오지 않았다...\n";
	return nullptr;
}



// Getter
string Monster::getName() const { return name; }
int Monster::getHP() const { return m_HP; }
int Monster::getAttack() const { return m_ATK; }
int Monster::getDropGold() const { return m_dropGold; }
int Monster::getDropEXP() const { return m_dropEXP; }

// Setter
void Monster::setName(const string name) { this->name = name; }
void Monster::setHP(int m_HP) { this->m_HP = m_HP; }