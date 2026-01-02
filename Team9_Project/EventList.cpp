#include "EventList.h"
#include "Utils.h"
#include "GameManager.h"
#include "Character.h"
#include <iostream>
#include <random>

using namespace std;

void BuyBookEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 2);
	int RandNum = dis(gen);

	cout << "====================서적 할인 이벤트 발생!!!====================" << endl;
	cout << "인터넷 서칭을 하던 중 원하던 C++ 강의 서적을 발견했다!" << endl;
	cout << "\"평소보다 저렴한 가격이잖아? 구매할까?\" (구매 시 100 ZEP코인이 소모됩니다.)" << endl;		// 가격 팀원들과 상의 후 필요시 조정
	while (true) {
		cout << "1. 구매한다  2. 구매하지 않는다" << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}


		if (select == 1) {
			if (character->getGold() >= 100) {			//소지한 골드가 책 가격보다 크거나 같을때만 작동
				character->setGold(character->getGold() - 100);
				cout << "100 ZEP코인을 지불했습니다." << endl;
				if (RandNum == 0 || RandNum == 1) {		// 66% 확률의 긍정 이벤트
					cout << "원하던 책이 잘 도착했습니다!" << endl;
					cout << "배송받은 책을 읽고 지식이 늘었습니다!" << endl;
					cout << "코딩력이 50만큼 상승했다!" << endl;				// 후에 팀원들과 상의해서 수치 조정 필요
					character->setATK(character->getATK() + 50);				// 현재 코딩력에 정해진 수치만큼 상승
					break;
				}
				else {									// 33% 확률 부정 이벤트
					cout << "\"배송된 박스가 생각보다 무겁다?!\"" << endl;
					cout << "박스 안에는 묵직한 벽돌 뿐이였다..." << endl;
					cout << "\"안돼... 내 돈....\"" << endl;
					cout << "사기를 당해버렸다." << endl;
					break;
				}
			}
			else {				// 돈 없을 때 작동
				cout << "\"생각해보니 탈 것을 산다고 ZEP코인을 썼었지..\"" << endl;
				cout << "\"나중에 돈이 생기면 사야겠다..\"" << endl;
				break;
			}
		}
		else if (select == 2) {		// 2번 선택지 선택 시 작동
			cout << "\"저 가격에 올라올 수가 없는데... 사기인가?\"" << endl;
			cout << "\"불안하니 사지 말아야지\"" << endl;
			cout << "책을 구매하지 않았다." << endl;
			break;
		}
		else {
			cout << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}

	m_Count++;
}
void BuyBookEvent::EventCount() {
	cout << "이벤트 조우 횟수 : " << m_Count << endl;
}



void SurpriseSessionEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 2);
	int RandNum = dis(gen);

	cout << "====================깜짝 세션 이벤트 발생!!!====================" << endl;
	cout << "과제를 하던 중 슬랙에 알림이 울린다." << endl;
	cout << "\"튜터님의 깜짝세션 개최!\" 참여하시겠습니까?" << endl;
	while (true) {
		cout << "1. 참여한다  2. 참여하지 않는다" << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}


		if (select == 1) {
			if (RandNum == 0 || RandNum == 1) {
				cout << "튜터님의 명강의를 들었더니 개념이 확실히 잡혔다." << endl;
				cout << "헷갈리던 개념이 잡히고 머리가 맑아진다." << endl;
				cout << "코딩력이 30만큼 상승했다!" << endl;		// 후에 수치조정 필요
				character->setATK(character->getATK() + 30);
				break;
			}
			else {
				cout << "\"실력향상에는 반복학습이 최고죠!\"" << endl;
				cout << "튜터님께서 추가과제를 주셨다...." << endl;
				cout << "\"안... 안돼! 이건 꿈이야!!\"" << endl;
				cout << "코딩력이 10 상승했다!" << endl;
				cout << "체력이 40 감소했다." << endl;
				character->setATK(character->getATK() + 10);
				character->setHP(character->getHP() - 40);			// 이 이벤트로 사망할 수도 있어서 후에 조정 필요
				break;
			}

		}
		else if (select == 2) {
			cout << "\"과제 제출이 얼마 남지 않았으니까 지금은 과제에 집중하자.\"" << endl;
			cout << "깜짝 세션에 참여하지 않았다." << endl;
			break;
		}
		else {
			cout << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}

	m_Count++;
}
void SurpriseSessionEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}



void TILIsImportantEvent::EventEffect(Character* character, GameManager* gm) {


	cout << "====================TIL 작성 이벤트 발생!!!====================" << endl;
	cout << "\"드디어 공부가 끝났다 이제 쉬어야지...\"" << endl;
	cout << "\"인생이 별거 있나 침대에 누워서 핸드폰 보는 이게 인생이지.\"" << endl;
	cout << "\"아 맞다! 오늘 TIL을 안썼네.\"" << endl;
	cout << "\"다시 일어나기 너무 귀찮은데...\"" << endl;
	while (true) {
		cout << "1. TIL을 작성한다  2. 작성하지 않는다" << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}

		if (select == 1) {
			cout << "\"그래도 TIL 작성은 중요하지. 오늘 공부를 복습할겸 작성해보자\"" << endl;
			cout << "\"휴 다 작성했다. 이젠 진짜 자야지...\"" << endl;
			cout << "TIL을 작성하고 제출을 완료했다." << endl;
			cout << "제출한 TIL이 우수 TIL로 선정되었다!" << endl;
			cout << "1000 ZEP코인을 획득했다!" << endl;				// 수치 팀 상의 필요
			character->setGold(character->getGold() + 1000);
			break;
		}
		else if (select == 2) {
			cout << "\"너무 힘들어서 일어날 수가 없다...\"" << endl;
			cout << "\"그래 하루만 쉬자... 하루 쉬는 건데 별일이야 있겠어?\"" << endl;
			cout << "TIL을 작성하지 않았다." << endl;
			cout << "적당한 휴식으로 HP가 10 상승했다." << endl;
			character->setHP(character->getHP() + 10);				// 수치 팀 상의 필요
			break;
		}
		else {
			cout << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}

	m_Count++;
}
void TILIsImportantEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}



void DrinkCaffeineEvent::EventEffect(Character* character, GameManager* gm) {
	double health = static_cast<double>(character->getHP()) / character->getMaxHP();	// 현재 체력 상태 체크를 위한 변수 만들기

	cout << "====================카페인 섭취 이벤트 발생!!!====================" << endl;
	cout << "\"오늘도 해야할 공부가 많아서 일찍 자기는 틀렸구나...\"" << endl;
	cout << "\"그런데 너무 졸려서 집중이 안되네...\"" << endl;
	cout << "\"최근에 많이 먹었는데 오늘도 에너지드링크를 마셔야하나?\"" << endl;
	while (true) {
		cout << "1. 마신다  2. 마시지 않는다" << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}


		if (select == 1) {
			if (health >= 0.5) {		// 현재체력이 최대체력의 절반보다 높거나 같을 때
				cout << "\"역시 에너지 드링크야. 먹으니까 눈이 확 떠지네.\"" << endl;
				cout << "\"조금만 더 힘내서 해보자!\"" << endl;
				cout << "에너지 드링크 덕분에 집중력이 올라서 성공적으로 공부를 끝마쳤다!" << endl;
				cout << "코딩력이 40만큼 상승했다!" << endl;				// 후에 수치조정 필요
				character->setATK(character->getATK() + 40);
				break;
			}
			else {						// 현재 체력이 최대체력의 절반이 안될 때
				cout << "에너지 드링크 덕분에 오늘 공부를 다했다." << endl;
				cout << "\"이제 자러가야지.\"" << endl;
				cout << "\"어라? 잠이 오지 않는다. 내일 아침 일찍 일어나야하는데 큰일났다!\"" << endl;
				cout << "다음날 생활패턴이 망가져 공부를 망쳤다." << endl;
				cout << "\"적당히 마실껄...\"" << endl;
				cout << "코딩력이 20 하락했다." << endl;					// 후에 수치조정 필요
				character->setATK(character->getATK() - 20);
				break;
			}
		}
		else if (select == 2) {
			cout << "\"최근에 너무 많이 마셨으니까 오늘은 마시지 말자.\"" << endl;
			cout << "\"잠도 깰겸 물 마시고 산책이나 하고 와야지.\"" << endl;
			cout << "에너지 드링크를 마시지 않았다." << endl;
			cout << "체력과 최대체력이 10만큼 증가했다." << endl;			// 후에 수치조정 필요
			character->setMaxHP(character->getMaxHP() + 10);
			character->setHP(character->getHP() + 10);
			break;
		}
		else {
			cout << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}

	m_Count++;
}
void DrinkCaffeineEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}



void FixCodeEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 2);
	int RandNum = dis(gen);

	cout << "====================과제 수정 이벤트 발생!!!====================" << endl;
	cout << "과제 제출 마감 하루 전" << endl;
	cout << "휴 드디어 끝냈다. 제출하기 전에 오타는 없는지 다시 확인해봐야지" << endl;
	cout << "어우 내가 짠 코드가 이렇게 더러웠었나.. 심각하네." << endl;
	cout << "다시보니까 다시 수정하면 훨씬 간단하게 바꿀 수 있겠는데?" << endl;
	cout << "하루 정도 시간도 남았는데 수정해볼까?" << endl;
	while (true) {
		cout << "1. 수정한다  2. 수정하지 않는다" << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}

		if (select == 1) {
			if (RandNum == 0 || RandNum == 1) {
				cout << "역시 함수와 클래스를 잘 활용하니까 코드가 훨씬 짧아지네" << endl;
				cout << "\"수정하면서 배웠던 내용 활용도 해보고 복습도 됐네. 수정하기를 잘했다!\"" << endl;
				cout << "과제를 성공적으로 수정해서 제출했다." << endl;
				cout << "코딩력이 40 상승했다!" << endl;							// 후에 수치조정 필요
				character->setATK(character->getATK() + 40);
				break;
			}
			else {
				cout << "수정하기 시작한지 어언 몇시간째... 오류가 멈추지 않는다..." << endl;
				cout << "\"어디서부터 잘못된걸까... 여기까지 왔는데 과제 제출을 못할 수는 없어...\"" << endl;
				cout << "\"오늘도 놀기는 글렀구나...\"" << endl;
				cout << "아슬아슬하게 수정해서 과제를 제출했다." << endl;
				cout << "코딩력이 40 상승했다! 체력이 20 하락했다." << endl;		// 후에 수치조정 필요
				character->setATK(character->getATK() + 40);
				character->setHP(character->getHP() - 20);
				break;
			}
		}
		else if (select == 2) {
			cout << "\"과제를 완성한게 어디냐\"" << endl;
			cout << "일단 이 상태로 제출하고 나중에 궁금한 점이 생기면 인터넷을 찾아보자." << endl;
			cout << "\"오랜만에 게임이나 해볼까?\"" << endl;
			cout << "과제를 수정하지 않았다." << endl;
			cout << "휴식을 취해서 건강이 좋아졌다." << endl;
			cout << "체력이 10 증가했다! 최대체력이 10 증가했다!" << endl;			// 후에 수치조정 필요
			character->setMaxHP(character->getMaxHP() + 10);
			character->setHP(character->getHP() + 10);
			break;
		}
		else {
			cout << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}

	m_Count++;
}
void FixCodeEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}



void SOSRequestEvent::EventEffect(Character* character, GameManager* gm) {
	cout << "====================팀원의 SOS요청 이벤트 발생!!!====================" << endl;
	cout << "\"띠링!\" 팀프로젝트 맡은 파트의 코드를 작성하던 중 슬랙의 알림이 울린다." << endl;
	cout << "팀원: 팀장님 지금 작성한 코드에서 오류가 너무 많이나와요.. 도와주세요 ㅜㅜ " << endl;
	cout << "확인해보니 에러가 발생하는 곳이 전체 코드의 절반 이상이다." << endl;
	cout << "\"지금 내가 맡은 파트도 마무리해야하는데...\"" << endl;
	cout << "팀원을 도와줄까?" << endl;
	while (true) {
		cout << "1. 팀원을 도와준다  2. 내 할 일을 한다" << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}

		if (select == 1) {
			cout << "\"그래 결국 팀 프로젝트니까 도와주자.\"" << endl;
			cout << "팀원과 코드를 수정해본다." << endl;
			cout << "예상했던 시간보다 더 거리긴 했지만 오류를 전부 수정했다." << endl;
			cout << "\"늦게 발견해서 나중에 수정했으면 큰일날 뻔 했다. 도와주길 잘했다.\"" << endl;
			cout << "조금 힘들긴했지만 결과물을 완성했다!" << endl;
			cout << "체력이 10 하락했다. 코딩력이 20 증가했다!" << endl;
			character->setHP(character->getHP() - 10);
			character->setATK(character->getATK() + 20);
			break;
		}
		else if (select == 2) {
			cout << "지금은 내 코가 석자다.. 미안하지만 거절해야겠다." << endl;
			cout << "나: 지금은 제 파트도 못 끝내서 나중에 도와드릴께요 죄송합니다." << endl;
			cout << "팀원: 아 네 알겠습니다... 제가 한번 수정해볼께요." << endl;
			cout << "그렇게 문제가 일단락되는 줄 알았다." << endl;
			cout << "하지만 나중에 내가 마주하게 된 것은 감당할 수 없이 늘어나버린 오류였다." << endl;
			cout << "수정하지 못한 오류가 남아서 결과물을 제출하지 못했다." << endl;
			cout << "코딩력이 20 하락했다." << endl;
			character->setATK(character->getATK() - 20);
			break;
		}
		else {
			cout << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}

	m_Count++;

}
void SOSRequestEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}



void YouTubeAlgorithmEvent::EventEffect(Character* character, GameManager* gm) {

	cout << "====================알고리즘의 유혹 이벤트 발생!!!====================" << endl;
	cout << "잠깐 쉬려고 유튜브를 켰다." << endl;
	cout << "\"어라?\"" << endl;
	cout << "\"귀여운 강아지 영상이 추천에 떠 있다.\"" << endl;
	cout << "\"해야할 일이 아직 남았는데... 이것만 보고 할까?\"" << endl;
	while (true) {
		cout << "1. 강아지 영상을 본다  2. 남은 할 일을 한다" << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}

		if (select == 1) {
			cout << "\"강아지가 너무 귀엽다... 하나만 더 보자.\"" << endl;
			cout << "\"어라? 언제 이렇게 시간이 지났지?\"" << endl;
			cout << "머리는 식었지만 집중력이 완전히 깨져버렸다." << endl;
			cout << "체력이 20 증가했다! 코딩력이 20 감소했다." << endl;
			character->setHP(character->getHP() + 20);
			character->setATK(character->getATK() - 20);
			break;
		}
		else if (select == 2) {
			cout << "지금은 참아야 한다." << endl;
			cout << "유튜브를 끄고 다시 작성하던 코드로 돌아간다." << endl;
			cout << "집중한 덕분에 작업이 생각보다 빨리 끝났다." << endl;
			cout << "평소보다 집중력이 좋았던 것 같다." << endl;
			cout << "코딩력이 10 증가했다!" << endl;
			character->setATK(character->getATK() + 10);
			break;
		}
		else {
			cout << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}
	m_Count++;
}
void YouTubeAlgorithmEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}



void MidnightDebugEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 2);
	int RandNum = dis(gen);

	cout << "====================새벽 버그 수정 이벤트 발생!!!====================" << endl;
	cout << "\"어라 벌써 새벽 1시네. 언제 시간이 이렇게 지나간거지.\"" << endl;
	cout << "\n조금만 더 해보면 오류를 고칠 수 있을 거 같은데.\n" << endl;
	cout << "\n하지만 내일도 일정이 있는데 어떻게하지?\n" << endl;
	while (true) {
		cout << "1. 오류를 고쳐본다  2. 자러간다" << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}

		if (select == 1) {
			if (RandNum == 0 || RandNum == 1) {
				cout << "\n휴.. 시간이 좀 걸리기는 했지만 결국 고쳤다!\n" << endl;
				cout << "\n오류를 수정하면서 잘못 알고있던 개념도 제대로 알게됐네.\n" << endl;
				cout << "\n고쳐보기를 잘했다!!\n" << endl;
				cout << "오류를 성공적으로 수정했다." << endl;
				cout << "코딩력이 20 증가했다! 체력이 10 감소했다." << endl;
				character->setATK(character->getATK() + 20);
				character->setHP(character->getHP() - 10);
				break;
			}
			else {
				cout << "\n벌써 새벽 3시라고?? 금방 끝날 줄 알았는데 언제 끝나는거지...\n" << endl;
				cout << "\n그냥 자고 일어나서 할껄 망했다...\n" << endl;
				cout << "오류를 수정하지 못했다." << endl;
				cout << "체력이 20 감소했다." << endl;
				character->setHP(character->getHP() - 20);
				break;
			}

		}
		else if (select == 2) {
			cout << "\n무리하지말고 자자. 일어나서 하는게 집중이 더 잘될꺼야.\n" << endl;
			cout << "오류를 수정하지 않고 잠을 잤다." << endl;
			cout << "체력이 10 증가했다!" << endl;
			character->setHP(character->getHP() + 10);
			break;
		}
		else {
			cout << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}

	m_Count++;
}
void MidnightDebugEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}



void CodeCopyEvent::EventEffect(Character* character, GameManager* gm) {
	cout << "====================코드 카피 이벤트 발생!!!====================" << endl;
	cout << "\"벌써 10시라고?! 과제 제출 시간이 2시간 밖에 안남았네..\"" << endl;
	cout << "'시간 안에 못끝낼거 같은데 어떻게하지...'" << endl;
	cout << "고민하고 있던 당신의 눈 앞에 아까검색해뒀던 제미나이의 코드가 보인다." << endl;
	while (true) {
		cout << "1. 복사해서 제출한다  2. 작성한만큼 제출한다" << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}

		if (select == 1) {
			cout << "'그래 일단 과제 제출이 먼저지.'" << endl;
			cout << "'일단 제출하고 나중에 복습해봐야겠다.'" << endl;
			cout << "과제 제출을 완료했다." << endl;
			cout << "하지만 후에 본 테스트에서 같은 문제를 똑같이 틀렸다." << endl;
			cout << "코딩력이 10 감소했다." << endl;
			character->setATK(character->getATK() - 10);
			break;
		}
		else if (select == 2) {
			cout << "'제미나이의 코드를 베껴서 제출하면 실력이 늘지 않을꺼야.'" << endl;
			cout << "'지금 작성한 것까지만 제출하고 개념을 다시 정리해보자.'" << endl;
			cout << "작성한만큼만 과제를 제출했다." << endl;
			break;
		}
		else {
			cout << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}
	m_Count++;
}
void CodeCopyEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}



void ZepGambleEvent::EventEffect(Character* character, GameManager* gm) {
	int Choice;
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 1); // 0 = 짝, 1 = 홀
	int result = dis(gen);
	cout << "====================ZEP코인 겜블링 이벤트 발생!!!====================" << endl;
	cout << "쉬는 시간, ZEP에서 담임 매니저님이 이상한 사이트를 추천했다." << endl;
	cout << "\"ZEP 코인 홀짝 맞추기!\"" << endl;
	cout << "\n성공시 200 ZEP코인 획득! 시도 비용 100 ZEP코인\n" << endl;
	cout << "\n재밌어 보이는데... 한 번만 해볼까?\n" << endl;
	while (true) {
		cout << "1. 해본다  2. 안한다" << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}
		if (select == 1) {
			if (character->getGold() >= 100) {			// 현재 가진 돈이 100원 이상일 때 진행
				while (true) {
					cout << "\n1. 홀  2. 짝  당신의 선택은??\n" << endl;
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
						cout << "1번 또는 2번을 선택해주세요." << endl;
					}
				}
				int userPick = (Choice == 1) ? 1 : 0;
				cout << "결과는..." << endl;
				if (userPick == result) {
					cout << "정답이다!" << endl;
					cout << "운이 따랐다! 도파민과 함께 코인이 들어온다." << endl;
					cout << "200 ZEP코인을 획득했다!" << endl;
					character->setGold(character->getGold() + 200);
					break;
				}
				else {
					cout << "틀렸다..." << endl;
					cout << "순식간에 코인이 사라졌다." << endl;
					cout << "\n역시 도박에 손을 대는게 아니였어...\n" << endl;
					cout << "100 ZEP코인을 잃었다." << endl;
					character->setGold(character->getGold() - 100);
					break;
				}
			}
			else {			// 100원이 없다면 이벤트 참여 실패
				cout << "\n보유하고 있는 ZEP코인이 모자라군요!\n" << endl;
				cout << "\n아쉽지만 다음 기회에 참여해야겠네요!\n" << endl;
				cout << "ZEP코인이 모자라서 겜블링에 참여하지 못했다." << endl;
				break;
			}
		}
		else if (select == 2) {			// 안한다 선택지 선택시 해당 과정 진행
			cout << "\"그래 어떻게 모은 돈인데 잃는다면 내가 어떻게 변할지 몰라..\"" << endl;
			cout << "\"건실하게 모아서 빨리 오토바이를 사야해.\"" << endl;
			cout << "겜블링에 참여하지 않았다." << endl;
			break;
		}
		else {
			cout << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}
	m_Count++;
}
void ZepGambleEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}

void FunctionNamingEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 3);
	int RandNum = dis(gen);

	cout << "====================함수 이름짓기 이벤트 발생!!!====================" << endl;
	cout << "\n계속 반복되는 이 부분을 함수로 만들면 코드가 짧아지겠는데?\n" << endl;
	cout << "\n새로 함수를 하나 만들어야겠다.\n" << endl;
	cout << "\n흠.. 함수 이름은 뭘로 하지.\n" << endl;
	cout << "\n뭘로 정할지 고민이 되네. 귀찮은데 대충 지어두고 나중에 수정할까?\n" << endl;
	while (true) {
		cout << "1. 고민해서 정하기  2. 대충짓기" << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}

		if (select == 1) {
			if (RandNum != 3) {
				cout << "\n저번에 적어뒀던 함수를 수정해야 하는데 어디에 있더라..\n" << endl;
				cout << "\n아 찾았다! 역시 이름을 잘 지어두니까 찾기 편하네.\n" << endl;
				cout << "이름 짓기를 잘해둔 덕분에 코드의 가독성이 좋아졌다." << endl;
				cout << "코딩력이 30 증가했다!" << endl;
				character->setATK(character->getATK() + 30);
				break;
			}
			else {
				cout << "\n휴 드디어 함수 이름을 정했다.\n" << endl;
				cout << "\n헉! 뭐야 벌써 1시간이나 지났잖아!\n" << endl;
				cout << "\n작성해야할 부분이 아직 산더미인데 망했다...\n" << endl;
				cout << "함수 이름을 짓는데 시간을 많이 사용해 코딩할 시간이 적어졌다." << endl;
				cout << "코딩력이 10 감소했다." << endl;
				character->setATK(character->getATK() - 10);
				break;
			}

		}
		else if (select == 2) {
			cout << "\n어라 저번에 만들어뒀던 함수를 어디에 넣어놨었지??\n" << endl;
			cout << "\n프로젝트 내용이 너무 많아져서 찾을 수가 없잖아.\n" << endl;
			cout << "\n다음에는 만들 때 기능에 맞춰 이름을 지어야겠다...\n" << endl;
			cout << "만들어뒀던 함수를 찾는데 시간을 날려 코딩할 시간이 적어졌다." << endl;
			cout << "코딩력이 20 감소했다." << endl;
			character->setATK(character->getATK() - 20);
			break;
		}
		else {
			cout << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}

	m_Count++;
}
void FunctionNamingEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}



void LegacyCodeEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 3);
	int RandNum = dis(gen);

	cout << "====================누군가의 코드 이벤트 발생!!!====================" << endl;
	cout << "'이 프로젝트... 예전에 다른 사람이 만들다가 그만둔건가?'" << endl;
	cout << "'코드에 주석도 하나도 없고 변수 이름이 a, b, c밖에 없네..'" << endl;
	cout << "'공부하던 것도 끝나서 마침 시간도 남는데 한 번 분석해볼까?'" << endl;
	while (true) {
		cout << "1. 분석해보기  2. 못 본 척 지나가기" << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}

		if (select == 1) {
			if (RandNum != 3) { // 75% 확률로 성공
				cout << "'아하! 이래서 이 부분을 이렇게 작성한거구나!'" << endl;
				cout << "'확실히 남이 작성해둔 코드를 분석하는 것도 큰 도움이 되는구나.'" << endl;
				cout << "코드를 분석하는데 성공했습니다! 코드를 보는 눈이 좋아집니다." << endl;
				cout << "코딩력이 40 증가했다!" << endl;
				character->setATK(character->getATK() + 40);
				break;
			}
			else { // 25% 확률로 실패
				cout << "'어... 이게 여기서 왜 호출되지?'" << endl;
				cout << "'어라?? 이건 왜 실행이 안되지??'" << endl;
				cout << "'건드리지말껄.. 머리가 너무 아프다...'" << endl;
				cout << "코드를 분석하는데 실패했습니다. 머릿속이 복잡해집니다." << endl;
				cout << "코딩력이 15 감소했다." << endl;
				character->setATK(character->getATK() - 15);
				break;
			}
		}
		else if (select == 2) {
			cout << "'얼마만의 자유시간인데 오늘은 좀 쉬자'" << endl;
			cout << "'그런데 처음부터 다시 만드려니까 생각보다 시간이 너무 오래 걸리네..'" << endl;
			cout << "'아예 처음부터 다시 설계하느라 오늘 진도를 하나도 못 나갔어.'" << endl;
			break;
		}
		else {
			cout << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << endl;
		}
	}

}
void LegacyCodeEvent::EventCount() {
	cout << "이벤트 조우 횟수: " << m_Count << endl;
}