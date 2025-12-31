#pragma once

#include<iostream>
#include"GameManager.h"
#include "Item.h"
using namespace std;

class Item;
class Shop
{
private:
	vector<Item*>Product; // 아이템 호출 
	

public:
	

	void ItemSetting(); // 아이템 랜덤 호출
	void BuyItem(); // 구매 이벤트
	void FirstProduct();
	void SecondProduct();
	void SellItemFuntion();// 판매 이벤트
	void SellItem();// 판매 가능한 아이템 확인
	void NextStage(); // 다음 스테이지로 넘어감 -> 

};

