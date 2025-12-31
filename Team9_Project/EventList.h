#pragma once
#include "Event.h"


class BuyBookEvent : public Event{
private:
	int m_Count;
public:
	BuyBookEvent() :m_Count(0) {}

	void EventEffect(Character* character) override;

	void EventCount() override;

};

class SurpriseSessionEvent : public Event {
private:
	int m_Count;
public:
	SurpriseSessionEvent() : m_Count(0) {}

	void EventEffect(Character* character) override;

	void EventCount() override;
};

class TILIsImportantEvent : public Event {
private:
	int m_Count;
public:
	TILIsImportantEvent() : m_Count(0) {}

	void EventEffect(Character* character) override;

	void EventCount() override;
};

class DrinkCaffeineEvent : public Event {
private:
	int m_Count;
public:
	DrinkCaffeineEvent() : m_Count(0) {}

	void EventEffect(Character* character) override;

	void EventCount() override;
};

class FixCodeEvent : public Event {
private:
	int m_Count;
public:
	FixCodeEvent() : m_Count(0) {}

	void EventEffect(Character* character) override;

	void EventCount() override;
};