#pragma once
#include <string>
#include <vector>


using namespace std;

class Potion;

class Item;

class Monster;

class Inventory;

class Character//캐릭터 클래스
{
private:
	string m_name;//유저의 닉네임
	int m_HP;//현재 체력
	int m_MaxHP;//최대 체력
	int m_ATK;//공격력
	int m_Wepatk;//무기 공격력
	int m_EXP;//현재 보유 경험치
	int m_EXPToLevelUp;//경험치통
	int m_Level;//현재 레벨
	int m_MaxLevel;//최대 레벨
	int m_Gold;//현재 보유 골드
	bool m_Throw;
	

	Item* m_EquippedThrow;//장착중인 투척류
	Item* m_Equippeditem;//무기

	Inventory* m_Inventory; // 임시로 인벤토리 추가



public:
	Character(string name, int hp=200, int maxHp=200, int atk=9999, int level=1,int gold=0, int exp=0);//캐릭터의 초기값

	;

	string getName()const;
	int getHP()const;
	int getMaxHP()const;
	int getATK() const;
	int getEXP()const;
	int getLevel()const;
	int getEXPToLevelUp()const;
	int getGold()const;
	Inventory* getInventory()const;
	

	void setHP(int Hp);
	void setMaxHP(int MaxHp);
	void setATK(int atk);
	void setEXP(int exp);
	void GainEXP(int amount);
	void setLevel(int level);
	void setGold(int gold);
	void GainGold(int amount);

	void LevelUp();
	void Attack(Monster* target);
	void GetHit(int damage);

	void showStatus();//캐릭터 스텟 보기
	void usePotion(Potion& potion);
    void manageEquipment(int action, Item* item, int slot); // 무기 투척류 장비착용 해제 포함
};