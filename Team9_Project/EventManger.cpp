#include "EventManger.h"
#include "Event.h"
#include "EventList.h"
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

EventManger:: EventManger() {
	m_EventList.push_back(new HPBuffEvent);
}

EventManger :: ~EventManger(){
		for (size_t i = 0; i < m_EventList.size(); i++) {
			delete m_EventList[i];
		}

}
void EventManger:: StartEvent() {
	
}