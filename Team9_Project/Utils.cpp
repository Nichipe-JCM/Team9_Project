#include "Utils.h"
#include <iostream>

using namespace std;

int Utils::GetSafeInput() {
    int input;

    while (true) {
        cout << "> 입력: ";
        cin >> input;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n');
            cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
        }
        else {
            cin.ignore(10000, '\n'); 
            return input; 
        }
    }
}

int Utils::DefaultMenu() {
    cout << "---------------------------------" << endl;
    cout << "7.인벤토리  8.상태창  9.전적  0.업적" << endl;
    cout << "---------------------------------" << endl;
    return GetSafeInput();
}

void Utils::DrawLine() {
    cout << "=================================" << endl;
}