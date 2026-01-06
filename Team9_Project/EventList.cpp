#include "EventList.h"
#include "Utils.h"
#include "GameManager.h"
#include "Character.h"
#include <iostream>
#include <random>
#include <windows.h>

using namespace std;

void BuyBookEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 2);
	int RandNum = dis(gen);

	cout << Color::GOLD << "====================서적 할인 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::BRIGHT_WHITE << "인터넷 서칭을 하던 중 원하던 C++ 강의 서적을 발견했다!" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"평소보다 저렴한 가격이잖아? 구매할까?\"" << Color::BRIGHT_WHITE << " (" << Color::BRIGHT_YELLOW << "구매 시 100 ZEP코인이 소모됩니다." << Color::BRIGHT_WHITE << ")" << Color::RESET << endl;
	Sleep(500);
	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 구매한다  2. 구매하지 않는다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			if (character->getGold() >= 100) {
				character->setGold(character->getGold() - 100);
				cout << Color::BRIGHT_YELLOW << "100 ZEP코인을 지불했습니다." << Color::RESET << endl;
				Sleep(500);
				if (RandNum == 0 || RandNum == 1) {
					int gain = character->getLevel() * 3;
					cout << Color::BRIGHT_WHITE << "원하던 책이 잘 도착했습니다!" << Color::RESET << endl;
					Sleep(500);
					cout << Color::BRIGHT_WHITE << "배송받은 책을 읽고 지식이 늘었습니다!" << Color::RESET << endl;
					cout << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
					character->setATK(character->getATK() + gain);
					break;
				}
				else {
					cout << Color::CYAN << "\"배송된 박스가 생각보다 무겁다?!\"" << Color::RESET << endl;
					Sleep(500);
					cout << Color::BRIGHT_WHITE << "박스 안에는 묵직한 벽돌 뿐이였다..." << Color::RESET << endl;
					Sleep(500);
					cout << Color::CYAN << "\"안돼... 내 돈....\"" << Color::RESET << endl;
					Sleep(500);
					cout << Color::ORANGE << "사기를 당해버렸다." << Color::RESET << endl;
					break;
				}
			}
			else {
				cout << Color::CYAN << "\"생각해보니 탈 것을 산다고 ZEP코인을 썼었지..\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"나중에 돈이 생기면 사야겠다..\"" << Color::RESET << endl;
				break;
			}
		}
		else if (select == 2) {
			cout << Color::CYAN << "\"저 가격에 올라올 수가 없는데... 사기인가?\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"불안하니 사지 말아야지\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "책을 구매하지 않았다." << Color::RESET << endl;
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}
}




void SurpriseSessionEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 3);
	int RandNum = dis(gen);

	cout << Color::GOLD << "====================깜짝 세션 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::BRIGHT_WHITE << "과제를 하던 중 슬랙에 알림이 울린다." << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"튜터님의 깜짝세션 개최!\"" << Color::BRIGHT_WHITE << " 참여하시겠습니까?" << Color::RESET << endl;
  	Sleep(500);
	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 참여한다  2. 참여하지 않는다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			if (RandNum != 3) {
				int gain = character->getLevel() * 2;
				cout << Color::BRIGHT_WHITE << "튜터님의 명강의를 들었더니 개념이 확실히 잡혔다." << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "헷갈리던 개념이 잡히고 머리가 맑아진다." << Color::RESET << endl;
				cout << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
				character->setATK(character->getATK() + gain);
				break;
			}
			else {
				int gain = character->getLevel() * 2;
				int loss = static_cast<int>(character->getMaxHP() * 0.05);
				cout << Color::CYAN << "\"실력향상에는 반복학습이 최고죠!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "튜터님께서 추가과제를 주셨다...." << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"안... 안돼! 이건 꿈이야!!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::LIME << "코딩력이 " << gain << " 증가했다! " << Color::ORANGE << "체력이 " << loss << " 감소했다." << Color::RESET << endl;
				character->setATK(character->getATK() + gain);
				character->setHP(max(1, character->getHP() - loss));
				break;
			}
		}
		else if (select == 2) {
			cout << Color::CYAN << "\"과제 제출이 얼마 남지 않았으니까 지금은 과제에 집중하자.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "깜짝 세션에 참여하지 않았다." << Color::RESET << endl;
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}
}




void TILIsImportantEvent::EventEffect(Character* character, GameManager* gm) {
	cout << Color::GOLD << "====================TIL 작성 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"드디어 공부가 끝났다 이제 쉬어야지...\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"인생이 별거 있나 침대에 누워서 핸드폰 보는 이게 인생이지.\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"아 맞다! 오늘 TIL을 안썼네.\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"다시 일어나기 너무 귀찮은데...\"" << Color::RESET << endl;
	Sleep(500);

	while (true) {
		cout << Color::BRIGHT_WHITE << "1. TIL을 작성한다  2. 작성하지 않는다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			cout << Color::CYAN << "\"그래도 TIL 작성은 중요하지. 오늘 공부를 복습할겸 작성해보자\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"휴 다 작성했다. 이젠 진짜 자야지...\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "TIL을 작성하고 제출을 완료했다." << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "제출한 TIL이 우수 TIL로 선정되었다!" << Color::RESET << endl;
			cout << Color::BRIGHT_YELLOW << "500 ZEP코인을 획득했다!" << Color::RESET << endl;
			character->setGold(character->getGold() + 500);
			break;
		}
		else if (select == 2) {
			int gain = static_cast<int>(character->getMaxHP() * 0.05);
			cout << Color::CYAN << "\"너무 힘들어서 일어날 수가 없다...\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"그래 하루만 쉬자... 하루 쉬는 건데 별일이야 있겠어?\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "TIL을 작성하지 않았다." << Color::RESET << endl;
			cout << Color::LIME << "적당한 휴식으로 체력이 " << gain << " 회복됐다." << Color::RESET << endl;
			character->setHP(min(character->getMaxHP(), character->getHP() + gain));
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}
}




void DrinkCaffeineEvent::EventEffect(Character* character, GameManager* gm) {
	double health = static_cast<double>(character->getHP()) / character->getMaxHP();

	cout << Color::GOLD << "====================카페인 섭취 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"오늘도 해야할 공부가 많아서 일찍 자기는 틀렸구나...\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"그런데 너무 졸려서 집중이 안되네...\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"최근에 많이 먹었는데 오늘도 에너지드링크를 마셔야하나?\"" << Color::RESET << endl;
	Sleep(500);

	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 마신다  2. 마시지 않는다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			if (health >= 0.5) {
				int gain = character->getLevel() * 2;
				cout << Color::CYAN << "\"역시 에너지 드링크야. 먹으니까 눈이 확 떠지네.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"조금만 더 힘내서 해보자!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "에너지 드링크 덕분에 집중력이 올라서 성공적으로 공부를 끝마쳤다!" << Color::RESET << endl;
				cout << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
				character->setATK(character->getATK() + gain);
				break;
			}
			else {
				int loss = character->getLevel() * 2;
				cout << Color::BRIGHT_WHITE << "에너지 드링크 덕분에 오늘 공부를 다했다." << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"이제 자러가야지.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"어라? 잠이 오지 않는다. 내일 아침 일찍 일어나야하는데 큰일났다!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "다음날 생활패턴이 망가져 공부를 망쳤다." << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"적당히 마실껄...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::ORANGE << "코딩력이 " << loss << " 감소했다." << Color::RESET << endl;
				character->setATK(character->getATK() - loss);
				break;
			}
		}
		else if (select == 2) {
			int gain = static_cast<int>(character->getMaxHP() * 0.05);
			cout << Color::CYAN << "\"최근에 너무 많이 마셨으니까 오늘은 마시지 말자.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"잠도 깰겸 물 마시고 산책이나 하고 와야지.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "에너지 드링크를 마시지 않았다." << Color::RESET << endl;
			cout << Color::LIME << "체력이 " << gain << " 증가했다!" << Color::RESET << endl;
			character->setHP(min(character->getMaxHP(), character->getHP() + gain));
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}
}




void FixCodeEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 2);
	int RandNum = dis(gen);

	cout << Color::GOLD << "====================과제 수정 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::BRIGHT_WHITE << "과제 제출 마감 하루 전" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"휴 드디어 끝냈다. 제출하기 전에 오타는 없는지 다시 확인해봐야지\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"어우 내가 짠 코드가 이렇게 더러웠었나.. 심각하네.\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"다시보니까 다시 수정하면 훨씬 간단하게 바꿀 수 있겠는데?\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"하루 정도 시간도 남았는데 수정해볼까?\"" << Color::RESET << endl;
	Sleep(500);

	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 수정한다  2. 수정하지 않는다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			if (RandNum == 0 || RandNum == 1) {
				int gain = character->getLevel() * 7;
				cout << Color::CYAN << "\"역시 함수와 클래스를 잘 활용하니까 코드가 훨씬 짧아지네\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"수정하면서 배웠던 내용 활용도 해보고 복습도 됐네. 수정하기를 잘했다!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "과제를 성공적으로 수정해서 제출했다." << Color::RESET << endl;
				cout << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
				character->setATK(character->getATK() + gain);
				break;
			}
			else {
				int gain = character->getLevel() * 7;
				int loss = static_cast<int>(character->getMaxHP() * 0.05);
				cout << Color::BRIGHT_WHITE << "수정하기 시작한지 어언 몇시간째... 오류가 멈추지 않는다..." << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"어디서부터 잘못된걸까... 여기까지 왔는데 과제 제출을 못할 수는 없어...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"오늘도 놀기는 글렀구나...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "아슬아슬하게 수정해서 과제를 제출했다." << Color::RESET << endl;
				cout << Color::LIME << "코딩력이 " << gain << " 증가했다! " << Color::ORANGE << "체력이 " << loss << " 감소했다." << Color::RESET << endl;
				character->setATK(character->getATK() + gain);
				character->setHP(max(1, character->getHP() - loss));
				break;
			}
		}
		else if (select == 2) {
			int gain = static_cast<int>(character->getMaxHP() * 0.1);
			cout << Color::CYAN << "\"과제를 완성한게 어디냐\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"일단 이 상태로 제출하고 나중에 궁금한 점이 생기면 인터넷을 찾아보자.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"오랜만에 게임이나 해볼까?\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "과제를 수정하지 않았다. 휴식을 취해서 건강이 좋아졌다." << Color::RESET << endl;
			cout << Color::LIME << "체력이 " << gain << " 증가했다!" << Color::RESET << endl;
			character->setHP(min(character->getMaxHP(), character->getHP() + gain));
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}

	
}




void SOSRequestEvent::EventEffect(Character* character, GameManager* gm) {
	cout << Color::GOLD << "====================팀원의 SOS요청 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"띠링!\"" << Color::RESET << Color::BRIGHT_WHITE << " 팀프로젝트 맡은 파트의 코드를 작성하던 중 슬랙의 알림이 울린다." << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"팀원: 팀장님 지금 작성한 코드에서 오류가 너무 많이나와요.. 도와주세요 ㅜㅜ \"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::BRIGHT_WHITE << "확인해보니 에러가 발생하는 곳이 전체 코드의 절반 이상이다." << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"지금 내가 맡은 파트도 마무리해야하는데...\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::BRIGHT_WHITE << "팀원을 도와줄까?" << Color::RESET << endl;
	Sleep(500);
	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 팀원을 도와준다  2. 내 할 일을 한다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);

		if (select == 1) {
			int loss = static_cast<int>(character->getMaxHP() * 0.05);
			int gain = character->getLevel() * 2;
			cout << Color::CYAN << "\"그래 결국 팀 프로젝트니까 도와주자.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "팀원과 코드를 수정해본다." << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "예상했던 시간보다 더 걸리긴 했지만 오류를 전부 수정했다." << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"늦게 발견해서 나중에 수정했으면 큰일날 뻔 했다. 도와주길 잘했다.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "조금 힘들긴했지만 결과물을 완성했다!" << Color::RESET << endl;
			cout << Color::ORANGE << "체력이 " << loss << " 감소했다. " << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
			if (character->getHP() - loss >= 1) {
				character->setHP(character->getHP() - loss);
			}
			else {
				character->setHP(1);
			}
			character->setATK(character->getATK() + gain);
			break;
		}
		else if (select == 2) {
			int loss = character->getLevel() * 2;
			cout << Color::CYAN << "\"지금은 내 코가 석자다.. 미안하지만 거절해야겠다.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"나: 지금은 제 파트도 못 끝내서 나중에 도와드릴께요 죄송합니다.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"팀원: 아 네 알겠습니다... 제가 한번 수정해볼께요.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"그렇게 문제가 일단락되는 줄 알았다.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "하지만 나중에 내가 마주하게 된 것은 감당할 수 없이 늘어나버린 오류였다." << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "수정하지 못한 오류가 남아서 결과물을 제출하지 못했다." << Color::RESET << endl;
			cout << Color::ORANGE << "코딩력이 " << loss << " 감소했다." << Color::RESET << endl;
			character->setATK(character->getATK() - loss);
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}

	

}




void YouTubeAlgorithmEvent::EventEffect(Character* character, GameManager* gm) {
	cout << Color::GOLD << "====================알고리즘의 유혹 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::BRIGHT_WHITE << "잠깐 쉬려고 유튜브를 켰다." << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"어라? 귀여운 강아지 영상이 추천에 떠 있다.\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"해야할 일이 아직 남았는데... 이것만 보고 할까?\"" << Color::RESET << endl;
	Sleep(500);

	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 강아지 영상을 본다  2. 남은 할 일을 한다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			int gain = static_cast<int>(character->getMaxHP() * 0.05);
			int loss = character->getLevel() * 2;
			cout << Color::CYAN << "\"강아지가 너무 귀엽다... 하나만 더 보자.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"어라? 언제 이렇게 시간이 지났지?\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "머리는 식었지만 집중력이 완전히 깨져버렸다." << Color::RESET << endl;
			cout << Color::LIME << "체력이 " << gain << " 증가했다! " << Color::ORANGE << "코딩력이 " << loss << " 감소했다." << Color::RESET << endl;
			if (character->getHP() + gain >= character->getMaxHP()) {
				character->setHP(character->getMaxHP());
			}
			else {
				character->setHP(character->getHP() + gain);
			}
			character->setATK(character->getATK() - loss);
			break;
		}
		else if (select == 2) {
			int gain = character->getLevel() * 2;
			cout << Color::CYAN << "\"지금은 참아야 한다.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "유튜브를 끄고 다시 작성하던 코드로 돌아간다." << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "집중한 덕분에 작업이 생각보다 빨리 끝났다." << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "평소보다 집중력이 좋았던 것 같다." << Color::RESET << endl;
			cout << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
			character->setATK(character->getATK() + gain);
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}
	
}




void MidnightDebugEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 2);
	int RandNum = dis(gen);

	cout << Color::GOLD << "====================새벽 버그 수정 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"어라 벌써 새벽 1시네. 언제 시간이 이렇게 지나간거지.\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"조금만 더 해보면 오류를 고칠 수 있을 거 같은데.\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"하지만 내일도 일정이 있는데 어떻게하지?\"" << Color::RESET << endl;
	Sleep(500);
	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 오류를 고쳐본다  2. 자러간다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			if (RandNum == 0 || RandNum == 1) {
				int gain = character->getLevel() * 4;
				int loss = static_cast<int>(character->getMaxHP() * 0.05);
				cout << Color::CYAN << "\"휴.. 시간이 좀 걸리기는 했지만 결국 고쳤다!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"오류를 수정하면서 잘못 알고있던 개념도 제대로 알게됐네.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"고쳐보기를 잘했다!!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "오류를 성공적으로 수정했다." << Color::RESET << endl;
				cout << Color::LIME << "코딩력이 " << gain << " 증가했다! " << Color::ORANGE << "체력이 " << loss << " 감소했다." << Color::RESET << endl;
				character->setATK(character->getATK() + gain);
				if (character->getHP() - loss >= 1) {
					character->setHP(character->getHP() - loss);
				}
				else {
					character->setHP(1);
				}
				break;
			}
			else {
				int loss = static_cast<int>(character->getMaxHP() * 0.1);
				cout << Color::CYAN << "\"벌써 새벽 3시라고?? 금방 끝날 줄 알았는데 언제 끝나는거지...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"그냥 자고 일어나서 할껄 망했다...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "오류를 수정하지 못했다." << Color::RESET << endl;
				cout << Color::ORANGE << "체력이 " << loss << " 감소했다." << Color::RESET << endl;
				if (character->getHP() - loss >= 1) {
					character->setHP(character->getHP() - loss);
				}
				else {
					character->setHP(1);
				}
				break;
			}

		}
		else if (select == 2) {
			int gain = static_cast<int>(character->getMaxHP() * 0.05);
			cout << Color::CYAN << "\"무리하지말고 자자. 일어나서 하는게 집중이 더 잘될꺼야.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "오류를 수정하지 않고 잠을 잤다." << Color::RESET << endl;
			cout << Color::LIME << "체력이 " << gain << " 증가했다!" << Color::RESET << endl;
			if (character->getHP() + gain >= character->getMaxHP()) {
				character->setHP(character->getMaxHP());
			}
			else {
				character->setHP(character->getHP() + gain);
			}
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}

	
}




void CodeCopyEvent::EventEffect(Character* character, GameManager* gm) {
	cout << Color::GOLD << "====================코드 카피 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"벌써 10시라고?! 과제 제출 시간이 2시간 밖에 안남았네..\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"시간 안에 못끝낼거 같은데 어떻게하지...\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::BRIGHT_WHITE << "고민하고 있던 당신의 눈 앞에 아까검색해뒀던 제미나이의 코드가 보인다." << Color::RESET << endl;
	Sleep(500);
	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 복사해서 제출한다  2. 작성한만큼 제출한다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			int loss = character->getLevel() * 2;
			cout << Color::CYAN << "\"그래 일단 과제 제출이 먼저지.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"일단 제출하고 나중에 복습해봐야겠다.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "과제 제출을 완료했다." << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "하지만 후에 본 테스트에서 같은 문제를 똑같이 틀렸다." << Color::RESET << endl;
			cout << Color::ORANGE << "코딩력이 " << loss << " 감소했다." << Color::RESET << endl;
			character->setATK(character->getATK() - loss);
			break;
		}
		else if (select == 2) {
			cout << Color::CYAN << "\"제미나이의 코드를 베껴서 제출하면 실력이 늘지 않을꺼야.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"지금 작성한 것까지만 제출하고 개념을 다시 정리해보자.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "작성한만큼만 과제를 제출했다." << Color::RESET << endl;
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}
	
}




void ZepGambleEvent::EventEffect(Character* character, GameManager* gm) {
	int Choice;
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 1); // 0 = 짝, 1 = 홀
	int result = dis(gen);
	cout << Color::GOLD << "====================ZEP코인 겜블링 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::BRIGHT_WHITE << "쉬는 시간, ZEP에서 담임 매니저님이 이상한 사이트를 추천했다." << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"ZEP 코인 홀짝 맞추기!\"" << Color::RESET << endl;
	cout << Color::BRIGHT_YELLOW << "\"성공시 200 ZEP코인 획득! 시도 비용 100 ZEP코인\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"재밌어 보이는데... 한 번만 해볼까?\"" << Color::RESET << endl;
	Sleep(500);
	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 해본다  2. 안한다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}
		Sleep(500);
		if (select == 1) {
			if (character->getGold() >= 100) {			// 현재 가진 돈이 100원 이상일 때 진행
				while (true) {
					cout << Color::CYAN << "\"1. 홀  2. 짝  당신의 선택은??\"" << Color::RESET << endl;
					cin >> Choice;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << Color::BRIGHT_WHITE << "잘못된 값을 입력하셨습니다. 숫자만 입력해주세요." << Color::RESET << endl;
						continue;
					}
					if (Choice == 1 || Choice == 2) {
						break;
					}
					else {
						cout << Color::BRIGHT_WHITE << "1번 또는 2번을 선택해주세요." << Color::RESET << endl;
					}
				}
				Sleep(500);
				int userPick = (Choice == 1) ? 1 : 0;
				cout << Color::BRIGHT_WHITE << "결과는..." << Color::RESET << endl;
				Sleep(1000);
				if (userPick == result) {
					cout << Color::BRIGHT_WHITE << "정답이다!" << Color::RESET << endl;
					Sleep(500);
					cout << Color::BRIGHT_WHITE << "운이 따랐다! 도파민과 함께 코인이 들어온다." << Color::RESET << endl;
					cout << Color::BRIGHT_YELLOW << "200 ZEP코인을 획득했다!" << Color::RESET << endl;
					character->setGold(character->getGold() + 200);
					break;
				}
				else {
					cout << Color::ORANGE << "틀렸다... 순식간에 코인이 사라졌다." << Color::RESET << endl;
					Sleep(500);
					cout << Color::CYAN << "\"역시 도박에 손을 대는게 아니였어...\"" << Color::RESET << endl;
					cout << Color::BRIGHT_YELLOW << "100 ZEP코인을 잃었다." << Color::RESET << endl;
					character->setGold(character->getGold() - 100);
					break;
				}
			}
			else {			// 100원이 없다면 이벤트 참여 실패
				cout << Color::CYAN << "\"보유하고 있는 ZEP코인이 모자라군요!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"아쉽지만 다음 기회에 참여해야겠네요!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "ZEP코인이 모자라서 겜블링에 참여하지 못했다." << Color::RESET << endl;
				break;
			}
		}
		else if (select == 2) {			// 안한다 선택지 선택시 해당 과정 진행
			cout << Color::CYAN << "\"그래 어떻게 모은 돈인데 잃는다면 내가 어떻게 변할지 몰라..\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"건실하게 모아서 빨리 오토바이를 사야해.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "겜블링에 참여하지 않았다." << Color::RESET << endl;
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}
	
}


void FunctionNamingEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 3);
	int RandNum = dis(gen);

	cout << Color::GOLD << "====================함수 이름짓기 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"계속 반복되는 이 부분을 함수로 만들면 코드가 짧아지겠는데?\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"새로 함수를 하나 만들어야겠다.\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"흠.. 함수 이름은 뭘로 하지.\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"뭘로 정할지 고민이 되네. 귀찮은데 대충 지어두고 나중에 수정할까?\"" << Color::RESET << endl;
	Sleep(500);
	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 고민해서 정하기  2. 대충짓기" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			if (RandNum != 3) {
				int gain = character->getLevel() * 2;
				cout << Color::CYAN << "\"아 찾았다! 역시 이름을 잘 지어두니까 찾기 편하네.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "이름 짓기를 잘해둔 덕분에 코드의 가독성이 좋아졌다." << Color::RESET << endl;
				cout << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
				character->setATK(character->getATK() + gain);
				break;
			}
			else {
				int loss = character->getLevel() * 2;
				cout << Color::CYAN << "\"휴 드디어 함수 이름을 정했다.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"헉! 뭐야 벌써 1시간이나 지났잖아!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"작성해야할 부분이 아직 산더미인데 망했다...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "함수 이름을 짓는데 시간을 많이 사용해 코딩할 시간이 적어졌다." << Color::RESET << endl;
				cout << Color::ORANGE << "코딩력이 " << loss << " 감소했다." << Color::RESET << endl;
				character->setATK(character->getATK() - loss);
				break;
			}
		}
		else if (select == 2) {
			int loss = character->getLevel() * 2;
			cout << Color::CYAN << "\"어라 저번에 만들어뒀던 함수를 어디에 넣어놨었지??\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"프로젝트 내용이 너무 많아져서 찾을 수가 없잖아.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"다음에는 만들 때 기능에 맞춰 이름을 지어야겠다...\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "만들어뒀던 함수를 찾는데 시간을 날려 코딩할 시간이 적어졌다." << Color::RESET << endl;
			cout << Color::ORANGE << "코딩력이 " << loss << " 감소했다." << Color::RESET << endl;
			character->setATK(character->getATK() - loss);
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}

	
}




void LegacyCodeEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 3);
	int RandNum = dis(gen);

	cout << Color::GOLD << "====================누군가의 코드 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"이 프로젝트... 예전에 다른 사람이 만들다가 그만둔건가?\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"코드에 주석도 하나도 없고 변수 이름이 a, b, c밖에 없네..\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"공부하던 것도 끝나서 마침 시간도 남는데 한 번 분석해볼까?\"" << Color::RESET << endl;
	Sleep(500);
	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 분석해보기  2. 못 본 척 지나가기" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			if (RandNum != 3) {
				int gain = character->getLevel() * 3;
				cout << Color::CYAN << "\"아하! 이래서 이 부분을 이렇게 작성한거구나!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"확실히 남이 작성해둔 코드를 분석하는 것도 큰 도움이 되는구나.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "코드를 분석하는데 성공했습니다! 코드를 보는 눈이 좋아집니다." << Color::RESET << endl;
				cout << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
				character->setATK(character->getATK() + gain);
				break;
			}
			else {
				int loss = character->getLevel() * 2;
				cout << Color::CYAN << "\"어... 이게 여기서 왜 호출되지?\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"어라?? 이건 왜 실행이 안되지??\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"건드리지말껄.. 머리가 너무 아프다...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "코드를 분석하는데 실패했습니다. 머릿속이 복잡해집니다." << Color::RESET << endl;
				cout << Color::ORANGE << "코딩력이 " << loss << " 감소했다." << Color::RESET << endl;
				character->setATK(character->getATK() - loss);
				break;
			}
		}
		else if (select == 2) {
			int gain = static_cast<int>(character->getMaxHP() * 0.05);
			cout << Color::CYAN << "\"얼마만의 자유시간인데 오늘은 좀 쉬자\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"오랜만에 친구들이랑 게임이나 해볼까\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"친구들은 지금 뭐하려나. 연락해보자.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "친구들과 놀며 휴식을 취했다." << Color::RESET << endl;
			cout << Color::LIME << "체력이 " << gain << " 증가했다!" << Color::RESET << endl;
			if (character->getHP() + gain >= character->getMaxHP()) {
				character->setHP(character->getMaxHP());
			}
			else {
				character->setHP(character->getHP() + gain);
			}
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}

	
}




void NappingEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 3);
	int RandNum = dis(gen);

	cout << Color::GOLD << "====================낮잠 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"아... 점심 먹고 나니까 계속 잠이 오네.\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"모니터에 있는 내용이 머릿속에 제대로 들어오지가 않는다.\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"딱 15분만 자고 일어나면 잠이 깰 것 같은데...\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"잠깐만 자고 올까? 아니면 세수를 하고 올까?\"" << Color::RESET << endl;
	Sleep(500);

	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 잠깐 낮잠자기  2. 세수하고 오기" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			if (RandNum != 3) {
				int gainATK = character->getLevel() * 2;
				int gainHP = static_cast<int>(character->getMaxHP() * 0.1);
				cout << Color::CYAN << "\"낮잠 자고 일어나니까 너무 개운하다.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"역시 너무 피곤하면 해소를 해줘야하는구나.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"좋아. 아까 하던 공부를 마저해볼까!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "낮잠으로 컨디션이 회복됐다! 집중력이 올라갔다!" << Color::RESET << endl;
				cout << Color::LIME << "코딩력이 " << gainATK << " 증가했다! 체력이 " << gainHP << " 증가했다!" << Color::RESET << endl;
				character->setATK(character->getATK() + gainATK);
				if (character->getHP() + gainHP >= character->getMaxHP()) {
					character->setHP(character->getMaxHP());
				}
				else {
					character->setHP(character->getHP() + gainHP);
				}
				break;
			}
			else {
				int loss = character->getLevel() * 2;
				cout << Color::CYAN << "\"어우 잘잤다. 너무 상쾌하네.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"뭐지? 불안하다... 왜 이렇게 상쾌한거지?\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"뭐야! 2시간이나 자버렸잖아! 공부하던 것도 안끝났는데 망했다...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "알람 소리를 듣지 못해 숙면을 취했다. 오늘치 공부를 망쳤다." << Color::RESET << endl;
				cout << Color::ORANGE << "코딩력이 " << loss << " 감소했다." << Color::RESET << endl;
				character->setATK(character->getATK() - loss);
				break;
			}
		}
		else if (select == 2) {
			int gain = character->getLevel() * 2;
			cout << Color::CYAN << "\"세수하니까 그래도 잠이 깨네.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"집중해서 빨리 끝내고 쉬러 가야겠다.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"내가 어디까지 했더라..\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "세수로 잠을 깨고 공부를 진행했다." << Color::RESET << endl;
			cout << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
			character->setATK(character->getATK() + gain);
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}

	
}



void PartTimeJobEvent::EventEffect(Character* character, GameManager* gm) {
	cout << Color::GOLD << "====================야간 알바 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"ZEP에서 오토바이 깜짝 할인을 시작했잖아!\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"지금 가지고 있는 코인이 모자란데.. 야간 알바를 잠깐 해볼까?\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"야간 알바를 하게 되면 내일 공부를 못할텐데 어떻게 하지...\"" << Color::RESET << endl;
	Sleep(500);

	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 야간 알바 가기  2. 잠자기" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			int loss = character->getLevel() * 2;
			cout << Color::CYAN << "\"아... 죽을 것 같다... 그래도 오토바이를 살 수 있는 돈을 모았다.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"원하던 걸 살 수 있어서 다행이다..\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"공부는 어쩔 수 없지만 하루만 쉬어야겠다.. 너무 힘들어..\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "코인을 얻었지만 공부를 하지 못했다." << Color::RESET << endl;
			cout << Color::BRIGHT_YELLOW << "200 ZEP코인을 획득했다! " << Color::ORANGE << "코딩력이 " << loss << " 감소했다." << Color::RESET << endl;
			character->setGold(character->getGold() + 200);
			character->setATK(character->getATK() - loss);
			break;
		}
		else if (select == 2) {
			int gain = static_cast<int>(character->getMaxHP() * 0.1);
			cout << Color::CYAN << "\"그래 아무리 오토바이가 가지고 싶어도 컨디션 관리가 우선이지.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"지금은 자고 다음에 코인을 더 모아서 구매하자\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "컨디션 관리를 위해 야간 알바를 하지 않았다." << Color::RESET << endl;
			cout << Color::LIME << "체력이 " << gain << " 증가했다!" << Color::RESET << endl;
			if (character->getHP() + gain >= character->getMaxHP()) {
				character->setHP(character->getMaxHP());
			}
			else {
				character->setHP(character->getHP() + gain);
			}
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}

	
}




void VSUpdateEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 3);
	int RandNum = dis(gen);

	cout << Color::GOLD << "====================VS 업데이트 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"어 비주얼 스튜디오 버전 업데이트가 생겼네?\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"흠... 보안 패치도 있고 빌드 속도도 개선된다라... 해볼까?\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"근데 업데이트했다가 오류나면 큰일 나는데 어떻게 하지...\"" << Color::RESET << endl;
	Sleep(500);
	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 업데이트한다  2. 현재버전으로 한다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			if (RandNum != 2) {
				int gain = character->getLevel() * 2;
				cout << Color::CYAN << "\"와! 업데이트하니까 획실히 쾌적하다.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"빌드 시간도 확실히 줄어든 것 같아. 업데이트 하기를 잘했다!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "업데이트 후 코딩 효율이 상승했다!" << Color::RESET << endl;
				cout << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
				character->setATK(character->getATK() + gain);
				break;
			}
			else {
				int loss = character->getLevel() * 2;
				cout << Color::CYAN << "\"안돼!! 재부팅도 해봤는데 설치 오류가 계속 나오잖아...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"망했다... 오늘 하루종일 비주얼 스튜디오 재설치만 하겠네.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"이럴 줄 알았으면 그냥 쓸 걸 ㅠㅜ\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "업데이트 중 오류로 인해 개발 환경이 망가졌다." << Color::RESET << endl;
				cout << Color::ORANGE << "코딩력이 " << loss << " 감소했다." << Color::RESET << endl;
				character->setATK(character->getATK() - loss);
				break;
			}
		}
		else if (select == 2) {
			cout << Color::CYAN << "\"지금 괜히 건드렸다가 오류라도 나면 큰일나니까 일단 두자.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"지금은 업데이트보다는 작성하던 코드를 완성하는게 더 중요해.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "비주얼 스튜디오 업데이트를 진행하지 않았다." << Color::RESET << endl;
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}
	
}




void QuestionCodeEvent::EventEffect(Character* character, GameManager* gm) {
	cout << Color::GOLD << "====================튜터님께 질문 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"여기서 도대체 왜 에러가 발생하는거지...\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"2시간째 보고 있는데 도저히 이유를 모르겠다... 튜터님께 질문드려볼까?\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"스스로 해결하는 능력을 키우는 것도 중요하다고 하셨는데 어떻게 해야하지..\"" << Color::RESET << endl;
	Sleep(500);
	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 질문드리러 간다  2. 스스로 해결해본다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			int gain = character->getLevel() * 2;
			cout << Color::CYAN << "\"아하! 이렇게 해결하면 되는 거였군요! 감사합니다 튜터님!\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"튜터님의 설명덕분에 막힌 부분이 뚫렸다. 이제 다음 내용을 작성해볼까.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "튜터님의 설명덕분에 막혀있던 문제를 해결했다." << Color::RESET << endl;
			cout << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
			character->setATK(character->getATK() + gain);
			break;
		}
		else if (select == 2) {
			int gain = character->getLevel() * 4;
			int loss = static_cast<int>(character->getMaxHP() * 0.05);
			cout << Color::CYAN << "\"... 드디어 찾았다!! 여기 문장 때문에 오류가 발생하고 있었구나.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"이 오류 해결하는데만 몇시간을 사용했지만  덕분에 많이 성장한 것 같아.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"근데 너무 힘들다... 조금만 쉬자\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "오류를 해결하는데 시간이 오래걸렸지만 실력이 크게 상승했다!" << Color::RESET << endl;
			cout << Color::LIME << "코딩력이 " << gain << " 증가했다! " << Color::ORANGE << "체력이 " << loss << " 감소했다." << Color::RESET << endl;
			character->setATK(character->getATK() + gain);
			if (character->getHP() - loss >= 1) {
				character->setHP(character->getHP() - loss);
			}
			else {
				character->setHP(1);
			}
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}

	
}




void TemptationOfWeekendEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 3);
	int RandNum = dis(gen);

	cout << Color::GOLD << "====================주말의 유혹 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"드디어 주말이다.. 이제 드디어 쉴 수 있어...\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"그런데 생각해보니까 이번에 배운 포인터와 클래스가 아직 헷갈리는데..\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"주말에 복습을 해야하나? 그런데 주말에도 공부를 하면 너무 힘들 것 같은데..\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"어떻게 해야하지?\"" << Color::RESET << endl;
	Sleep(500);
	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 공부한다  2. 쉰다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			if (RandNum != 2) {
				int gain = character->getLevel() * 3;
				cout << Color::CYAN << "\"휴 이제야 좀 포인터와 클래스가 이해가 됐네.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"다음 진도가 나가기 전에 개념을 확실히 복습해 놓으니 안심이 된다.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"주말은 지나갔지만 알차게 보낸 것 같아!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "주말 추가 학습으로 실력이 향상됐다!" << Color::RESET << endl;
				cout << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
				character->setATK(character->getATK() + gain);
				break;
			}
			else {
				int loss = static_cast<int>(character->getMaxHP() * 0.1);
				cout << Color::CYAN << "\"주말까지 공부를 하는 건 무리였나? 너무 힘들다...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"너무 힘들고 피곤한데 내일이 월요일이라고?? 안돼...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "과도한 학습량으로 인해 번아웃이 왔다." << Color::RESET << endl;
				cout << Color::ORANGE << "체력이 " << loss << " 감소했다." << Color::RESET << endl;
				if (character->getHP() - loss >= 1) {
					character->setHP(character->getHP() - loss);
				}
				else {
					character->setHP(1);
				}
				break;
			}
		}
		else if (select == 2) {
			int gain = static_cast<int>(character->getMaxHP() * 0.1);
			cout << Color::CYAN << "\"그래 쉬는 시간도 있어야 공부할 때 더 잘되는 법이지.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"주말에는 맛있는 것도 먹고 푹 쉬자!\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "주말에 휴식을 취한 덕분에 건강이 좋아졌다!" << Color::RESET << endl;
			cout << Color::LIME << "체력이 " << gain << " 증가했다!" << Color::RESET << endl;
			if (character->getHP() + gain >= character->getMaxHP()) {
				character->setHP(character->getMaxHP());
			}
			else {
				character->setHP(character->getHP() + gain);
			}
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}

	}
	
}




void RelayQuizEvent::EventEffect(Character* character, GameManager* gm) {
	int correctCount = 0;

	cout << Color::GOLD << "====================깜짝 퀴즈 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"띠링!\"" << Color::BRIGHT_WHITE <<  " Slack에 알림이 울린다." << Color::RESET << endl;
	cout << Color::BRIGHT_WHITE << "깜짝 퀴즈! 모두 맞출 시 " << Color::BRIGHT_YELLOW << "200 ZEP코인" << Color::BRIGHT_WHITE << " 증정!" << Color::RESET << endl;
	Sleep(500);
	cout << Color::BRIGHT_WHITE << "강제적으로 퀴즈가 시작됐다!" << Color::RESET << endl;
	Sleep(500);
	while (true) {
		cout << Color::CYAN << "[1단계: 포인터의 이해]" << Color::RESET << endl;
		Sleep(500);
		cout << Color::BRIGHT_WHITE << "int a = 10; int* ptr = &a; *ptr = 20; 일 때, a의 값은?" << Color::RESET << endl;
		cout << Color::BRIGHT_WHITE << "1. 10  2. 20" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 2) {
			cout << Color::CYAN << "\"포인터의 기초가 잡혀있군요! 정답!\"" << Color::RESET << endl;
			Sleep(500);
			correctCount++;
			break;
		}
		else if (select == 1) {
			cout << Color::ORANGE << "\"기초 공부부터 다시 해야겠네요. 오답!\"" << Color::RESET << endl;
			Sleep(500);
			goto Failed;
		}
	}
	while (true) {
		cout << Color::CYAN << "[2단계: 클래스 상속]" << Color::RESET << endl;
		Sleep(500);
		cout << Color::BRIGHT_WHITE << "부모 클래스의 private 멤버를 자식 클래스에서 직접 접근할 수 있는가?" << Color::RESET << endl;
		cout << Color::BRIGHT_WHITE << "1. 가능하다  2. 불가능하다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(1500);
		if (select == 2) {
			cout << Color::CYAN << "\"캡슐화의 원리를 이해했군요! 정답!\"" << Color::RESET << endl;
			Sleep(500);
			correctCount++;
			break;
		}
		else if (select == 1) {
			cout << Color::ORANGE << "\"기초는 있지만 객체지향의 개념이 부족하네요. 오답!\"" << Color::RESET << endl;
			Sleep(500);
			goto Failed;
		}
	}
	while (true) {
		cout << Color::CYAN << "[3단계: 메모리 관리]" << Color::RESET << endl;
		Sleep(500);
		cout << Color::BRIGHT_WHITE << "C++에서 new로 할당한 메모리를 해제할 때 사용하는 키워드는?" << Color::RESET << endl;
		cout << Color::BRIGHT_WHITE << "1. delete    2. free" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(1500);
		if (select == 1) {
			cout << Color::CYAN << "\"동적할당을 이해하고 있군요! 정답!\"" << Color::RESET << endl;
			Sleep(500);
			correctCount++;
			break;
		}
		else if (select == 2) {
			cout << Color::ORANGE << "\"아직 동적할당까지 이해하지는 못했군요. 오답!\"" << Color::RESET << endl;
			Sleep(500);
			goto Failed;
		}
	}
	if (correctCount == 3) {
		int gain = character->getLevel() * 4;
		cout << Color::BRIGHT_WHITE << "====================================================" << Color::RESET << endl;
		cout << Color::LIME << "축하합니다! 모든 퀴즈를 맞췄습니다!" << Color::RESET << endl;
		cout << Color::BRIGHT_WHITE << "퀴즈를 전부 맞춰 자신감이 상승했다." << Color::RESET << endl;
		cout << Color::BRIGHT_YELLOW << "200 ZEP코인을 획득했다! " << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
		character->setGold(character->getGold() + 200);
		character->setATK(character->getATK() + gain);
		return;
	}
Failed:
	int loss = character->getLevel() * 2;
	cout << Color::BRIGHT_WHITE << "====================================================" << Color::RESET << endl;
	cout << Color::ORANGE << "\"깜짝 퀴즈를 틀렸습니다...\"" << Color::RESET << endl;
	cout << Color::BRIGHT_WHITE << "자신감이 감소했다." << Color::RESET << endl;
	cout << Color::ORANGE << "코딩력이 " << loss << " 감소했다." << Color::RESET << endl;
	character->setATK(character->getATK() - loss);
}




void HowSuccessEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 3);
	int RandNum = dis(gen);

	cout << Color::GOLD << "====================무지성 코드 성공 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"...??? 이 코드 왜 돌아가는거지? 오류가 나야하는데..?\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"결과가 나오긴 하네? 뭐지? 되면 안되는데?\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"어떻게 하지? 이대로 제출할까? 이유를 찾아야하나?\"" << Color::RESET << endl;
	Sleep(500);
	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 원인을 찾는다  2. 그냥 제출한다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			if (RandNum != 3) {
				int gain = character->getLevel() * 3;
				cout << Color::CYAN << "\"아 이 부분의 연산이 우연히 맞아서 작동되고 있었구나!\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"시간은 좀 걸렸지만 확실히 이유를 찾으니까 마음이 편하다.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "코드 분석을 통해 실력이 상승했다!" << Color::RESET << endl;
				cout << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
				character->setATK(character->getATK() + gain);
				break;
			}
			else {
				int loss = character->getLevel() * 2;
				cout << Color::CYAN << "\"큰일났다. 코드를 수정하니까 이제는 실행도 안되잖아...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"이제는 어디서부터 문제인건지 짐작도 안된다.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"제출 시간도 얼마 안남았네. 건드리지말껄...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "코드 분석에 실패해서 코드가 망가졌다." << Color::RESET << endl;
				cout << Color::ORANGE << "코딩력이 " << loss << " 감소했다." << Color::RESET << endl;
				character->setATK(character->getATK() - loss);
				break;
			}
		}
		else if (select == 2) {
			cout << Color::CYAN << "\"일단 돌아가기는 하니까 제출해야겠다.\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::CYAN << "\"언젠가 미래의 내가 이유는 찾아보겠지 뭐..\"" << Color::RESET << endl;
			Sleep(500);
			cout << Color::BRIGHT_WHITE << "이유를 찾지 않고 코드를 제출했다." << Color::RESET << endl;
			break;
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}
}




void BlueScreenEvent::EventEffect(Character* character, GameManager* gm) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 2);
	int RandNum = dis(gen);  // 1번 선택지용 확률
	int RandNum2 = dis(gen); // 2번 선택지용 확률

	cout << Color::GOLD << "====================블루 스크린 이벤트 발생!!!====================" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"뭐야? 갑자기 화면이 멈췄잖아!!\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"마지막 저장을 내가 언제 했었지?\"" << Color::RESET << endl;
	Sleep(500);
	cout << Color::CYAN << "\"재부팅을 해야하나? 본체를 때려볼까?\"" << Color::RESET << endl;
	Sleep(500);

	while (true) {
		cout << Color::BRIGHT_WHITE << "1. 재부팅한다  2. 본체를 때린다" << Color::RESET << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) continue;
		Sleep(500);
		if (select == 1) {
			if (RandNum != 2) {
				int gain = character->getLevel() * 2;
				cout << Color::CYAN << "\"제발 남아있어라...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"휴 다행이다. 평소에 저장을 습관처럼 해둬서 살았다.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "평소 자주 저장하는 습관 덕분에 코드는 그대로 남아있다." << Color::RESET << endl;
				cout << Color::LIME << "코딩력이 " << gain << " 증가했다!" << Color::RESET << endl;
				character->setATK(character->getATK() + gain);
				break;
			}
			else {
				int loss = static_cast<int>(character->getMaxHP() * 0.1);
				cout << Color::CYAN << "\"내가 오늘 작성한 코드들이 다 어디간거지...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"말도 안돼... 처음부터 다시 해야 한다고? 이건 꿈이야...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "오늘치 작업이 날아갔다. 극심한 스트레스가 밀려온다." << Color::RESET << endl;
				cout << Color::ORANGE << "체력이 " << loss << " 감소했다." << Color::RESET << endl;
				if (character->getHP() - loss >= 1) {
					character->setHP(character->getHP() - loss);
				}
				else {
					character->setHP(1);
				}
				break;
			}
		}
		else if (select == 2) {
			if (RandNum2 != 2) {
				cout << Color::CYAN << "\"오 화면이 돌아왔다! 역시 기계는 때려야 하는건가.\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::CYAN << "\"일단 바로 저장부터 하자. 진짜 다행이다..\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "컴퓨터가 원상태로 돌아왔다." << Color::RESET << endl;
				break;
			}
			else {
				cout << Color::CYAN << "\"뭐야 컴퓨터가 왜 이러지. 갑자기 꺼졌잖아...\"" << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "컴퓨터의 전원버튼을 눌러도 컴퓨터가 응답하지 않는다." << Color::RESET << endl;
				Sleep(500);
				cout << Color::BRIGHT_WHITE << "컴퓨터가 고장났다. 새로 컴퓨터를 구매하는데 비용이 발생했다." << Color::RESET << endl;
				cout << Color::BRIGHT_YELLOW << "100 ZEP코인을 잃었다." << Color::RESET << endl;
				if (character->getGold() >= 100) {
					character->setGold(character->getGold() - 100);
				}
				else {
					character->setGold(0);
				}
				break;
			}
		}
		else {
			cout << Color::BRIGHT_WHITE << "잘못된 선택지를 선택했습니다. 1번과 2번 중 선택해주세요." << Color::RESET << endl;
		}
	}
	
}
