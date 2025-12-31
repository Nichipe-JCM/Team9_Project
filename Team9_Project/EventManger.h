#pragma once
#include <vector>


class Event;

using namespace std;
class EventManger {
private:
	vector<Event*> m_EventList;

public:
	EventManger();
	

	~EventManger();

	void StartEvent();

};

