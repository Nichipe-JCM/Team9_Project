#pragma once
#include <vector>


class Event;
class Character;

using namespace std;
class EventManager {
private:
	vector<Event*> m_EventList;

public:
	EventManager();
	

	~EventManager();

	void StartEvent(Character* character);

};

