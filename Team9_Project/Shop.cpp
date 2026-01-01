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
#include <cstdlib>
#include <ctime>

using namespace std;

// 아이템 랜덤 호출
void Shop::ItemSetting()
{

	for (int i = 0; i < 3; i++)
	{
		int RandomValue = rand() % 4;

		if (RandomValue == 0) //임시로 넣어놨습니다. 전체 아이템 목록이 생기면 거기서 무작위로 받아올 수 있어야 합니다
		{
			m_Product.push_back(new ThrowingWeapon("임시투척", 10, 10, 10));
		}
		else if (RandomValue == 1)
		{
			m_Product.push_back(new Weapon("임시무기", 10, 10));
		}
		else if (RandomValue == 2)
		{
			m_Product.push_back(new BuffPotion("임시버프", 10, 10));
		}
		else if (RandomValue == 3)
		{
			m_Product.push_back(new HealingPotion("임시포션", 10, 10));
		}
	}

}
// 상점 메인 ->void VisitShop();을 통해 해당 함수 로드 
void Shop::ShopSelect(Character* player, GameManager* gm)
{
	m_ShopMessage.clear();
	m_ShopMessage.push_back("=============================================.");	
	m_ShopMessage.push_back("상점에 오신것을 환영합니다. 나는 튜터 박은일.");
	m_ShopMessage.push_back("원하시는것을 선택해주세요.");
	m_ShopMessage.push_back("1. 구매  2. 판매  0. 다음 스테이지로 이동 ");
	m_ShopMessage.push_back("=============================================.");
	
	
	while (true)
	{
		// 지시사항대로 Utils::DefaultMenu() 사용
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
		else if (select == 0) {
			cout << "상점을 떠나 다음 스테이지로 향합니다." << endl;
			cout << "======================================" << endl;
			NextStage(gm);
			break; 
		}
		else {
			cout << "잘못된 번호를 선택했습니다." << endl;
		}
	}

}
// 구매이벤트
void Shop::BuyItemFuntion(int NewProduct, Character* player)
{
	Item* itemPtr = m_Product[NewProduct];
	int price = itemPtr->getValue();
	

	if (player->getGold() >= price)
	{
		// 골드 차감
		player->setGold(player->getGold() - price);
		m_Inventory->AddItem(itemPtr);
		m_Product.erase(m_Product.begin() + NewProduct);
	}
	else
	{
		cout << "골드가 부족합니다." << endl;
	}
}

// 1,2,3 상품구매 함수
void Shop::FirstProduct(Character* player)
{
	BuyItemFuntion(0,player);
	cout << "1." << "품목 : " << m_Product[0]->getName() << "가격 : " << m_Product[0]->getValue() <<"구매했습니다." << endl;
}
void Shop::SecondProduct(Character* player)
{
	BuyItemFuntion(1,player);
	cout << "2." << "품목 : " << m_Product[1]->getName() << "가격 : " << m_Product[1]->getValue() <<"구매했습니다." << endl;
}
void Shop::ThirdProduct(Character* player)
{
	BuyItemFuntion(2,player);
	cout << "1." << "품목 : " << m_Product[2]->getName() << "가격 : " << m_Product[2]->getValue() <<"구매했습니다." << endl;
}


// 상품 구매창 함수 -> 상점 메인에서 이동 
void Shop::BuyItem(Character* player)
{	
	
	m_ShopMessage.clear();
	m_ShopMessage.push_back("구매할 아이템을 선택해주세요.");
	m_ShopMessage.push_back("필요하시면 고민하지말고 사세요.");
	
	
	ItemSetting();

	for (auto& text : m_ShopMessage) {
		cout << text << endl;
	}
	for (int i = 0; i < 3; i++) {
		cout << i+1 << "." << "품목 : " << m_Product[i]->getName() << "가격 : " << m_Product[i]->getValue() << endl;
	}
	
	while (true) {
		for (auto& text : m_ShopMessage) {
			cout << text << endl;
		}
		for (int i = 0; i < 3; i++) {
			cout << i + 1 << "." << "품목 : " << m_Product[i]->getName() << "가격 : " << m_Product[i]->getValue() << endl;
		}
		int select = Utils::DefaultMenu();

		if (gm->DefaultMenuCheck(select)) {
			continue;
		}
		if (select == 1) 
		{
			FirstProduct(player);
			break;
		}
		else if (select == 2) 
		{
			SecondProduct(player);
			break;
		}
		else if (select == 3)
		{
			ThirdProduct(player);
			break;
		}
		else if (select == 0) {
			ShopSelect(player, gm);
			return;
		}else		
			cout << "잘못된 번호를 선택했습니다." << endl;
			break;		
	}
}

	

// 판매 이벤트 -> RemoveItem()

void Shop::SellItemFuntion(int NewProduct, Character* player) {
	vector<Item*> items = player->getInventory()->GetInventory(); // 인벤토리 호출 부분
	Item* itemToSell = items[NewProduct];
	
	int sellPrice = itemToSell->getValue() * 0.6;

	player->setGold(player->getGold() + sellPrice);
	
	m_Inventory->RemoveItemFromIndex(NewProduct);

	cout << itemToSell->getName() << "를" << sellPrice
		<< " 에 판매했습니다!" << endl;
}


// 판매 가능한 아이템 확인
void Shop::SellItem(Character* player) {

	m_ShopMessage.clear();
	m_ShopMessage.push_back("판매할 아이템을 선택해주세요.");
	m_ShopMessage.push_back("필요하시면 고민하지말고 파세요.");
	m_ShopMessage.push_back("판매할 아이템이 없습니다.");
	m_ShopMessage.push_back("-------내 인벤토리 / 판매-------");
	m_ShopMessage.push_back("판매할 아이템 번호를 선택하세요: ");
	m_ShopMessage.push_back("0. 뒤로가기");	

	while (true)
	{
		for (auto& text : m_ShopMessage)
		{
			cout << text << endl;
		}

		if (m_MyItem.empty()) {
			cout << m_ShopMessage[3] << endl;
			return;
		}

		cout << m_ShopMessage[4] << endl;
		for (int i = 0; i < m_MyItem.size(); ++i) {
			cout << i + 1 << ". " << m_Product[i]->getName()
				<< " , 가격: " << m_Product[i]->getValue() << endl;
		}
		for (int j = 4; j < 6; j++)
		{
			cout << m_ShopMessage[j] << endl;
		}

		int select = Utils::DefaultMenu();

		if (gm->DefaultMenuCheck(select)) {
			continue;
		}

		if (select >= 1 && select <= m_MyItem.size()) {
			SellItemFuntion(select - 1, player);
		}
		else if (select == 0) {
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
		}
	}
}


void Shop:: NextStage(GameManager* gm) {
	m_ShopMessage.clear();
	for (auto item : m_Product) delete item;
	m_Product.clear();

}// 다음 스테이지로 넘어감 -> 
