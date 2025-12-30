#include "HPBuffEvent.h"
#include <iostream>

using namespace std;

void HPBuffEvent::EventEffect(Character* character) {

	// 후에 Character 클래스 변수, 함수 보고 작성
	// 이벤트 시작하면 호수 조우 
	// 그 후 1. 물을 마신다 2. 그냥 간다 선택지 중 선택
	// 1 을 선택하면 몸이 치유되는 것을 느끼며 현재체력,최대체력+ (수치 정해야함)
	// 2 선택하면 별 일 없이 이벤트 종료

	Count++;
}

void HPBuffEvent::EventCount() {
	cout << "호수 이벤트 조우 횟수: " << Count << endl;
}