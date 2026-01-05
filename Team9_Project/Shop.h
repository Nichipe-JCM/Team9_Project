#pragma once
#include <vector>
#include <iostream>



using namespace std;
class Character;
class Monster;
class Item;
class Inventory;
class GameManager;
class Utils;

class Shop 
{
private:
	vector<Item*> m_Product; // 아이템 호출 
	vector<Inventory*>m_MyItem;
    vector<string>m_ShopMessage;
	Inventory* m_Inventory = nullptr;
	GameManager* gm;
	//Rarity rarity;
public:
	Shop(GameManager* _gm) :m_Inventory(nullptr), gm(_gm) {}
	~Shop(){}
	void ItemSetting(); // 아이템 랜덤 호출		
	void ShopSelect(Character* player);// 상점 시작함수
	void BuyItem(Character* player); // 구매 이벤트
	bool BuyItemFuntion(int NewProduct, Character* player);//구매시 인벤토리에 아이템 추가
	void SellItem(Character* player);//  판매 이벤트
	void SellItemFuntion(int NewProduct, Character* player);//판매 가능한 아이템 확인
	static void DrawTineLine();
	
	void NextStage(GameManager* gm); // 다음 스테이지로 넘어감 -> 

};

