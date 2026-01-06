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
#include "Monster.h"
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
		case Rarity::Common:    w = 100.0; break;
		case Rarity::Rare:      w = 30.0;  break;
		case Rarity::Legendary: w = 10.0;  break;
		default:                w = 10.0;  break;
		}
		weights.push_back(w);
	}

	std::discrete_distribution<int> dist(weights.begin(), weights.end());
	vector<int> vec;
	for (int i = 0; i < 5; i++)
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
	system("cls");
	ItemSetting();
	while (true)
	{		
		m_ShopMessage.clear();
		m_ShopMessage.push_back("----------------------------------------------------------------");
		m_ShopMessage.push_back("                        [ TUTOR : 박은일 ]                      ");
		m_ShopMessage.push_back("================================================================");
		m_ShopMessage.push_back("                                                                ");
		m_ShopMessage.push_back("                             @@@@@@@@@                          ");
		m_ShopMessage.push_back("                            @@@@@@@@@@@                         ");
		m_ShopMessage.push_back("                            [| -   - |]     \"흐음...\"         ");
		m_ShopMessage.push_back("                            (|   -   |)                         ");
		m_ShopMessage.push_back("                             |   _   |                          ");
		m_ShopMessage.push_back("                           |  -------  |                        ");
		m_ShopMessage.push_back("                          |             |                       ");
		m_ShopMessage.push_back("================================================================");
		m_ShopMessage.push_back("상점에 오신것을 환영합니다. 나는 튜터 박은일.");
		m_ShopMessage.push_back("원하시는것을 선택해주세요.");
		m_ShopMessage.push_back("----------------------------------------------------------------");
		m_ShopMessage.push_back("1. 구매            2. 판매              3. 다음 스테이지로 이동 ");
		m_ShopMessage.push_back("----------------------------------------------------------------");
		for (auto& msg : m_ShopMessage) {
			cout << Color::BEIGE << msg << Color::RESET<< endl;
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
			system("cls");
			cout << Color::RED << "잘못된 번호를 선택했습니다." << Color::RESET << endl;
		}
	}
}

// 구매이벤트
bool Shop::BuyItemFuntion(int NewProduct, Character* player)
{
	system("cls");
	if (NewProduct < 0 || NewProduct >= m_Product.size()) return false;
	Item* itemPtr = m_Product[NewProduct];
	if (itemPtr == nullptr) {
		cout<<Color::RED << "배치된 아이템이 없습니다."<< Color::RESET<< endl;
		return false;
	}
	int price = itemPtr->getValue();
	string RarityStr = itemPtr->rarityToString(itemPtr->getRarity());
	string RarityColor = itemPtr->getRarityColor(itemPtr->getRarity());
	
	if (player->getGold() >= price)
	{
		if (player->getInventory()->GetCurrentInventorySize() >= player->getInventory()->GetMaxInventorySlot())
		{
			cout <<Color::RED << "인벤토리가 가득 찼습니다. 아이템을 구매할 수 없습니다."<<Color::RESET << endl;
			return false;
		}
		// 골드 차감
		player->setGold(player->getGold() - price);
		player->getInventory()->AddItem(itemPtr);
		string color = itemPtr->getRarityColor(itemPtr->getRarity());
		string rName = itemPtr->rarityToString(itemPtr->getRarity());

		cout << "[구매 성공] " << color <<"["<< itemPtr->getName() << "]" << "(" << rName << ")" << "\033[0m"
			<< "을(를) 구매했습니다." << endl;

		m_Product.erase(m_Product.begin() + NewProduct);
		return true;
	}
	else
	{
		cout << Color::RED << "골드가 부족합니다." << Color::RESET << endl;
		return false;
	}
}
void Shop::BuyItem(Character* player)
{
	system("cls");
	while (true) {
		
		if (m_Product.empty()) {
			system("cls");
			cout << "배치된 아이템이 없습니다." << endl;
			return;
		}
		m_ShopMessage.clear();
		m_ShopMessage.push_back("----------------------------------------------------------------");
		m_ShopMessage.push_back("구매할 아이템을 선택해주세요.");
		m_ShopMessage.push_back("필요하시면 고민하지말고 사세요.");		
		m_ShopMessage.push_back("-------------------------- 구매 목록 --------------------------");
		int i = 0;
		Item* itemPtr = m_Product[i];
		string rarityStr = itemPtr->rarityToString(itemPtr->getRarity());
		Utils::DrawLine();
		for (auto& msg : m_ShopMessage) { cout<<Color::BEIGE << msg <<Color::RESET<< endl; }
		for (int i = 0; i < m_Product.size(); i++) {
			DrawTineLine();
			string color = m_Product[i]->getRarityColor(m_Product[i]->getRarity());
			cout << color << i + 1 << ". " << "품목 : "
				 << m_Product[i]->getName() << "[" << m_Product[i]->rarityToString(m_Product[i]->getRarity()) << "]" << "\033[0m" << endl;
			if(m_Product[i]->getItemType() == ItemCategory::Weapon)
			{
				cout << color << " 가격: " << m_Product[i]->getValue() << "  타입: 무기 " <<"  코딩력: " << m_Product[i]->getAttack() << "\033[0m" << endl;
			}
			else if(m_Product[i]->getItemType() == ItemCategory::Throwing)
			{
				cout << color << " 가격: " << m_Product[i]->getValue() << "  타입: 투척 무기 " << "  코딩력: " << m_Product[i]->getAttack() << "\033[0m" << endl;
			}
			else if(m_Product[i]->getItemType() == ItemCategory::HPotion)
			{
				cout << color << " 가격: " << m_Product[i]->getValue() << "  타입: 회복 포션 " << "  회복력: " << m_Product[i]->getHeal() << "\033[0m" << endl;
			}
			else if(m_Product[i]->getItemType() == ItemCategory::BPotion)
			{
				cout << color << " 가격: " << m_Product[i]->getValue() << "  타입: 버프 포션 " << "  버프력: " << m_Product[i]->getBuff() << "\033[0m" << endl;
			}
			
		}
		Utils::DrawLine();
		
		cout << Color::BG_BROWN << Color::WHITE << "[현재 코인] "<< player->getGold() <<"   " << Color::RESET << Color::RESET << "              6.뒤로가기" << endl;
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
		else if (select == 4)
		{
			BuyItemFuntion(3, player);
		}
		else if (select == 5)
		{
			BuyItemFuntion(4, player);
		}
		else if (select == 6) {
			system("cls");
			return;
		}
		else			
			cout<<Color::RED << "잘못된 번호를 선택했습니다." <<Color::RESET<< endl;		
		break;
	}
}
// 판매 이벤트 -> RemoveItem()
void Shop::SellItemFuntion(int NewProduct, Character* player) {
	vector<Item*>& items = player->getInventory()->GetInventory(); // 인벤토리 호출 부분
	Item* itemToSell = items[NewProduct];
	int sellPrice =0;
	string color = itemToSell->getRarityColor(itemToSell->getRarity());
	string rName = itemToSell->rarityToString(itemToSell->getRarity());
	if (items[NewProduct]->getItemType() != ItemCategory::Cash) {
		sellPrice = static_cast<int>(itemToSell->getValue() * 0.6);
	}
	else {
		sellPrice = static_cast<int>(itemToSell->getValue());
	}
	player->setGold(player->getGold() + sellPrice);
	cout << color << "[" << itemToSell->getName() << "]" << "(" << rName << ")" 
		<< "를 " << sellPrice << "에 판매했습니다!" << "\033[0m" << endl;
	player->getInventory()->RemoveItemFromIndex(NewProduct + 1);
	if(itemToSell != nullptr) delete itemToSell;
	Utils::WaitForKeypress();
}
// 판매 가능한 아이템 확인
void Shop::SellItem(Character* player) {
	system("cls");
	int currentPage = 0;
	const int itemsPerPage = 4;
	while (true)
	{
		system("cls");		
		m_ShopMessage.clear();
		cout << Color::BEIGE << "----------------------------------------------------------------"<< Color::RESET << endl;
		cout << Color::BEIGE << "판매할 아이템을 선택해주세요. (현재 페이지: " << currentPage + 1 << ")" << Color::RESET << endl;
		cout << Color::BEIGE << "--------------------------- 판매 목록 --------------------------" << Color::RESET << endl;

		vector<Item*>& myItems = player->getInventory()->GetInventory();
		if (myItems.empty()) {
			system("cls");
			cout << Color::RED << "판매할 아이템이 없습니다." << Color::RESET << endl;
			return;
		}
		
		int totalItems = static_cast<int>(myItems.size());
		int startIndex = currentPage * itemsPerPage;
		int endIndex;

		if (startIndex + itemsPerPage > totalItems)
		{
			endIndex = totalItems;
		}
		else
		{
			endIndex = startIndex + itemsPerPage;
		}
		for (int i = startIndex; i < endIndex; ++i) {
			cout << "----------------------------------------------------------------"<< endl;
			DrawTineLine();
			string color = myItems[i]->getRarityColor(myItems[i]->getRarity());
			if (myItems[i]->getItemType() != ItemCategory::Cash) {
				cout << color << (i - startIndex) + 1 << ". " << "[" << myItems[i]->getName() << "]" << "(" << myItems[i]->rarityToString(myItems[i]->getRarity()) << ")" 
					<< " (판매가: " << (int)(myItems[i]->getValue() * 0.6) << "G)" << "\033[0m" << endl;
			}
			else {
				cout << color << (i - startIndex) + 1 << ". " << "[" << myItems[i]->getName() << "]" << "(" << myItems[i]->rarityToString(myItems[i]->getRarity()) << ")"
					<< " (판매가: " << (int)(myItems[i]->getValue()) << "G)" << "\033[0m" << endl;
			}
			if (myItems[i]->getItemType() == ItemCategory::Weapon)
			{
				cout << color << " 가격: " << myItems[i]->getValue() << "  타입: 무기 " << "  코딩력: " << myItems[i]->getAttack() << "\033[0m" << endl;
			}
			else if (myItems[i]->getItemType() == ItemCategory::Throwing)
			{
				cout << color << " 가격: " << myItems[i]->getValue() << "  타입: 투척 무기 " << "  코딩력: " << myItems[i]->getAttack() << "\033[0m" << endl;
			}
			else if (myItems[i]->getItemType() == ItemCategory::HPotion)
			{
				cout << color << " 가격: " << myItems[i]->getValue() << "  타입: 회복 포션 " << "  회복력: " << myItems[i]->getHeal() << "\033[0m" << endl;
			}
			else if (myItems[i]->getItemType() == ItemCategory::BPotion)
			{
				cout << color << " 가격: " << myItems[i]->getValue() << "  타입: 버프 포션 " << "  버프력: " << myItems[i]->getBuff() << "\033[0m" << endl;
			}
			else if (myItems[i]->getItemType() == ItemCategory::Cash)
			{
				cout << color << " 가격: " << myItems[i]->getValue() << "  타입: 환금 아이템 " << "\033[0m" << endl;
			}
		}
		DrawTineLine();
		bool hasNextPage = (startIndex + itemsPerPage < totalItems);

		if (currentPage > 0) {
			cout <<Color::YELLOW << "5. 이전 페이지로       " << Color::RESET;
		}		
		if (hasNextPage) {
			cout <<Color::CYAN << "6. 다음 페이지로" <<Color::RESET << endl;
		}
		else {
			cout << Color::CYAN << "6. 뒤로가기 (상점 종료)" << Color::RESET << endl;
		}
		cout << "----------------------------------------------------------------" << endl;
			
		int select = Utils::DefaultMenu();
		
		if (select >= 1 && select <= (endIndex - startIndex)) {
			int actualIndex = startIndex + (select - 1);
			SellItemFuntion(actualIndex, player);			
			if (myItems.size() <= startIndex && currentPage > 0) currentPage--;
		}
		else if (select == 5) {
			if (currentPage > 0) {
				currentPage--;
			}
			else {
				system("cls");
				break;
			}
		}
		else if (select == 6) {
			if (hasNextPage) {
				currentPage++;
			}
			else {
				system("cls");
				break;
			}
		}
		else {
			system("cls");
			cout <<Color::RED <<"잘못된 입력입니다." << Color::RESET << endl;
		}
	}
}
void Shop::DrawTineLine() {
	cout << Color::GRAY << "----------------------------------------------------------------"<<Color::RESET<<endl;
}
void Shop::NextStage(GameManager* gm) {
	Utils::WaitForKeypress();
	system("cls");
	m_ShopMessage.clear();
	for (auto item : m_Product) delete item;
	m_Product.clear();
}// 다음 스테이지로 넘어감 ->