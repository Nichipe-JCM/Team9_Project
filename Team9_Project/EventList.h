#pragma once
#include "Event.h"

class Character;

class BuyBookEvent : public Event {

public:
	BuyBookEvent() {}

	void EventEffect(Character* character, GameManager* gm) override;


};

class SurpriseSessionEvent : public Event {

public:
	SurpriseSessionEvent() {}

	void EventEffect(Character* character, GameManager* gm) override;

	
};

class TILIsImportantEvent : public Event {

public:
	TILIsImportantEvent() {}

	void EventEffect(Character* character, GameManager* gm) override;

	
};

class DrinkCaffeineEvent : public Event {

public:
	DrinkCaffeineEvent() {}

	void EventEffect(Character* character, GameManager* gm) override;

	
};

class FixCodeEvent : public Event {

public:
	FixCodeEvent() {}

	void EventEffect(Character* character, GameManager* gm) override;

	
};

class SOSRequestEvent : public Event {

public:
	SOSRequestEvent() {}

	void EventEffect(Character* character, GameManager* gm) override;

	
};

class YouTubeAlgorithmEvent : public Event {

public:
	YouTubeAlgorithmEvent() {}

	void EventEffect(Character* character, GameManager* gm) override;

	
};

class MidnightDebugEvent : public Event {

public:
	MidnightDebugEvent() {}

	void EventEffect(Character* character, GameManager* gm) override;

	
};

class CodeCopyEvent : public Event {

public:
	CodeCopyEvent() {}

	void EventEffect(Character* character, GameManager* gm) override;

	
};

class ZepGambleEvent : public Event {

public:
	ZepGambleEvent() {}
	void EventEffect(Character* character, GameManager* gm) override;
	
};

class FunctionNamingEvent : public Event {

public:
	FunctionNamingEvent() {}
	void EventEffect(Character* character, GameManager* gm) override;
	
};

class LegacyCodeEvent : public Event {

public:
	LegacyCodeEvent() {}
	void EventEffect(Character* character, GameManager* gm) override;
	
};

class NappingEvent : public Event {

public:
	NappingEvent() {}
	void EventEffect(Character* character, GameManager* gm) override;
	
};

class PartTimeJobEvent : public Event {

public:
	PartTimeJobEvent() {}
	void EventEffect(Character* character, GameManager* gm) override;
	
};

class VSUpdateEvent : public Event {

public:
	VSUpdateEvent() {}
	void EventEffect(Character* character, GameManager* gm) override;
	
};

class QuestionCodeEvent : public Event {

public:
	QuestionCodeEvent() {}
	void EventEffect(Character* character, GameManager* gm) override;
	
};

class TemptationOfWeekendEvent : public Event {

public:
	TemptationOfWeekendEvent(){}
	void EventEffect(Character* character, GameManager* gm) override;
	
};

class RelayQuizEvent : public Event {

public:
	RelayQuizEvent() {}
	void EventEffect(Character* character, GameManager* gm) override;
	
};

class HowSuccessEvent : public Event {

public:
	HowSuccessEvent() {}
	void EventEffect(Character* character, GameManager* gm) override;
	
};

class BlueScreenEvent : public Event {

public:
	BlueScreenEvent() {}
	void EventEffect(Character* character, GameManager* gm) override;
	
};