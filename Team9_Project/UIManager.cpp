#include "UIManager.h"
#include "Character.h"
#include "Monster.h"
#include "Windows.h"

using namespace std;

UIManager::UIManager() {}
UIManager::~UIManager() {}

void gotoxy(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD GetCursorPosition() {
    CONSOLE_SCREEN_BUFFER_INFO presentCur;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
    return presentCur.dwCursorPosition;
}

//아스키 아트 맵
//MonsterArt = { "포인터" ,}



string UIManager::RenderMonsterArt(const std::string& monsterName) {
    auto it = MonsterArt.find(monsterName);
    if (it != MonsterArt.end()) {
		return it->second;  
    } else {
        return "No art available";
    }
}

void UIManager::RenderBattleScreen(const Character* player, const Monster* monster) {
    COORD oldPos = GetCursorPosition();
	if (oldPos.Y > 40) system("cls");
    gotoxy(0, 0);
    cout << "================================================================" << endl;
    cout << " [ ENEMY ]  " << monster->getName() << "  |  레벨: " << monster->getLevel() <<"  | HP: "<< monster->getHP() << " / " << monster->getMaxHP() <<" | 코딩력 : " << monster->getAttack()<<"                            " << endl;
    cout << "----------------------------------------------------------------" << endl;

	string art = RenderMonsterArt(monster->getName());
    cout << art << endl;
    int artHeight = 0;
    if (!art.empty()) {
        artHeight = static_cast<int>(std::count(art.begin(), art.end(), '\n') + 1);
    }

    cout << "----------------------------------------------------------------" << endl;
    cout << " [ PLAYER ]  " << player->getName() << "  |  레벨: " << player->getLevel() << "  | HP: " << player->getHP() << " / " << player->getMaxHP() << "  |  코딩력 : " << player->getATK() << "                         " << endl;
    cout << "================================================================" << endl;
	int linesUsed = 6 + artHeight;
	int targetY = (oldPos.Y < linesUsed) ? linesUsed : oldPos.Y;
	gotoxy(0, targetY);
}   

void UIManager::OpeningScene() { // 임시 
    system("cls");
    cout << "================= 게임 오프닝 씬 =================" << endl;
    cout << "당신은 코딩 세계의 용사입니다." << endl;
    cout << "악명 높은 버그 몬스터들이 세상을 위협하고 있습니다." << endl;
    cout << "당신의 임무는 이 몬스터들을 물리치고 평화를 되찾는 것입니다." << endl;
    cout << "=================================================" << endl;
    Utils::WaitForKeypress("계속하려면 아무 키나 누르세요...");
}

void UIManager::EndingScene() { // 임시
    system("cls");
    cout << "================= 게임 엔딩 씬 =================" << endl;
    cout << "축하합니다! 모든 몬스터를 물리치고 세상에 평화를 되찾았습니다." << endl;
    cout << "당신의 용기와 코딩 실력에 경의를 표합니다." << endl;
    cout << "=================================================" << endl;
    Utils::WaitForKeypress("계속하려면 아무 키나 누르세요...");
}

void UIManager::FinalBossAppearance() { // 임시
    system("cls");
    cout << "================= 최종 보스 등장 씬 =================" << endl;
    cout << "거대한 버그 몬스터가 나타났습니다!" << endl;
    cout << "이것이 바로 당신이 물리쳐야 할 최종 보스입니다." << endl;
    cout << "모든 힘을 다해 싸우세요!" << endl;
    cout << "===================================================" << endl;
    Utils::WaitForKeypress("계속하려면 아무 키나 누르세요...");
}

void UIManager::Mainscreen() {
    system("cls");
	cout << "내배캠에서 살아남기!" <<endl;
    cout << "=== Text Colors Test ===" << endl;
    // 기본
    cout << Color::BLACK << "BLACK " << Color::RED << "RED " << Color::GREEN << "GREEN "
        << Color::YELLOW << "YELLOW " << Color::BLUE << "BLUE " << Color::MAGENTA << "MAGENTA "
        << Color::CYAN << "CYAN " << Color::WHITE << "WHITE " << Color::GRAY << "GRAY" << Color::RESET << endl << endl;

    // 붉은 계열
    cout << Color::ORANGE << "ORANGE " << Color::GOLD << "GOLD " << Color::CRIMSON << "CRIMSON "
        << Color::SALMON << "SALMON" << Color::RESET << endl;

    // 푸른 계열
    cout << Color::SKY_BLUE << "SKY_BLUE " << Color::NAVY << "NAVY " << Color::TEAL << "TEAL "
        << Color::INDIGO << "INDIGO" << Color::RESET << endl;

    // 초록 계열
    cout << Color::LIME << "LIME " << Color::OLIVE << "OLIVE " << Color::MINT << "MINT" << Color::RESET << endl;

    // 보라/분홍 계열
    cout << Color::PURPLE << "PURPLE " << Color::LAVENDER << "LAVENDER " << Color::PINK << "PINK "
        << Color::HOT_PINK << "HOT_PINK" << Color::RESET << endl;

    // 무채색/기타
    cout << Color::SILVER << "SILVER " << Color::BROWN << "BROWN " << Color::BEIGE << "BEIGE" << Color::RESET << endl;

    // 고채도 텍스트
    cout << Color::BRIGHT_WHITE << "B_WHITE " << Color::BRIGHT_RED << "B_RED " << Color::BRIGHT_GREEN << "B_GREEN "
        << Color::BRIGHT_YELLOW << "B_YELLOW " << Color::BRIGHT_BLUE << "B_BLUE " << Color::BRIGHT_CYAN << "B_CYAN" << Color::RESET << endl << endl;


    cout << "=== Background Colors Test ===" << endl;
    // 기본 배경
    cout << Color::BG_RED << " RED " << Color::RESET << " "
        << Color::BG_GREEN << " GRN " << Color::RESET << " "
        << Color::BG_YELLOW << " YEL " << Color::RESET << " "
        << Color::BG_BLUE << " BLU " << Color::RESET << " "
        << Color::BG_MAGENTA << " MAG " << Color::RESET << " "
        << Color::BG_CYAN << " CYN " << Color::RESET << " "
        << Color::BG_WHITE << " WHT " << Color::RESET << " "
        << Color::BG_GRAY << " GRY " << Color::RESET << endl << endl;

    // 확장 배경 1
    cout << Color::BG_ORANGE << " ORANGE " << Color::RESET << " "
        << Color::BG_GOLD << " GOLD " << Color::RESET << " "
        << Color::BG_CRIMSON << " CRIMSON " << Color::RESET << " "
        << Color::BG_SALMON << " SALMON " << Color::RESET << endl;

    // 확장 배경 2
    cout << Color::BG_SKY_BLUE << " SKY " << Color::RESET << " "
        << Color::BG_NAVY << " NAVY " << Color::RESET << " "
        << Color::BG_TEAL << " TEAL " << Color::RESET << " "
        << Color::BG_INDIGO << " INDIGO " << Color::RESET << endl;

    // 확장 배경 3
    cout << Color::BG_LIME << " LIME " << Color::RESET << " "
        << Color::BG_OLIVE << " OLIVE " << Color::RESET << " "
        << Color::BG_MINT << " MINT " << Color::RESET << endl;

    // 확장 배경 4
    cout << Color::BG_PURPLE << " PURP " << Color::RESET << " "
        << Color::BG_LAVENDER << " LAVE " << Color::RESET << " "
        << Color::BG_PINK << " PINK " << Color::RESET << " "
        << Color::BG_HOT_PINK << " HOTP " << Color::RESET << endl;

    // 확장 배경 5
    cout << Color::BG_SILVER << " SILV " << Color::RESET << " "
        << Color::BG_BROWN << " BRWN " << Color::RESET << " "
        << Color::BG_BEIGE << " BEIGE " << Color::RESET << endl << endl;

    // 고채도 배경
    cout << Color::BG_BRIGHT_RED << " B_RED " << Color::RESET << " "
        << Color::BG_BRIGHT_GREEN << " B_GRN " << Color::RESET << " "
        << Color::BG_BRIGHT_YELLOW << " B_YEL " << Color::RESET << " "
        << Color::BG_BRIGHT_BLUE << " B_BLU " << Color::RESET << " "
        << Color::BG_BRIGHT_CYAN << " B_CYN " << Color::RESET << " "
        << Color::BG_BRIGHT_WHITE << " B_WHT " << Color::RESET << endl;
    Utils::WaitForKeypress();
}