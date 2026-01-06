#pragma once
#include "Character.h"

class GameManager;

class Event
{
public:
	virtual void EventEffect(Character* character,GameManager* gm) = 0;
	virtual ~Event(){}
};

