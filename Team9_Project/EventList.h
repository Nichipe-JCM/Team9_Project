#pragma once
#include "Event.h"


class BuyBookEvent : public Event {
private:
	int m_Count;
public:
	BuyBookEvent() :m_Count(0) {}

	void EventEffect(Character* character, GameManager* gm) override;

	void EventCount() override;

};

class SurpriseSessionEvent : public Event {
private:
	int m_Count;
public:
	SurpriseSessionEvent() : m_Count(0) {}

	void EventEffect(Character* character, GameManager* gm) override;

	void EventCount() override;
};

class TILIsImportantEvent : public Event {
private:
	int m_Count;
public:
	TILIsImportantEvent() : m_Count(0) {}

	void EventEffect(Character* character, GameManager* gm) override;

	void EventCount() override;
};

class DrinkCaffeineEvent : public Event {
private:
	int m_Count;
public:
	DrinkCaffeineEvent() : m_Count(0) {}

	void EventEffect(Character* character, GameManager* gm) override;

	void EventCount() override;
};

class FixCodeEvent : public Event {
private:
	int m_Count;
public:
	FixCodeEvent() : m_Count(0) {}

	void EventEffect(Character* character, GameManager* gm) override;

	void EventCount() override;
};

class SOSRequestEvent : public Event {
private:
	int m_Count;
public:
	SOSRequestEvent() : m_Count(0) {}

	void EventEffect(Character* character, GameManager* gm) override;

	void EventCount() override;
};

class YouTubeAlgorithmEvent : public Event {
private:
	int m_Count;
public:
	YouTubeAlgorithmEvent() : m_Count(0) {}

	void EventEffect(Character* character, GameManager* gm) override;

	void EventCount() override;
};

class MidnightDebugEvent : public Event {
private:
	int m_Count;
public:
	MidnightDebugEvent() : m_Count(0) {}

	void EventEffect(Character* character, GameManager* gm) override;

	void EventCount() override;
};

class CodeCopyEvent : public Event {
private:
	int m_Count;
public:
	CodeCopyEvent() : m_Count(0) {}

	void EventEffect(Character* character, GameManager* gm) override;

	void EventCount() override;
};

class ZepGambleEvent : public Event {
private:
	int m_Count;
public:
	ZepGambleEvent() : m_Count(0) {}
	void EventEffect(Character* character, GameManager* gm) override;
	void EventCount() override;
};

class FunctionNamingEvent : public Event {
private:
	int m_Count;
public:
	FunctionNamingEvent() : m_Count(0) {}
	void EventEffect(Character* character, GameManager* gm) override;
	void EventCount() override;
};

class LegacyCodeEvent : public Event {
private:
	int m_Count;
public:
	LegacyCodeEvent() : m_Count(0) {}
	void EventEffect(Character* character, GameManager* gm) override;
	void EventCount() override;
};