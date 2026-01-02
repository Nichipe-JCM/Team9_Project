#include "Shop.h"
#include "Item.h"
#include "Inventory.h"
#include "Character.h"
#include "Utils.h"
#include "GameManager.h"
#include "Weapon.h"
#include "ThrowingWeapon.h"
#include "BuffPotion.h"
#include "HealingPotion.h"
#include "CashableItem.h"
#include "Itempool.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;

void Shop::ItemSetting()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());

	auto& allItems = ItemPool::getAllItems(); 

	std::vector<Item*> candidates; 
	std::vector<double> weights;

	for (Item* item : allItems) {
		
		if (item->getItemType() == ItemCategory::Cash) {
			continue;
		}
		
		candidates.push_back(item);

		double w = 0;
		switch (item->getRarity()) {
		case Rarity::Common:    w = 100.0; break; // 흔함 (가장 높은 점수)
		case Rarity::Rare:      w = 30.0;  break; // 희귀
		case Rarity::Legendary: w = 10.0;   break; // 전설 (가장 낮은 점수)
		default:                w = 10.0;  break;
		}
		weights.push_back(w);
	}
	
	std::discrete_distribution<int> dist(weights.begin(), weights.end());
	vector<int> vec;
	for (int i = 0; i < 3; i++)
	{
		int selectedIndex = dist(gen);
		if (!vec.empty()) {
			auto it = find(vec.begin(), vec.end(), selectedIndex);
			if (it != vec.end()) {
				i--;
				continue;
			}
		}
		Item* chosenItem = candidates[selectedIndex]->clone();
		m_Product.push_back(chosenItem);
		vec.push_back(selectedIndex);
	}
}

// 상점 메인 ->void VisitShop();을 통해 해당 함수 로드
void Shop::ShopSelect(Character* player)
{

	while (true)
	{
		m_ShopMessage.clear();
		m_ShopMessage.push_back("----------------------------------------------");
		m_ShopMessage.push_back("상점에 오신것을 환영합니다. 나는 튜터 박은일.");
		m_ShopMessage.push_back("원하시는것을 선택해주세요.");
		m_ShopMessage.push_back("1. 구매  2. 판매  3. 다음 스테이지로 이동 ");
		m_ShopMessage.push_back("----------------------------------------------");
		for (auto& msg : m_ShopMessage) {
			cout << msg << endl;
		}

		int select = Utils::DefaultMenu();
		// 기본 선택지(인벤토리 확인 등) 체크
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}
		if (select == 1) {
			BuyItem(player);
		}
		else if (select == 2) {
			SellItem(player);
		}
		else if (select == 3) {
			cout << "상점을 떠나 다음 스테이지로 향합니다." << endl;
			Utils::DrawLine();
			NextStage(gm);
			return;
		}
		else {
			cout << "잘못된 번호를 선택했습니다." << endl;
		}
	}
}
// 구매이벤트
bool Shop::BuyItemFuntion(int NewProduct, Character* player)
{
	if (NewProduct < 0 || NewProduct >= m_Product.size()) return false;
	Item* itemPtr = m_Product[NewProduct];
	int price = itemPtr->getValue();

	if (player->getGold() >= price)
	{
		// 골드 차감
		player->setGold(player->getGold() - price);
		player->getInventory()->AddItem(itemPtr);
		cout << "[구매 성공] " << itemPtr->getName() << "을(를) 구매했습니다." << endl;
		cout << "잔액: " << player->getGold() << endl;
		m_Product.erase(m_Product.begin() + NewProduct);
		return true;
	}
	else
	{
		cout << "골드가 부족합니다." << endl;
		return false;
	}
}
// 1,2,3 상품구매 함수
//void Shop::FirstProduct(Character* player)
//{
//	if (BuyItemFuntion(0, player)) {
//		
//	}
//}
//void Shop::SecondProduct(Character* player)
//{
//	if (BuyItemFuntion(1, player)) {
//		cout << "2." << "품목 : " << m_Product[1]->getName() << "가격 : " << m_Product[1]->getValue() << "구매했습니다." << endl;
//	}
//}
//void Shop::ThirdProduct(Character* player)
//{
//	if (BuyItemFuntion(2, player)) {
//		cout << "3." << "품목 : " << m_Product[2]->getName() << "가격 : " << m_Product[2]->getValue() << "구매했습니다." << endl;
//	}
//}
// 상품 구매창 함수 -> 상점 메인에서 이동
void Shop::BuyItem(Character* player)
{
	while (true) {
		m_ShopMessage.clear();
		m_ShopMessage.push_back("구매할 아이템을 선택해주세요.");
		m_ShopMessage.push_back("필요하시면 고민하지말고 사세요.");
		ItemSetting();
		Utils::DrawLine();
		for (auto& msg : m_ShopMessage) { cout << msg << endl; }
		for (int i = 0; i < 3; i++) {
			cout << i + 1 << "." << "품목 : " << m_Product[i]->getName() << "가격 : " << m_Product[i]->getValue() << endl;
		}
		cout << "4.뒤로가기" << endl;
		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}
		if (select == 1)
		{
			BuyItemFuntion(0, player);
		}
		else if (select == 2)
		{
			BuyItemFuntion(1, player);
		}
		else if (select == 3)
		{
			BuyItemFuntion(2, player);
		}
		else if (select == 4) {
			return;
		}
		else
			cout << "잘못된 번호를 선택했습니다." << endl;
		break;
	}
}

// 판매 이벤트 -> RemoveItem()
void Shop::SellItemFuntion(int NewProduct, Character* player) {

	vector<Item*>& items = player->getInventory()->GetInventory(); // 인벤토리 호출 부분
	Item* itemToSell = items[NewProduct];

	int sellPrice = (int)itemToSell->getValue() * 0.6;
	player->setGold(player->getGold() + sellPrice);
	cout << itemToSell->getName() << "를" << sellPrice
		<< " 에 판매했습니다!" << endl;
	player->getInventory()->RemoveItemFromIndex(NewProduct+1);
}
// 판매 가능한 아이템 확인
void Shop::SellItem(Character* player) {

	while (true)
	{
		m_ShopMessage.clear();
		m_ShopMessage.push_back("판매할 아이템을 선택해주세요.");
		m_ShopMessage.push_back("-------- 판매 목록 ---------");
		Utils::DrawLine();
		m_ShopMessage.push_back("21. 뒤로가기");


		for (auto& msg : m_ShopMessage) cout << msg << endl;
		vector<Item*>& myItems = player->getInventory()->GetInventory();
		if (myItems.empty()) {
			cout << "판매할 아이템이 없습니다." << endl;
			return;
		}
		for (int i = 0; i < myItems.size(); ++i) {
			cout << i + 1 << ". " << myItems[i]->getName()
				<< " (판매가: " << (int)(myItems[i]->getValue() * 0.6) << ")" << endl;
		}

		int select = Utils::DefaultMenu();
		if (gm->DefaultMenuCheck(select)) {
			continue;
		}
		if (select >= 1 && select <= myItems.size()) {
			SellItemFuntion(select - 1, player);
		}
		else {
			cout << "잘못된 입력입니다." << endl;
		}
		if (select == 21) {
			break;
		}

		m_ShopMessage.clear();
	}
}
void Shop::NextStage(GameManager* gm) {
	m_ShopMessage.clear();
	for (auto item : m_Product) delete item;
	m_Product.clear();
}// 다음 스테이지로 넘어감 ->