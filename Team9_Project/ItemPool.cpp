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
		new Weapon("키보드워리어의 너덜너덜한 키보드였던 것", 100, 15, ItemCategory::Weapon, Rarity::Common),
		new Weapon("독거미 키보드 60% 배열", 300, 30, ItemCategory::Weapon, Rarity::Rare),
		new Weapon("전설적인 C++ 마스터의 키보드", 1000, 100, ItemCategory::Weapon, Rarity::Legendary),

		// 2. 투척 무기류 (ThrowingWeapon)
		new ThrowingWeapon("투척용 플로피디스크", 100, 10, 3, ItemCategory::Throwing, Rarity::Common),
		new ThrowingWeapon("구겨진 음료캔", 150, 20, 2, ItemCategory::Throwing, Rarity::Common),
		new ThrowingWeapon("분노에 찬 마우스", 200, 30, 1, ItemCategory::Throwing, Rarity::Common),
		new ThrowingWeapon("찌르기", 400, 50, 3, ItemCategory::Throwing, Rarity::Rare),
		new ThrowingWeapon("오토바이", 3000, 9999, 1, ItemCategory::Throwing, Rarity::Legendary),

		// 3. 포션류 (HealingPotion / BuffPotion)
		new HealingPotion("에너지드링크", 40, 150, ItemCategory::HPotion, Rarity::Common),
		new HealingPotion("스누피 초코우유", 50, 300, ItemCategory::HPotion, Rarity::Rare),
		new HealingPotion("빨간 날", 1000, 9999, ItemCategory::HPotion, Rarity::Legendary),

		new BuffPotion("코딩애플 숏츠", 400, 10, ItemCategory::BPotion, Rarity::Common),
		new BuffPotion("점심시간", 800, 30, ItemCategory::BPotion, Rarity::Rare),
		new BuffPotion("Copilot Pro 이용권", 1500, 100, ItemCategory::BPotion, Rarity::Legendary),

		// 4. 환금 아이템류 (CashableItem)
		new CashableItem("500원 동전", 500, ItemCategory::Cash, Rarity::Common),
		new CashableItem("지폐", 1000, ItemCategory::Cash, Rarity::Common),
		new CashableItem("동전 몇 개", 300, ItemCategory::Cash, Rarity::Common),	
		new CashableItem("동전 한 줌", 1000, ItemCategory::Cash, Rarity::Common),
		new CashableItem("지폐 한 묶음", 5000, ItemCategory::Cash, Rarity::Rare),
		new CashableItem("동전 지갑", 3000, ItemCategory::Cash, Rarity::Rare),
		new CashableItem("지폐 몇 장", 2000, ItemCategory::Cash, Rarity::Rare),
		new CashableItem("길가다 주운 Zep 상품권", 5000, ItemCategory::Cash, Rarity::Rare),
		new CashableItem("길가다 주운 복권", 1000000, ItemCategory::Cash, Rarity::Legendary),
	};
	return allItems;
}