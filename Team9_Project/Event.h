#pragma once
class Event
{
public:
	virtual void EventEffect(Character* character) = 0;
	virtual void EventCount() = 0;
	virtual ~Event(){}
};

