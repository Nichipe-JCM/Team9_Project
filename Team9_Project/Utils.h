#pragma once
#include <string>
#include <conio.h>

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
}

class Utils
{
public:
	static int GetSafeInput();
	static int DefaultMenu();
	static void DrawLine();
    static void WaitForKeypress(const std::string& msg = "\n▶ 계속하려면 아무 키나 누르세요...");
};

