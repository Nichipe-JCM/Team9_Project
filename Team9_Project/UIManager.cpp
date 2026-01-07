#include "UIManager.h"
#include "Character.h"
#include "Monster.h"
#include "Windows.h"

using namespace std;

UIManager::UIManager()
{
	//아스키 아트 맵
    MonsterArt["포인터"] = { R"(
       _    _    _  
      \ \  | |  / /  
       \ \ | | / /  
       _ _ \ / _ _  
    | _ _       _ _ |  
        / /   \ \   
       / / | | \ \  
      /_/  |_|  \_\   
                            )", 10 };

    

    MonsterArt["레퍼런스"] = { R"(
           _ _ _  
          / _ _ \  
         / /   \ \  
         \ \_ _/ /  
          \  _  /  _  
          / / \ \/ /  
         / /   \  /  
        / /_ _ /\ \  
        \_ _ _ _/\_\  
                            )", 11 };

    MonsterArt["템플릿"] = { R"(
                              _ _  
                _ _ _ _ _ _ / \   \   
               / \         /   \_ _\   
               \  \       /   /   /   
           _ _  \  \         /   /   
          \  _ \ \  \       /   / \   
           \ \    \  \             \   
            \ \ _  \  \_ _ _ _ _ _ _\   
             \ _ _\ \ /_ _ _ _ _ _ _/    
                            )", 11};
   

    MonsterArt["변수"] = { R"(

    		[const int MAX_HP]  
    		[SEALED]  
    ╔══════════════════════════════════════════╗  
    ║                   _       _     _        ║  
    ║                  (_)     | |   | |       ║  
    ║  __   ____ _ _ __ _  __ _| |__ | | ___   ║  
    ║  \ \ / / _` | '__| |/ _` | '_ \| |/ _ \  ║  
    ║   \ V / (_| | |  | | (_| | |_) | |  __/  ║  
    ║    \_/ \__,_|_|  |_|\__,_|_.__/|_|\___|  ║
    ║                                          ║  
    ╚══════════════════════════════════════════╝   
                            )", 14};


    MonsterArt["함수"] = { R"(
            \       /  
        _ _ _\     / _ _ _ _ _ _ _  
        |                         |  
        |                         |  
        |                 \  \    |  
        |                ('- ')   |  
        |                ⊂  ⊂ )°  | 
        | _ _ _ _ _ _ _ _ "  "  _ |  
                          /     \   
                         /       \   
                         - - - - -   
                            )", 13 };


    MonsterArt["배열"] = { R"delim(
       _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
      |         |         |        |         |         |         | 
      |   ('')  | (-'- )  | (^.^)  | ( _ _ ) | (-. -)  | (^v^ )  | 
      |   - -   |   - -   |  - -   |   -  -  |   -  -  |  - -    |
      | _ _ _ _ | _ _ _ _ | _ _ _ _| _ _ _ _ | _ _ _ _ | _ _ _ _ |  
                                )delim", 7};


    MonsterArt["알고리즘"] = { R"delim(
                 _ _ _  
                (_ _ _)  
               _ _ | _ _  
              | _ _ _ _ |  
                   |  
                  / \   
                 /   \   
                /     \   
         _ _ _ / (ㅇ)  \ _ _  
        /      \       /     \   
       //\      \     /     /\\  
                 \   /
                  \ /
                   | 
                            )delim", 16 };


    MonsterArt["객체"] = { R"(
                  _ _ _ _ 
                | -     - | 
                |_ _ _ _ _| 
                     | 
             _ _ _ _ | _ _ _ _ 
             |                |
             |                | 
         _ _ | _ _        _ _ | _ _ 
        |         |_    _|         | 
        |_|_|_|_ _|_|  |_|_ _|_|_|_|  
                            )", 12 };


    MonsterArt["부동소수점"] = { R"(
                      ·¨ ¨ ¨ ¨ ¨ ¨·  
                     ·    ____     · 
                    :    /    |     : 
                    :   /_|   |     : 
                    :     |   |     : 
                     ·    |___| ㅇ · 
                      ·           · 
                      ｏ ¨ ¨ ¨ ¨ 
                      。  
                     。 
                    .  
                            )", 13 };


	MonsterArt["클래스"] = {
		R"delim(
                    CLASS 
                /===========\  
           [PROTECTED]  
              hp 
              level 
                      
           [PRIVATE]    
              heart 
              itemDrop 
                       
           [PUBLIC] 
              Attack() 
              Jump()  
                            )delim", 15 };

    

    MonsterArt["김조은 튜터"] = {
        R"(
         -===+==                                      
        =:=++++=:.:=                                   
       .-*#######*=:-                                  
       .-++===+*###*=::                                
       ::-+****++***+-:--           =-------           
        :::+*****+=+++-.-        -..=+****+-..-        
          -:-+*##*+=+++=.-     +:=++#########*=:-      
            =::*##*==+=:::-  ::===--=*#########=.-     
             -:-*###--=====-.-+====---=+#######*=.:    
               .-++-==----=*=+*++***====+*##***+=.:    
             :-+=++:=*****+=+*##*++###*+==++++++=.:    
           .=*#####*--=++=-=======-.:::-+====+=-.=.    
          :-*##########*++*#%%%%%#*=:.:=*#**+-:-       
         -:*###########*=*#%%%%%%%##*+*#%%%%#*-:#      
        -:=*###########*=+**********===+******-..      
        ::+*############*==++++++++======++++-::-      
        .:=+*#########*++++===+===++++======++:        
       :.:==**######*=-=++=--=++-==++++=-====*-.       
       :.:====++*##*==-...-#%%%%%-::::.-#%*-=*-..      
       :.:==========-=+++:=%%%%%%--+++--#%*==-:..      
         .:=========-=++++-::::::=+****=-:::-..:       
          .:==========+++***********+******=..         
           ..:=========++*******=+*****+-+*=           
              .:--=======++******=-----=*=:            
              ......-=====-=++*******+-..    
                            )", 27};


	MonsterArt["손승현 튜터"] = {
		R"(                                                       
                ..::::....              ..             
              .:-===++++++-..        .:==-.            
             ..-+**=---========-:  :=**==-.            
             .-=--+%%%++===*#%%%*--=++=-. .            
             .-+%%%%%%=*==-+#%%--======. .-            
           .=+#%%%%%%%=-++++#%%----==--:::.            
            .#%%%%%%%%%#%%%%%%%*=----:=*- .            
          .-#%%%%%%%%%%%%%%%%%*+*****+=*%%-            
         .=##%%%%%%%%%%%%%%%%%%%#*****#%%%#+.          
         .=##%%%%%%%%%%%%%#*+++++++++##%%%%*.          
         :=####%%%%%%%%%#***#########++*###*.          
         -=####%%%%%%%#**+=..:-*###+-:-+*##*.          
         -=######%%%%#+*##############*+*##*.          
          .-##########+*##*=:.-*###+-.-+*#=..          
           :.#########+*#*+++**####**#*+*#-            
             --########*+****#*##+*+******-            
              :-**#######****##==++##+++-              
                 - .**######*++++++++*-:  
                            )", 20 };

	MonsterArt["김봉재 튜터"] = {
		R"(
                 @...........*                
             ..:--==+*****+==--:..            
         %..:-===================-:..*        
       *.:-==========================:.*      
      *.-========-------------========-..     
     ..:---==---------------------==---:..    
     ..::----:::-==----------=-:::----::..    
     .:::::---===================---:::::..#  
    ..:::---=====+++++++++++++=====---:::..%  
    ..::..:---:..:===========...:--::..::..#  
    -.:: ........ .-+*###**=. ........ ::..@  
      *. -:-*#*+++++**###**+++++*##-:-. .     
      @.=+==**=-----+#####+-----=*#+=+=..     
      @.++=+#*-+##*-=#####+-*##+=*#+=+*..     
       =:+**##*****###***###*****##**+::      
         -.:+******#**###**#******+: .+       
            =:+*#####+===+######+:=*          
               :-=*#########*=-:
                             )", 20 };

	MonsterArt["박은일 튜터"] = {
	R"(                                                     
                    ......::::......                   
                    .......:::......  .                
            ........................::......           
          :......:::::::::...........:::::...          
        ...:::.:::---::::::::::...:::::::-::....       
        ..:::::::------::-:::::::..::::-----::..       
      . .:::.::::::--=--------::.....::---=-:::..      
      ..::::.:::::::::::-:---:.........:::::::::.    
      ..::::.::::::::::::::-:............:::::::.    
      ..:::::..::::::.:::::::.=******-....:::::..      
     ....:::::..:::::..::::::.=********-..:::::..      
     .:...::::::..:::......:::.-******+-:::::...       
      :................:+++-...:******- :=:....        
        ......:-+*=.:+***=-=+***********=. ..          
         :... -*--+=:+***:.....-******-..  .           
           :. .-+++*****##################:.           
             :   ..:****###**##########***:.           
               --..-=+**#####************---           
                    ..:=+*###########**=:-             
                      :  :-+++*+=--::-::         
                             )", 22 };

	MonsterArt["김극민 튜터"] = {
R"(
                 ...........:                 
              :..-----------:..:              
          ..::------========----::.           
         ..-------============-----::         
        ..--------============------.:        
       ..----------------------------:.       
        :------------------------------..     
        :------------------------------.      
        ::---------::....:---------:... :     
      . :::::--------::::..::---::..::: .     
       .::::....----:....:---------::..       
         ...::-:.-:.:=:.-+..:---:..=-.        
         . .-:.:---=##-::::-------::::::      
            .:--::---========-----=====..     
                .:---======--------==-:       
                .:::---===---==-----:.        
                   ..::--:::-----:....   
                             )", 19 };

	MonsterArt["문승현 튜터"] = {
R"(                                              
                ..............                
                ......  .....                 
             . ................ .             
           .......::::..::::.......           
            ...................... .          
         . .....              ..... .         
          ..   ................   .. .        
            .....::::::::::::.....   .        
          .........::::::::......... .        
         .............................        
        ..............................        
        ..............................        
        .......                .......        
        ......=****************-......        
         -+***=:::=********=:::=***+:         
     :.-==+*******==******-=*******+==-..     
     ::+--=*****=:=********+-:+****=-=+.      
     .-=+=+*###+  =########- .+###*+=+=.      
       .:.-*####**##########**####*:..:       
           --*######******######+---          
             :-***##########**+--             
               : .:-=++++=-:. -   

 )", 22 };

	MonsterArt["강창민 튜터"] = {
R"(
             .::.               ....          
          ..::::.              .::. .         
           .:--:.              .:....         
              .:: .           ...... .        
       .--:::--:.. .:-------:. .:=-:.         
       ..##*+=---:-------------:...           
         .:===----=***+=----------=-.         
         .:--------==++=------:::-==-..       
        ..:-------.  =::--:::-==++-:-...      
       ..::-------.    :---::-==++-:  .       
       .:::--------::-+####+-:------.:::      
       .:::-------+##########+=--=**+:::      
       .::::----+#####*-=======+++==*+:: .    
       .:::::--+####*=*=---+####+----*+: .    
       .:::::::+*#*-*###++*#####*=+--*+..     
       - ::::::+**+-+###- =#####= :*=*=       
         :.:::::+**=+##############+=+.-      
           :.::::=+**=+*#######*#+-=--        
             :....:=++**=-------==-:          
               .    ..........  -   
                            )", 22 };
}



UIManager::~UIManager() {}


void UIManager::PrintLogs() {
    int totalLogs = static_cast<int>(m_battleLog.size());
    int startIdx = 0;
    if(totalLogs == 0) return;
    if (totalLogs > Max_DisplayLog) {
        startIdx = totalLogs - Max_DisplayLog;
    }
    for (int i = startIdx; i < totalLogs; i++) {
        cout << m_battleLog[i] << endl;
    }
}

void gotoxy(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ShowBossEntrance(string rawArt, int totalLines) {
    // 1. 거대한 문자열을 한 줄씩 분해합니다.
    vector<string> artLines = Utils::SplitString(rawArt, '\n');

    // 데이터의 줄 수가 입력받은 높이(22)보다 적을 경우를 대비한 안전장치
    if (artLines.size() < totalLines) {
        totalLines = artLines.size();
    }

    // 2. 연출 시작 (총 totalLines 단계만큼 반복)
    // frame 1: 맨 윗줄 1개만 바닥에 보임
    // frame 2: 맨 윗줄은 한 칸 위로, 두 번째 줄이 바닥에 보임 ...
    for (int frame = 1; frame <= totalLines; ++frame) {

        // (1) 화면을 매번 지우면 깜빡이니, 커서를 '그림이 시작될 위치'로 되돌립니다.
        // 예를 들어 화면 상단(0, 5)부터 그리기 시작한다고 가정합시다.
        // 선생님의 UI 배치에 따라 Y좌표(5)는 조절하세요.
        gotoxy(0, 0);

        // (2) [공간 계산] 위쪽 여백 채우기
        // 그림이 솟아오르려면, 아직 안 올라온 부분만큼은 '빈 줄(Newline)'로 밀어내야 합니다.
        // 예: 22줄짜리 그림인데 5줄만 보여주고 싶다면? -> 위에 17줄은 빈 줄로 채움
        for (int i = 0; i < totalLines - frame; ++i) {
            cout << "                                                    " << endl; // 공백 출력
        }

        for (int i = 0; i < frame; ++i) {
            cout << Color::CRIMSON << artLines[i] << Color::RESET << endl;
        }

        // (4) [시간 지연] 너무 빠르면 솟아오르는 느낌이 안 납니다.
        Sleep(150); // 0.1초 대기 (속도는 취향껏 조절)
    }

    // 3. 등장 후 웅장한 메시지 (선택 사항)
    Sleep(500);
    cout << "\n\n" << Color::BG_RED << Color::BRIGHT_WHITE
        << "       [ 경고 ]  강창민 튜터님이 등장했습니다!       "
        << Color::RESET << endl;
    Sleep(1000);
}



COORD GetCursorPosition() {
    CONSOLE_SCREEN_BUFFER_INFO presentCur;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
    return presentCur.dwCursorPosition;
}


int UIManager::GetArtHeight(const std::string& monsterName) {
    auto it = MonsterArt.find(monsterName);
    if (it != MonsterArt.end()) {
        return it->second.height;
    }
    return 1;
}

string UIManager::RenderMonsterArt(const std::string & monsterName) {
		auto it = MonsterArt.find(monsterName);
		if (it != MonsterArt.end()) {
			return it->second.art;
		}
		else {
			return "아트가 없어요. 왜 없을까? 버근가?";
		}
	}


void UIManager::RenderBattleScreen(const Character* player, const Monster* monster) {
    system("cls");
	gotoxy(0, 0);
	cout << Color::BRIGHT_WHITE<< "==========================================================================" << endl;
	cout << " [ ENEMY ]  " << monster->getName() << "  |  레벨: " << monster->getLevel() << "  | HP: " << monster->getHP() << " / " << monster->getMaxHP() << " | 코딩력 : " << monster->getAttack() << "                            " << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	string art = RenderMonsterArt(monster->getName());
	cout << art << endl;

	cout << "--------------------------------------------------------------------------" << endl;
	cout << " [ PLAYER ]  " << player->getName() << "  |  레벨: " << player->getLevel() << "  | HP: " << player->getHP() << " / " << player->getMaxHP() << "  |  코딩력 : " << player->getATK() << "                         " << endl;
	cout << "==========================================================================" << Color::RESET << endl;
    PrintLogs();
} 

void UIManager::OpeningScene() {
    system("cls");
    cout << Color::BRIGHT_WHITE << "오늘도 내배캠에서 열심히 공부를 하던 나. 그런데..." << endl;
    Sleep(2000);
	cout << Color::TEAL << "\n「강창민 튜터 」" << Color::BRIGHT_WHITE << " 오늘부터 과제 발제합니다!!!" << endl;
	Sleep(2000);
	cout << Color::BRIGHT_WHITE << "\n튜터님이 손짓하자 순식간에 Zep이 수많은 코드카타 문제들로 가득 찼다!" << endl;
	Sleep(2000);
	cout << Color::TEAL << "\n「강창민 튜터 」" << Color::BRIGHT_WHITE << " 이번 과제는!!! 코딩 지옥에서 살아남아라!!! 으하하하하!!!" << endl;
	Sleep(2000);
	cout << Color::BRIGHT_WHITE << "\n튜터님은 그대로 웃으며 모습을 감췄다..." << endl;
	Sleep(2000);
	cout << Color::LIME << "\n수많은 코드카타 문제들을 해결하며 실력을 기르고, 그 실력을 강창민 튜터님에게 증명해서 내배캠에서 살아남자!!" << Color::RESET << endl;
    Sleep(2000);
    Utils::WaitForKeypress();
}

void UIManager::EndingScene() {
    system("cls");
    cout << Color::BRIGHT_WHITE << "어떻게든 강창민 튜터님의 문제를 해결했다!!" << endl;
    Sleep(2000);
    cout << Color::TEAL << "\n「강창민 튜터 」" << Color::BRIGHT_WHITE << " 크크큭... 제법이군요... 하지만 이 과제는 앞으로 남은 과제들 중 최약체!!!" << endl;
    Sleep(2000);
    cout << Color::TEAL << "\n「강창민 튜터 」" << Color::BRIGHT_WHITE << " 앞으로의 과제도 기대해 주세요!! 으하하하하!!!" << endl;
    Sleep(2000);
    cout << Color::BRIGHT_WHITE << "\n튜터님은 또 그대로 웃으며 모습을 감췄다..." << endl;
    Sleep(2000);
    cout << Color::LIME << "\n하지만 그동안의 노력으로 실력이 많이 성장했다! 앞으로도 계속 정진하자!! 화이팅!!" << Color::RESET << endl;
    Sleep(2000);
    Utils::WaitForKeypress();
}

void UIManager::FinalBossAppearance() {
    system("cls");
    cout << Color::BRIGHT_WHITE << "Zep에 남아있던 코드카타 문제들을 전부 풀었다!!" << endl;
	Sleep(2000);
	cout << Color::BRIGHT_WHITE << "\n하지만 갑자기 바닥이 격하게 흔들리기 시작한다...!" << endl;
	Sleep(2000);
    string bossArt = MonsterArt["강창민 튜터"].art;
    int artHeight = 22;
    ShowBossEntrance(bossArt, artHeight);
    cout << Color::TEAL << "\n「강창민 튜터 」" << Color::BRIGHT_WHITE << " 크크크... 그 많던 문제들을 모두 해결하다니..." << endl;
    Sleep(2000);
    cout << Color::TEAL << "\n「강창민 튜터 」" << Color::BRIGHT_WHITE << " 이번엔 제가 직접 상대해드리죠!! 으랴아!!!" << endl;
    Sleep(2000);
    cout << Color::BRIGHT_WHITE << "\n창민 튜터님이 크고 아름다운 문제를 들고 이쪽으로 돌진한다!!!!" << endl;
    Sleep(2000);
    cout << Color::CRIMSON << "\n최종보스 창민 튜터님의 문제를 해결하고 이번 과제를 클리어하자!!!!" << Color::RESET << endl;
    Sleep(2000);
}

void DrawLogo() {
    const vector<string> logoData = {
        "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
        "@@@@########@@@@#######@@@@@@@@####@@@@@@@######@@@@@##########@@@@####@@@@@@@",
        "@@@####@@@###@@@###@@@@###@@@@##@@##@@@@@@###@@@###@@@@@@###@@@@@@##@@##@@@@@@",
        "@@@###@@@@@@@@@@###@@@@###@@@###@@###@@@@@###@@@###@@@@@@###@@@@@###@@###@@@@@",
        "@@@@@######@@@@@###@@@@###@@@##@@@@##@@@@@#########@@@@@@###@@@@@##@@@@##@@@@@",
        "@@@##@@@@@@##@@@#########@@@##########@@@@#######@@@@@@@@###@@@@##########@@@@",
        "@@@###@@@@###@@@###@@@@@@@@@###@@@@###@@@@###@@@###@@@@@@###@@@@###@@@@###@@@@",
        "@@@@########@@@@###@@@@@@@@###@@@@@@###@@@###@@@###@@@@@@###@@@###@@@@@@###@@@",
        "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
        "@@@@@@@@@@@@@@@@@@@@######################################@@@@@@@@@@@@@@@@@@@@",
        "@@@@@@@@@@@@@@@@@@#######@@@@@####@@###########@@##########@@@@@@@@@@@@@@@@@@@",
        "@@@@@@@@@@@@@@@@@######@@@@@@@@@##@@###########@@##########@@@@@@@@@@@@@@@@@@@",
        "@@@@@@@@@@@@@@@@@#####@@@#####@@##@@##@@###@@##@@@@@@@######@@@@@@@@@@@@@@@@@@",
        "@@@@@@@@@@@@@@@@@@####@@##########@@##@@###@@##@@###@@@#####@@@@@@@@@@@@@@@@@@",
        "@@@@@@@@@@@@@@@@@@####@@@#####@@##@@##@@###@@##@@####@@######@@@@@@@@@@@@@@@@@",
        "@@@@@@@@@@@@@@@@@@@####@@@@@@@@@##@@##@@@##@@##@@####@@######@@@@@@@@@@@@@@@@@",
        "@@@@@@@@@@@@@@@@@@@######@@@@@####@@###@@@@@@##@@@@@@#######@@@@@@@@@@@@@@@@@@",
        "@@@@@@@@@@@@@@@@@@@@######################################@@@@@@@@@@@@@@@@@@@@",
        "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
    };

    for (const string& line : logoData) {
        for (int v = 0; v < 2; ++v) {
            char lastChar = '\0';
            for (char c : line) {
                if (c != lastChar) {
                    if (c == '@') {
                        cout << Color::BG_BRIGHT_WHITE << Color::BRIGHT_WHITE;
                    }
                    else if (c == '#') {
                        cout << Color::BG_RED << Color::RED;
                    }
                }

                cout << c << c;

                lastChar = c;
            }
            cout << Color::RESET << endl;
        }
    }
}

void UIManager::Mainscreen() {
    system("cls");
    DrawLogo();
	cout << Color::BRIGHT_YELLOW << "\n내배캠에서 살아남기! - 코딩 지옥에서 살아남아라!!" << Color::RESET <<endl;
    //cout << "=== Text Colors Test ===" << endl;
    //// 기본
    //cout << Color::BLACK << "BLACK " << Color::RED << "RED " << Color::GREEN << "GREEN "
    //    << Color::YELLOW << "YELLOW " << Color::BLUE << "BLUE " << Color::MAGENTA << "MAGENTA "
    //    << Color::CYAN << "CYAN " << Color::WHITE << "WHITE " << Color::GRAY << "GRAY" << Color::RESET << endl << endl;

    //// 붉은 계열
    //cout << Color::ORANGE << "ORANGE " << Color::GOLD << "GOLD " << Color::CRIMSON << "CRIMSON "
    //    << Color::SALMON << "SALMON" << Color::RESET << endl;

    //// 푸른 계열
    //cout << Color::SKY_BLUE << "SKY_BLUE " << Color::NAVY << "NAVY " << Color::TEAL << "TEAL "
    //    << Color::INDIGO << "INDIGO" << Color::RESET << endl;

    //// 초록 계열
    //cout << Color::LIME << "LIME " << Color::OLIVE << "OLIVE " << Color::MINT << "MINT" << Color::RESET << endl;

    //// 보라/분홍 계열
    //cout << Color::PURPLE << "PURPLE " << Color::LAVENDER << "LAVENDER " << Color::PINK << "PINK "
    //    << Color::HOT_PINK << "HOT_PINK" << Color::RESET << endl;

    //// 무채색/기타
    //cout << Color::SILVER << "SILVER " << Color::BROWN << "BROWN " << Color::BEIGE << "BEIGE" << Color::RESET << endl;

    //// 고채도 텍스트
    //cout << Color::BRIGHT_WHITE << "B_WHITE " << Color::BRIGHT_RED << "B_RED " << Color::BRIGHT_GREEN << "B_GREEN "
    //    << Color::BRIGHT_YELLOW << "B_YELLOW " << Color::BRIGHT_BLUE << "B_BLUE " << Color::BRIGHT_CYAN << "B_CYAN" << Color::RESET << endl << endl;


    //cout << "=== Background Colors Test ===" << endl;
    //// 기본 배경
    //cout << Color::BG_RED << " RED " << Color::RESET << " "
    //    << Color::BG_GREEN << " GRN " << Color::RESET << " "
    //    << Color::BG_YELLOW << " YEL " << Color::RESET << " "
    //    << Color::BG_BLUE << " BLU " << Color::RESET << " "
    //    << Color::BG_MAGENTA << " MAG " << Color::RESET << " "
    //    << Color::BG_CYAN << " CYN " << Color::RESET << " "
    //    << Color::BG_WHITE << " WHT " << Color::RESET << " "
    //    << Color::BG_GRAY << " GRY " << Color::RESET << endl << endl;

    //// 확장 배경 1
    //cout << Color::BG_ORANGE << " ORANGE " << Color::RESET << " "
    //    << Color::BG_GOLD << " GOLD " << Color::RESET << " "
    //    << Color::BG_CRIMSON << " CRIMSON " << Color::RESET << " "
    //    << Color::BG_SALMON << " SALMON " << Color::RESET << endl;

    //// 확장 배경 2
    //cout << Color::BG_SKY_BLUE << " SKY " << Color::RESET << " "
    //    << Color::BG_NAVY << " NAVY " << Color::RESET << " "
    //    << Color::BG_TEAL << " TEAL " << Color::RESET << " "
    //    << Color::BG_INDIGO << " INDIGO " << Color::RESET << endl;

    //// 확장 배경 3
    //cout << Color::BG_LIME << " LIME " << Color::RESET << " "
    //    << Color::BG_OLIVE << " OLIVE " << Color::RESET << " "
    //    << Color::BG_MINT << " MINT " << Color::RESET << endl;

    //// 확장 배경 4
    //cout << Color::BG_PURPLE << " PURP " << Color::RESET << " "
    //    << Color::BG_LAVENDER << " LAVE " << Color::RESET << " "
    //    << Color::BG_PINK << " PINK " << Color::RESET << " "
    //    << Color::BG_HOT_PINK << " HOTP " << Color::RESET << endl;

    //// 확장 배경 5
    //cout << Color::BG_SILVER << " SILV " << Color::RESET << " "
    //    << Color::BG_BROWN << " BRWN " << Color::RESET << " "
    //    << Color::BG_BEIGE << " BEIGE " << Color::RESET << endl << endl;

    //// 고채도 배경
    //cout << Color::BG_BRIGHT_RED << " B_RED " << Color::RESET << " "
    //    << Color::BG_BRIGHT_GREEN << " B_GRN " << Color::RESET << " "
    //    << Color::BG_BRIGHT_YELLOW << " B_YEL " << Color::RESET << " "
    //    << Color::BG_BRIGHT_BLUE << " B_BLU " << Color::RESET << " "
    //    << Color::BG_BRIGHT_CYAN << " B_CYN " << Color::RESET << " "
    //    << Color::BG_BRIGHT_WHITE << " B_WHT " << Color::RESET << endl;
    Utils::WaitForKeypress();
}

