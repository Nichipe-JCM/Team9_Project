#include "Itempool.h"
#include "Weapon.h"
#include "Potion.h"
#include "ThrowingWeapon.h"
#include "CashableItem.h"
#include "BuffPotion.h"
#include "HealingPotion.h"

#include "Itempool.h"
#include "Weapon.h"
#include "Potion.h"
#include "ThrowingWeapon.h"
#include "CashableItem.h"
#include "BuffPotion.h"
#include "HealingPotion.h"


std::vector<Item*>& ItemPool::getAllItems() {
	static std::vector<Item*> allItems = {
		// 1. 무기류 (Weapon)
		new Weapon("키보드워리어의 너덜너덜한 키보드였던 것", 10, 10, ItemCategory::Weapon, Rarity::Common),
		new Weapon("독거미 키보드 60% 배열", 30, 30, ItemCategory::Weapon, Rarity::Rare),
		new Weapon("전설적인 C++ 마스터의 키보드", 500, 50, ItemCategory::Weapon, Rarity::Legendary),

		// 2. 투척 무기류 (ThrowingWeapon)
		new ThrowingWeapon("투척용 플로피디스크", 20, 10, 3, ItemCategory::Throwing, Rarity::Common),
		new ThrowingWeapon("구겨진 음료캔", 20, 30, 2, ItemCategory::Throwing, Rarity::Common),
		new ThrowingWeapon("분노에 찬 마우스", 40, 40, 1, ItemCategory::Throwing, Rarity::Common),
		new ThrowingWeapon("찌르기", 50, 30, 3, ItemCategory::Throwing, Rarity::Rare),
		new ThrowingWeapon("오토바이", 3000, 9999, 1, ItemCategory::Throwing, Rarity::Legendary),

		// 3. 포션류 (HealingPotion / BuffPotion)
		new HealingPotion("쓰리샷 추가한 커피", 55, 45, ItemCategory::HPotion, Rarity::Common),
		new HealingPotion("에너지드링크", 40, 50, ItemCategory::HPotion, Rarity::Common),
		new HealingPotion("스누피 초코우유", 50, 55, ItemCategory::HPotion, Rarity::Rare),
		new HealingPotion("빨간 날", 1000, 100, ItemCategory::HPotion, Rarity::Legendary),

		new BuffPotion("코딩애플 숏츠", 20, 10, ItemCategory::BPotion, Rarity::Common),
		new BuffPotion("점심시간", 30, 10, ItemCategory::BPotion, Rarity::Common),
		new BuffPotion("튜터님의 깜짝 세션", 50, 20, ItemCategory::BPotion, Rarity::Rare),

		// 4. 환금 아이템류 (CashableItem)
		new CashableItem("지폐", 77, ItemCategory::Cash, Rarity::Common),
		new CashableItem("500원 동전", 50, ItemCategory::Cash, Rarity::Common),
		new CashableItem("길가다 주운 복권", 10000, ItemCategory::Cash, Rarity::Legendary)
	};
	return allItems;
}