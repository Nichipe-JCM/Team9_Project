#pragma once
#include "Event.h"


class HPBuffEvent : public Event{
private:
	int m_Count;
public:
	HPBuffEvent() :m_Count(0) {}

	void EventEffect(Character* character) override {}

	void EventCount() override {}

};

