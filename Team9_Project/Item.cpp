#include "Item.h"
using namespace std;

Item::Item(const string& name, int value)
	: name(name), value(value) { }

string Item::getName() const
{
	return name;
}

int Item::getValue() const
{
	return value;
}