#include "Utils.h"
#include <iostream>

using namespace std;

int Utils::GetSafeInput() {
    int input;

    while (true) {
        cout << Color::BRIGHT_YELLOW << "> 입력: ";
        cin >> input;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n');
            cout << Color::BRIGHT_YELLOW << "잘못된 입력입니다. 숫자를 입력해주세요." << Color::RESET << endl;
        }
        else {
            cin.ignore(10000, '\n'); 
            return input; 
        }
    }
	cout << Color::RESET;
}

int Utils::DefaultMenu() {
    cout << Color::BRIGHT_WHITE << "==============================================" << endl;
    cout << "7.인벤토리     8.상태창     9.전적     0.업적" << endl;
    cout << "==============================================\n" << Color::RESET << endl;
    return GetSafeInput();
}

void Utils::DrawLine() {
    cout << Color::BRIGHT_WHITE << "===================================================================" << Color::RESET << endl;
}

void Utils::WaitForKeypress(const std::string& msg) {
    while (_kbhit()) {
        int ignored = _getch();
        (void)ignored;
    }

    if (!msg.empty()) std::cout << msg << std::endl;
    int key = _getch();
    (void)key;
}
std::vector<std::string> Utils::SplitString(const std::string& str, char delimiter) {
    std::vector<std::string> lines;
    std::stringstream ss(str);
    std::string temp;

    while (std::getline(ss, temp, delimiter)) {
        lines.push_back(temp);
    }
    return lines;
}