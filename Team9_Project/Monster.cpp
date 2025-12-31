#include "Monster.h"
#include "Weapon.h"
#include "ThrowingWeapon.h"
#include "Potion.h"
#include "CashableItem.h"

#include <iostream>
#include <string>
#include <random>
#include <map>
#include <ctime>    

using namespace std;

Monster::Monster(const string& name, int level, int gold, int exp)
	: name(name), m_dropGold(gold), m_dropEXP(exp)
{

	static random_device rd;
	static mt19937 gen(rd());


	uniform_int_distribution<int> hpDist(level * 20, level * 30);
	m_HP = hpDist(gen);

	uniform_int_distribution<int> atkDist(level * 5, level * 10);
	m_ATK = atkDist(gen);

}

	void Monster::attack(Player * player)
	{
		cout << name << "의 공격! (공격력: " << m_ATK << ")" << endl;
	}

	void Monster::GetHit(int damage)
	{
		m_HP -= damage;
		if (m_HP < 0) m_HP = 0;
		cout << name << "이(가) " << damage << " 피해를 입었습니다. 남은 HP: " << m_HP << endl;
	}

	// 드랍 테이블
	static map <string, vector<Item*>> monsterDrops = {

		// Weapon - item name / value / damage
		// Potion - item name / value / healamount
		// ThrowW - item name / value / damage / quantity
		// CashAb - item name / value
	
		 {"포인터",{ new Weapon("뫄뫄..", 10, 0), new CashableItem("뭐뭐..", 20) }},
		 {"포인터",{ new Potion("뫄뫄..", 10, 0), new ThrowingWeapon("뭐뭐..", 20,10,3) }}
		// ...
	};

	Item* Monster::dropItem() {
		static random_device rd;
		static mt19937 gen(rd());

		auto it = monsterDrops.find(name);
		if (it != monsterDrops.end())
		{// 랜덤 아이템 복사
			const vector<Item*>& items = it->second;
			uniform_int_distribution<int> dist(0, items.size() - 1);
			return items[dist(gen)];
		}

		// 30% 확률로 아이템 드랍
		bernoulli_distribution itemDropDist(0.3);
		if (itemDropDist(gen)) {
			cout << name << "이(가) 아이템을 드랍했다!" << endl;
		}
		else {
			cout << name << "아무것도 나오지 않았다..." << endl;
		}

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