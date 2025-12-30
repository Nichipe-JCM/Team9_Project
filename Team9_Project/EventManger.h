#pragma once
#include <vector>


class Event;

using namespace std;
class EventManger {
private:
	vector<Event*> EventList;

public:
	EventManger();
	

	~EventManger();

	void StartEvent();

};

