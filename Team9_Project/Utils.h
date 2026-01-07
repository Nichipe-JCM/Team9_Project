#pragma once
#include <string>
#include <conio.h>
#include <sstream>
#include <vector>

namespace Color {
    // [기본 8색]
    const std::string RESET = "\033[0m";
    const std::string BLACK = "\033[30m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";
    const std::string WHITE = "\033[37m";
    const std::string GRAY = "\033[90m"; // 밝은 검정
    // 붉은 계열
    const std::string ORANGE = "\033[38;5;208m";
    const std::string GOLD = "\033[38;5;220m";
    const std::string CRIMSON = "\033[38;5;196m";
    const std::string SALMON = "\033[38;5;210m";
    // 푸른 계열
    const std::string SKY_BLUE = "\033[38;5;123m";
    const std::string NAVY = "\033[38;5;18m"; 
    const std::string TEAL = "\033[38;5;51m";
    const std::string INDIGO = "\033[38;5;54m";
    // 초록 계열
    const std::string LIME = "\033[38;5;118m";
    const std::string OLIVE = "\033[38;5;100m";
    const std::string MINT = "\033[38;5;49m";
    // 보라/분홍 계열
    const std::string PURPLE = "\033[38;5;129m"; 
    const std::string LAVENDER = "\033[38;5;183m";
    const std::string PINK = "\033[38;5;200m";
    const std::string HOT_PINK = "\033[38;5;205m";
    // 무채색 & 기타
    const std::string SILVER = "\033[38;5;250m";
    const std::string BROWN = "\033[38;5;94m";
    const std::string BEIGE = "\033[38;5;230m";

    const std::string BG_BLACK = "\033[40m";
    const std::string BG_RED = "\033[41m";
    const std::string BG_GREEN = "\033[42m";
    const std::string BG_YELLOW = "\033[43m";
    const std::string BG_BLUE = "\033[44m";
    const std::string BG_MAGENTA = "\033[45m";
    const std::string BG_CYAN = "\033[46m";
    const std::string BG_WHITE = "\033[47m";
	const std::string BG_GRAY = "\033[100m";
	const std::string BG_ORANGE = "\033[48;5;208m";
	const std::string BG_GOLD = "\033[48;5;220m"; 
	const std::string BG_CRIMSON = "\033[48;5;196m";
	const std::string BG_SALMON = "\033[48;5;210m"; 
	const std::string BG_SKY_BLUE = "\033[48;5;123m";
	const std::string BG_NAVY = "\033[48;5;18m"; 
	const std::string BG_TEAL = "\033[48;5;51m";
	const std::string BG_INDIGO = "\033[48;5;54m";
	const std::string BG_LIME = "\033[48;5;118m";
	const std::string BG_OLIVE = "\033[48;5;100m";
	const std::string BG_MINT = "\033[48;5;49m";
	const std::string BG_PURPLE = "\033[48;5;129m"; 
	const std::string BG_LAVENDER = "\033[48;5;183m";
	const std::string BG_PINK = "\033[48;5;200m";
	const std::string BG_HOT_PINK = "\033[48;5;205m";
	const std::string BG_SILVER = "\033[48;5;250m";
	const std::string BG_BROWN = "\033[48;5;94m";
	const std::string BG_BEIGE = "\033[48;5;230m";

    const std::string BRIGHT_WHITE = "\033[97m";
    const std::string BRIGHT_RED = "\033[91m";
    const std::string BRIGHT_GREEN = "\033[92m";
    const std::string BRIGHT_YELLOW = "\033[93m";
    const std::string BRIGHT_BLUE = "\033[94m";
    const std::string BRIGHT_CYAN = "\033[96m";

	const std::string BG_BRIGHT_WHITE = "\033[107m";
    const std::string BG_BRIGHT_RED = "\033[101m";
	const std::string BG_BRIGHT_GREEN = "\033[102m";
	const std::string BG_BRIGHT_YELLOW = "\033[103m";    
	const std::string BG_BRIGHT_BLUE = "\033[104m";
	const std::string BG_BRIGHT_CYAN = "\033[106m";
}

class Utils
{
public:
	static int GetSafeInput();
	static int DefaultMenu();
	static void DrawLine();
    static void WaitForKeypress(const std::string& msg = "\n\033[38;5;51m▶ 계속하려면 아무 키나 누르세요...\033[0m");
    static std::vector<std::string> SplitString(const std::string& str, char delimiter);
};

