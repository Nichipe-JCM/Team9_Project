#include "Monster.h"
#include "Character.h"
#include "Weapon.h"
#include "ThrowingWeapon.h"
#include "HealingPotion.h"
#include "BuffPotion.h"
#include "CashableItem.h"
#include "Windows.h"
#include "UIManager.h"
#include "ItemPool.h"

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

void Monster::attack(Character* target, UIManager* ui)
{
	ui->AddLog(Color::ORANGE + name + Color::BRIGHT_WHITE + "이(가) " + Color::SKY_BLUE + target->getName() + Color::BRIGHT_WHITE + "을(를) 공격합니다!");
	ui->RenderBattleScreen(target, this);
	Sleep(500);	
	if (target != nullptr) {
		target->GetHit(m_ATK, ui);
	}
}

void Monster::GetHit(int damage, UIManager* ui) // checkDeath 추가
{
	m_HP -= damage;
	if (m_HP < 0) m_HP = 0;
	ui->AddLog(Color::ORANGE + name + Color::BRIGHT_WHITE + "이(가) " + Color::LIME + std::to_string(damage)
		+ Color::BRIGHT_WHITE + "의 피해를 입었습니다. (남은 HP: " + std::to_string(m_HP) + ")" ); // 해치웠나?
}

// 해치웠나? 의 몸통
bool Monster::checkDeath() {
	if (m_HP <= 0) {
		isAlive = false;
		Sleep(1000);
		cout << Color::LIME << name << "이(가) 쓰러졌다!" << endl;
		Sleep(1000);
		cout << Color::GOLD << m_dropGold << Color::LIME << " ZEP 코인과 " << Color::BRIGHT_WHITE <<
			m_dropEXP << Color::LIME << " 경험치를 획득했다!" << endl;
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



Item* Monster::dropItem() {
    static random_device rd;
    static mt19937 gen(rd());

    uniform_int_distribution<int> dropChance(1, 100);
    if (dropChance(gen) > 30) {
        cout <<Color::BRIGHT_WHITE<< "이겼지만 아무것도 나오지 않았다...\n";
        return nullptr;
    }

    vector<Item*>& allItems = ItemPool::getAllItems();
    if (allItems.empty()) return nullptr;

    vector<Item*> candidates;
    vector<double> weights;

    for (Item* item : allItems) {

        candidates.push_back(item);

        double w = 0;
        switch (item->getRarity()) {
        case Rarity::Common:    w = 100.0; break;
        case Rarity::Rare:      w = 30.0;  break;
        case Rarity::Legendary: w = 1.0;   break;
        }
        weights.push_back(w);
    }

    discrete_distribution<int> dist(weights.begin(), weights.end());

    int selectedIndex = dist(gen);
    Item* selectedItem = candidates[selectedIndex];

    cout << Color::LIME << name << "이(가) "
        << selectedItem->getRarityColor(selectedItem->getRarity())
        << selectedItem->getName()
        << Color::LIME << "을 드랍했다!\n";

    return selectedItem->clone();
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