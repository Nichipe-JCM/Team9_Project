#pragma once
#include <vector>
#include "Item.h"
class ItemFactory
{ public:
	static std::vector<Item*> createDefaultItems(); 
};