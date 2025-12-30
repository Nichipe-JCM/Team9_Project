#include "Character.h"

using namespace std;

Character::Character(string name, int maxHp, int atk)
	:Name(name), HP(200), MaxHP(maxHp), ATK(atk), EXP(0), Level(1), Gold(0), EXPToLevelUp(100), MaxLevel(10),MaxInventorySize(20) {
}
string Character::getName()const { return Name; }
int Character::getHP()const { return HP; }
int Character::getMaxHP()const { return MaxHP; }
int Character::getATK()const { return ATK; }
int Character::getEXP()const { return EXP; }
int Character::getEXPToLevelUp()const { return EXPToLevelUp; }
int Character::getLevel()const { return Level; }
int Character::getGold()const { return Gold; }
vector<Item> Character::getInventory()const { return Inventory; }

void Character::setHP(int hp) { HP = hp; }
void Character::setMaxHP(int maxHp) { MaxHP = maxHp; }
void Character::setATK(int atk) { ATK = atk; }
void Character::setEXP(int exp) { EXP = exp; }
void Character::setLevel(int level) { Level = level; }
void Character::setGold(int gold) { Gold = gold; }

void Character::LevelUp() {
	if (Level < MaxLevel && EXP >= EXPToLevelUp) {
		Level++;
		MaxHP += 60;
		ATK += 30;
		EXP = 0;
		EXPToLevelUp = 100;
	}
}
void Character::Attack(Character& target) {
	target.GetHit(ATK);
}
void Character::GetHit(int damage) {
	HP -= damage;
	if (HP < 0) HP = 0;
}