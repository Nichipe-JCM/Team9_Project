#pragma once
#include <vector>
#include<iostream>



using namespace std;
class Character;
class Item;
class Inventory;
class GameManager;
class Shop 
{
private:
	vector<Item*> m_Product; // 아이템 호출 
	vector<Inventory*>m_MyItem;
    vector<string>m_ShopMessage;
	Inventory* m_Inventory = nullptr;
	GameManager* gm;
public:
	Shop(GameManager* _gm) :m_Inventory(nullptr), gm(_gm) {}
	~Shop(){}
	void ItemSetting(); // 아이템 랜덤 호출	
	void FirstProduct(Character* player);//1,2,3 아이템 배치 함수
	void SecondProduct(Character* player);
	void ThirdProduct(Character* player);
	void ShopSelect(Character* player, GameManager* gm);// 상점 시작함수
	void BuyItem(Character* player); // 구매 이벤트
	void BuyItemFuntion(int NewProduct, Character* player);//구매시 인벤토리에 아이템 추가
	void SellItem(Character* player);//  판매 이벤트
	void SellItemFuntion(int NewProduct, Character* player);//판매 가능한 아이템 확인
	
	
	void NextStage(GameManager* gm); // 다음 스테이지로 넘어감 -> 

};

