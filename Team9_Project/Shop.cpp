#include "Shop.h"
#include <cstdlib>
#include <ctime>

using namespace std;


void Shop::ItemSetting() 
{	
			
	Product.clear();

	for (int i = 0; i < 2; i++) {
		int RandomValue = rand() % 4;

		if (RandomValue == 0)
		{
			Product.push_back(new ThrowableItems());
		}
		else if (RandomValue == 1)
		{
			Product.push_back(new Equipment());
		}
		else if (RandomValue == 2)
		{
			Product.push_back(new BuffItem());
		}
		else if (RandomValue == 3)
		{
			Product.push_back(new Potion());
		}
	}


} // 아이템 랜덤 호출


void Shop::BuyItem() 
{
	int Buy_Switch;
	ItemSetting();

	for (int i = 0; i < 2; i++) {
		cout << i+1 << "." << "품목 : " << Product[i]->GetName() << "가격 : " << Product[i]->GetGold() << endl;
	}
	cout << "구매할 아이템을 선택해주세요." << endl;

	switch (Buy_Switch)
	{
	case 1:
		FirstProduct();
		break;
	case 2:
		SecondProduct();
		break;
	case 3:
		//뒤로가기
		break;
	default:
		cout << "잘못된 번호를 선택했습니다." << endl;
		break;
	}

}


void Shop::FirstProduct() 
{
	cout << "1." << "품목 : " << Product[0]->GetName() << "가격 : " << Product[0]->GetGold() <<"구매했습니다." << endl;
}


void SecondProduct();
void SellItemFuntion();// 판매 이벤트
void SellItem();// 판매 가능한 아이템 확인
void NextStage(); // 다음 스테이지로 넘어감 -> 
