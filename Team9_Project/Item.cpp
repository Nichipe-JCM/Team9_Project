#include "Item.h"
using namespace std;

Item::Item(const string& name, int value)
	: name(name), value(value) { }

string Item::getName() const
{
	return m_name;
}

int Item::getValue() const
{
	return m_value;
}