#include "Mob.h"
#include <string>
#include <cstdlib>
#include <ctime> 
using namespace std;

Monster* Mob::createRandomMonster() // 정해진 리스트에서 랜덤으로 몬스터가 등장하게 하기
{
	static bool seeded = false;
	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}

	string names[] =
	{ "포인터", "레퍼런스", "템플릿", "변수", "함수", "배열", "알고리즘", "객체", "부동소수점", "클래스" };

	int idx = rand() % 10;
	int level = rand() % 5 + 1;
	int gold = rand() % 11 + 10;
	int exp = 50;
	return new Monster(names[idx], level, gold, exp);
}