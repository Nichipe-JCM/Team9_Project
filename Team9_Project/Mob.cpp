#include "Mob.h"
#include "Character.h"
#include <string>
#include <cstdlib>
#include <ctime> 
using namespace std;

Monster* Mob::createRandomMonster(Character* Player) // 정해진 리스트에서 랜덤으로 몬스터가 등장하게 하기
{
	static bool seeded = false;
	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}

	string names[] =
	{ "포인터", "레퍼런스", "템플릿", "변수", "함수", "배열", "알고리즘", "객체", "부동소수점", "클래스" };

	int idx = rand() % 10;
	int level = Player->getLevel();
	int gold = rand() % 11 + 10;
	int exp = 25;
	return new Monster(names[idx], level, gold, exp);
}

/*
필요 총 경험치 900
잡는 잡몹 16마리
잡는 중간보스 4마리
*/