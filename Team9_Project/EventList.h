#pragma once
#include "Event.h"


class HPBuffEvent : public Event{
private:
	int Count;
public:
	HPBuffEvent() :Count(0) {}

	void EventEffect(Character* character) override {}

	void EventCount() override {}

};

