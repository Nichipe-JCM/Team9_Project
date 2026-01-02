#pragma once
#include <vector>


class Event;
class Character;
class GameManager;

using namespace std;
class EventManager {
private:
	vector<Event*> m_EventList;

public:
	EventManager();
	

	~EventManager();

	void StartEvent(Character* character,GameManager* gm);

};

