#pragma once
#include <vector>
#include "Item.h"
class ItemPool
{
public:
	static std::vector<Item*>& getAllItems();

};