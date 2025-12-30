#pragma once
#include <vector>
#include "Event.h"

using namespace std;
class EventManger {
private:
	vector<Event*> EventList;

public:
	EventManger() {

		// 이벤트 종류별로 벡터에 할당
	}

	

	~EventManger() {
		for (size_t i = 0; i < EventList.size(); i++) {
			delete EventList[i];
		}

	}

	// void 이벤트 발생시 사용될 함수

};

