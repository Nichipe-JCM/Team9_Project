#include "GameManager.h"
#include "StatusManager.h"
#include "AchievementManager.h"
#include "Utils.h"
#include <iostream>
#include <Windows.h>


int main() {
	SetConsoleOutputCP(65001);
	StatusManager* SM = new StatusManager();
	AchievementManager* AM = new AchievementManager();
	while (true) {
		GameManager GM(SM,AM);
		GM.Opening();
		GM.RunGame();
		int choice = 0;
		while (true) {
			cout << "게임을 다시 시작하시겠습니까?" << endl;
			cout << "1. 예" << endl;
			cout << "2. 아니오(프로그램 종료)" << endl;
			choice = Utils::GetSafeInput();
			if (choice == 1 || choice == 2) {
				break;
			}
			else cout << "잘못된 입력입니다." << endl;
		}
		if (choice == 1) {
			cout << "게임을 재시작합니다" << endl;
			continue;
		}
		else {
			cout << "게임을 종료합니다." << endl;
			return 0;
		}
	}
	delete SM;
	delete AM;
	return 0;
}