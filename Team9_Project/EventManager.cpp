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
	m_EventList.push_back(new SOSRequestEvent());
	m_EventList.push_back(new YouTubeAlgorithmEvent());
	m_EventList.push_back(new MidnightDebugEvent());
	m_EventList.push_back(new CodeCopyEvent());
	m_EventList.push_back(new ZepGambleEvent());
	m_EventList.push_back(new FunctionNamingEvent());
	m_EventList.push_back(new LegacyCodeEvent());
	m_EventList.push_back(new NappingEvent());
	m_EventList.push_back(new PartTimeJobEvent());
	m_EventList.push_back(new VSUpdateEvent());
	m_EventList.push_back(new QuestionCodeEvent());
	m_EventList.push_back(new TemptationOfWeekendEvent());
	m_EventList.push_back(new RelayQuizEvent());
	m_EventList.push_back(new HowSuccessEvent());
	m_EventList.push_back(new BlueScreenEvent());
}

EventManager :: ~EventManager(){
		for (size_t i = 0; i < m_EventList.size(); i++) {
			delete m_EventList[i];
		}

}
void EventManager:: StartEvent(Character* character,GameManager* gm) {	
	if (m_EventList.empty()) {						//	벡터가 비어있을 때는 함수 실행 X
		cout << "호출될 이벤트가 없습니다!" << endl;
		return;
	}
	static random_device rd;
	static mt19937 gen(rd());											// 난수 생성을 위한 준비
	uniform_int_distribution<int> dis(0, m_EventList.size() - 1);		// 난수 범위 지정
	int EventNum = dis(gen);	// 만들어진 난수 변수에 대입		
	m_EventList[EventNum]->EventEffect(character,gm);			//해당 되는 index에 있는 Event의 EventEffect 함수 실행 

	delete m_EventList[EventNum];				// 이벤트 삭제전 객체 파괴

	m_EventList.erase(m_EventList.begin() + EventNum);			// 해당 벡터의 이벤트 삭제
}