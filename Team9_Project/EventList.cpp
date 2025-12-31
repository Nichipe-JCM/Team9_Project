#include "EventList.h"
#include <iostream>
#include <random>

using namespace std;

void BuyBookEvent::EventEffect(Character* character) {
	int Choice;
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 2);
	int RandNum = dis(gen);

	cout << "인터넷 서칭을 하던 중 원하던 C++ 강의 서적을 발견했다!" << endl;							
	cout << "평소보다 저렴한 가격이잖아? 구매할까? (구매 시 100 ZEP코인이 소모됩니다.)" << endl;		// 가격 팀원들과 상의 후 필요시 조정
	cout << "1. 구매한다  2. 구매하지 않는다" << endl;
	while (true) {			// 숫자 선택 예외처리 과정
		cin >> Choice;
		if (cin.fail()) {		// 숫자 말고 다른걸 입력했을 때
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "잘못된 값을 입력하셨습니다. 숫자만 입력해주세요." << endl;
			continue;
		}
		if (Choice == 1 || Choice == 2) {		// 선택지 안에서 선택시 while문 탈출
			break;
		}
		else {				// 1,2 제외 다른 숫자 입력시 작동
			cout << "잘못된 숫자를 선택하였습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}
	
		if (Choice == 1) {
			if (character->getGold() >= 100) {			//소지한 골드가 책 가격보다 크거나 같을때만 작동
				character->setGold(character->getGold() - 100);
				cout << "100 ZEP코인을 지불했습니다." << endl;
				if (RandNum == 0 || RandNum == 1) {		// 66% 확률의 긍정 이벤트
					cout << "원하던 책이 잘 도착했습니다!" << endl;
					cout << "배송받은 책을 읽고 지식이 늘었습니다!" << endl;
					cout << "코딩력이 50만큼 상승했다!" << endl;				// 후에 팀원들과 상의해서 수치 조정 필요
					character->setATK(character->getATK() + 50);				// 현재 코딩력에 정해진 수치만큼 상승
				}
				else {									// 33% 확률 부정 이벤트
					cout << "배송된 박스가 생각보다 무겁다?!" << endl;
					cout << "박스 안에는 묵직한 벽돌 뿐이였다..." << endl;
					cout << "안돼... 내 돈...." << endl;
					cout << "사기를 당해버렸다." << endl;
				}
			}
			else {				// 돈 없을 때 작동
				cout << "생각해보니 탈 것을 산다고 ZEP코인을 썼었지.." << endl;
				cout << "나중에 돈이 생기면 사야겠다.." << endl;
			}
		}
		else {		// 2번 선택지 선택 시 작동
			cout << "저 가격에 올라올 수가 없는데... 사기인가?" << endl;
			cout << "불안하니 사지 말아야지" << endl;
			cout << "책을 구매하지 않았다." << endl;
		}
																											
	m_Count++;
}
void BuyBookEvent::EventCount() {
	cout << "이벤트 조우 횟수 : " << m_Count << endl;
}



void SurpriseSessionEvent::EventEffect(Character* character) {
	int Choice;
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 2);
	int RandNum = dis(gen);

	cout << "과제를 하던 중 슬랙에 알림이 울린다." << endl;
	cout << "'튜터님의 깜짝세션 개최!' 참여하시겠습니까?" << endl;
	cout << "1. 참여한다  2. 참여하지 않는다" << endl;
	while (true) {			
		cin >> Choice;
		if (cin.fail()) {		
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "잘못된 값을 입력하셨습니다. 숫자만 입력해주세요." << endl;
			continue;
		}
		if (Choice == 1 || Choice == 2) {		
			break;
		}
		else {				
			cout << "잘못된 숫자를 선택하였습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}

	if (Choice == 1) {
		if (RandNum == 0 || RandNum == 1) {
			cout << "튜터님의 명강의를 들었더니 개념이 확실히 잡혔다." << endl;
			cout << "헷갈리던 개념이 잡히고 머리가 맑아진다." << endl;
			cout << "코딩력이 30만큼 상승했다!" << endl;		// 후에 수치조정 필요
			character->setATK(character->getATK() + 30);
		}
		else {
			cout << "'실력향상에는 반복학습이 최고죠!'" << endl;
			cout << "튜터님께서 추가과제를 주셨다...." << endl;
			cout << "안... 안돼! 이건 꿈이야!!" << endl;
			cout << "코딩력이 10 상승했다!" << endl;
			cout << "체력이 40 감소했다." << endl;
			character->setATK(character->getATK() + 10);
			character->setHP(character->getHP() - 40);			// 이 이벤트로 사망할 수도 있어서 후에 조정 필요
		}

	}
	else {
		cout << "과제 제출이 얼마 남지 않았으니까 지금은 과제에 집중하자." << endl;
		cout << "깜짝 세션에 참여하지 않았다." << endl;

	}

	m_Count++;
}
void SurpriseSessionEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}



void TILIsImportantEvent::EventEffect(Character* character) {
	int Choice;

	cout << "드디어 공부가 끝났다 이제 쉬어야지..." << endl;
	cout << "인생이 별거 있나 침대에 누워서 핸드폰 보는 이게 인생이지." << endl;
	cout << "아 맞다! 오늘 TIL을 안썼네." << endl;
	cout << "다시 일어나기 너무 귀찮은데..." << endl;
	cout << "1. TIL을 작성한다  2. 작성하지 않는다" << endl;
	while (true) {
		cin >> Choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "잘못된 값을 입력하셨습니다. 숫자만 입력해주세요." << endl;
			continue;
		}
		if (Choice == 1 || Choice == 2) {
			break;
		}
		else {
			cout << "잘못된 숫자를 선택하였습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}

	if (Choice == 1) {
		cout << "그래도 TIL 작성은 중요하지. 오늘 공부를 복습할겸 작성해보자" << endl;
		cout << "휴 다 작성했다. 이젠 진짜 자야지..." << endl;
		cout << "TIL을 작성하고 제출을 완료했다." << endl;
		cout << "제출한 TIL이 우수 TIL로 선정되었다!" << endl;
		cout << "1000 ZEP코인을 획득했다!" << endl;				// 수치 팀 상의 필요
		character->setGold(character->getGold() + 1000);
	}
	else {
		cout << "너무 힘들어서 일어날 수가 없다..." << endl;
		cout << "그래 하루만 쉬자... 하루 쉬는 건데 별일이야 있겠어?" << endl;
		cout << "TIL을 작성하지 않았다." << endl;
		cout << "적당한 휴식으로 HP가 10 상승했다." << endl;
		character->setHP(character->getHP() + 10);				// 수치 팀 상의 필요
	}

	m_Count++;
}
void TILIsImportantEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}



void DrinkCaffeineEvent::EventEffect(Character* character) {
	int Choice;
	double health = static_cast<double>(character->getHP()) / character->getMaxHP();	// 현재 체력 상태 체크를 위한 변수 만들기
	cout << "오늘도 해야할 공부가 많아서 일찍 자기는 틀렸구나..." << endl;
	cout << "그런데 너무 졸려서 집중이 안되네..." << endl;
	cout << "최근에 많이 먹었는데 오늘도 에너지드링크를 마셔야하나?" << endl;
	cout << "1. 마신다  2. 마시지 않는다" << endl;
	while (true) {
		cin >> Choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "잘못된 값을 입력하셨습니다. 숫자만 입력해주세요." << endl;
			continue;
		}
		if (Choice == 1 || Choice == 2) {
			break;
		}
		else {
			cout << "잘못된 숫자를 선택하였습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}

	if (Choice == 1) {
		if (health >= 0.5) {		// 현재체력이 최대체력의 절반보다 높거나 같을 때
			cout << "역시 에너지 드링크야. 먹으니까 눈이 확 떠지네." << endl;
			cout << "조금만 더 힘내서 해보자!" << endl;
			cout << "에너지 드링크 덕분에 집중력이 올라서 성공적으로 공부를 끝마쳤다!" << endl;
			cout << "코딩력이 40만큼 상승했다!" << endl;				// 후에 수치조정 필요
			character->setATK(character->getATK() + 40);
		}
		else {						// 현재 체력이 최대체력의 절반이 안될 때
			cout << "에너지 드링크 덕분에 오늘 공부를 다했다." << endl;
			cout << "이제 자러가야지." << endl;
			cout << "어라? 잠이 오지 않는다. 내일 아침 일찍 일어나야하는데 큰일났다!" << endl;
			cout << "다음날 생활패턴이 망가져 공부를 망쳤다." << endl;
			cout << "적당히 마실껄..." << endl;
			cout << "코딩력이 20 하락했다." << endl;					// 후에 수치조정 필요
			character->setATK(character->getATK() - 20);
		}
	}
	else {
		cout << "최근에 너무 많이 마셨으니까 오늘은 마시지 말자." << endl;
		cout << "잠도 깰겸 물 마시고 산책이나 하고 와야지." << endl;
		cout << "에너지 드링크를 마시지 않았다." << endl;
		cout << "체력과 최대체력이 10만큼 증가했다." << endl;			// 후에 수치조정 필요
		character->setMaxHP(character->getMaxHP() + 10);
		character->setHP(character->getHP()+ 10);
	}

	m_Count++;
}
void DrinkCaffeineEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}



void FixCodeEvent::EventEffect(Character* character) {
	int Choice;
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 2);
	int RandNum = dis(gen);

	cout << "과제 제출 마감 하루 전" << endl;
	cout << "휴 드디어 끝냈다. 제출하기 전에 오타는 없는지 다시 확인해봐야지" << endl;
	cout << "어우 내가 짠 코드가 이렇게 더러웠었나.. 심각하네." << endl;
	cout << "다시보니까 다시 수정하면 훨씬 간단하게 바꿀 수 있겠는데?" << endl;
	cout << "하루 정도 시간도 남았는데 수정해볼까?" << endl;
	cout << "1. 수정한다  2. 수정하지 않는다" << endl;
	while (true) {
		cin >> Choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "잘못된 값을 입력하셨습니다. 숫자만 입력해주세요." << endl;
			continue;
		}
		if (Choice == 1 || Choice == 2) {
			break;
		}
		else {
			cout << "잘못된 숫자를 선택하였습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}

	if (Choice == 1) {
		if (RandNum == 0 || RandNum == 1) {
			cout << "역시 함수와 클래스를 잘 활용하니까 코드가 훨씬 짧아지네" << endl;
			cout << "수정하면서 배웠던 내용 활용도 해보고 복습도 됐네. 수정하기를 잘했다!" << endl;
			cout << "과제를 성공적으로 수정해서 제출했다." << endl;
			cout << "코딩력이 40 상승했다!" << endl;							// 후에 수치조정 필요
			character->setATK(character->getATK() + 40);
		}
		else {
			cout << "수정하기 시작한지 어언 몇시간째... 오류가 멈추지 않는다..." << endl;
			cout << "어디서부터 잘못된걸까... 여기까지 왔는데 과제 제출을 못할 수는 없어..." << endl;
			cout << "오늘도 놀기는 글렀구나..." << endl;
			cout << "아슬아슬하게 수정해서 과제를 제출했다." << endl;
			cout << "코딩력이 40 상승했다! 체력이 20 하락했다." << endl;		// 후에 수치조정 필요
			character->setATK(character->getATK() + 40);
			character->setHP(character->getHP() - 20);
		}
	}
	else{
		cout << "과제를 완성한게 어디냐" << endl;
		cout << "일단 이 상태로 제출하고 나중에 궁금한 점이 생기면 인터넷을 찾아보자." << endl;
		cout << "오랜만에 게임이나 해볼까?" << endl;
		cout << "과제를 수정하지 않았다." << endl;
		cout << "휴식을 취해서 건강이 좋아졌다." << endl;
		cout << "체력이 10 증가했다! 최대체력이 10 증가했다!" << endl;			// 후에 수치조정 필요
		character->setMaxHP(character->getMaxHP() + 10);
		character->setHP(character->getHP() + 10);
	}

	m_Count++;
}
void FixCodeEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}