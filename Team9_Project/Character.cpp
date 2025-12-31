#include "Character.h"

using namespace std;

Character::Character(string name, int maxHp, int atk)
	:m_name(name), m_HP(200), MaxHP(maxHp), m_ATK(atk), m_EXP(0), m_Level(1), m_Gold(0), m_EXPToLevelUp(100), m_MaxLevel(10),m_MaxInventorySize(20) {
}
string Character::getName()const { return m_name; }
int Character::getHP()const { return m_HP; }
int Character::getMaxHP()const { return MaxHP; }
int Character::getATK()const { return m_ATK; }
int Character::getEXP()const { return m_EXP; }
int Character::getEXPToLevelUp()const { return m_EXPToLevelUp; }
int Character::getLevel()const { return m_Level; }
int Character::getGold()const { return m_Gold; }
vector<Item> Character::getInventory()const { return m_Inventory; }

void Character::setHP(int hp) { m_HP = hp; }
void Character::setMaxHP(int maxHp) { MaxHP = maxHp; }
void Character::setATK(int atk) { m_ATK = atk; }
void Character::setEXP(int exp) { m_EXP = exp; }
void Character::setLevel(int level) { m_Level = level; }
void Character::setGold(int gold) { m_Gold = gold; }

void Character::LevelUp() {
	if (m_Level < m_MaxLevel && m_EXP >= m_EXPToLevelUp) {
		m_Level++;
		MaxHP += 60;
		m_ATK += 30;
		m_EXP = 0;
		m_EXPToLevelUp = 100;
	}
}
void Character::Attack(Character& target) {
	target.GetHit(m_ATK);
}
void Character::GetHit(int damage) {
	m_HP -= damage;
	if (m_HP < 0) m_HP = 0;
}