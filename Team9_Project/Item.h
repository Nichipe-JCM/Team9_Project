#pragma once
#include<string>
using namespace std;

class Item
{
public:
	Item(const string& name, int value, int attack = 0, int heal);
	virtual ~Item() = default;

	string getName() const;
	int getValue() const;
	int getAttack() const;
	int getHeal() const;

	// 아이템 타입을 문자열로 반환 (무기, 포션 이렇게)
	virtual string getType() const = 0;

private:
	string name;
	int value;
};