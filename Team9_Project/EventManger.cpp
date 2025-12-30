#include "EventManger.h"
#include "Event.h"
#include "EventList.h"
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

EventManger:: EventManger() {
	EventList.push_back(new HPBuffEvent);
}

EventManger :: ~EventManger(){
		for (size_t i = 0; i < EventList.size(); i++) {
			delete EventList[i];
		}

}
void EventManger:: StartEvent() {
	
}