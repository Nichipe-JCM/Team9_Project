#include "EventManager.h"
#include "Event.h"
#include "EventList.h"
#include <vector>
#include <random>
#include <iostream>

using namespace std;

EventManager:: EventManager() {
	m_EventList.push_back(new BuyBookEvent());
	m_EventList.push_back(new SurpriseSessionEvent());
	m_EventList.push_back(new TILIsImportantEvent());
	m_EventList.push_back(new DrinkCaffeineEvent());
	m_EventList.push_back(new FixCodeEvent());
}

EventManager :: ~EventManager(){
		for (size_t i = 0; i < m_EventList.size(); i++) {
			delete m_EventList[i];
		}

}
void EventManager:: StartEvent(Character* character) {					
	static random_device rd;
	static mt19937 gen(rd());											// 난수 생성을 위한 준비
	uniform_int_distribution<int> dis(0, m_EventList.size() - 1);		// 난수 범위 지정
	int EventNum = dis(gen);	// 만들어진 난수 변수에 대입		
	m_EventList[EventNum]->EventEffect(character);			//해당 되는 index에 있는 Event의 EventEffect 함수 실행 
}