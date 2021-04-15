#include "main.h"

class Item {
	int iPrice;
	string sName;
public :
	Item();			// 키보드 입력 받아서 멤버 변수 초기화
	void setPrice(int cPrice);		// 매개변수로 가격변경
	string getsName();
	int getiPrice();
};

Item::Item() {
	cout << "이름>>"; cin >> sName;
	cout << "가격>>"; cin >> iPrice;
}

void Item::setPrice(int cPrice) {
	iPrice = cPrice;
}

string Item::getsName() {
	return sName;
}

int Item::getiPrice() {
	return iPrice;
}

class Storage {
	int nData;
	Item* itemList;
public :
	Storage(int nSize);		// nSize > 0
	~Storage();
	void showList();		// 등록된 모든 item 출력
	void changePrice(string a, int newPrice); // item 이름 검색하고 출력
};

Storage::Storage(int nSize) {
	nData = nSize;
	itemList = new Item[nData];
}

Storage::~Storage() {
	delete[] itemList;
}

void Storage::showList() {
	for (int i = 0; i < nData; i++) {
		cout << itemList[i].getsName() << " " << itemList[i].getiPrice() << '\n';
	}
}

void Storage::changePrice(string a, int newPrice) {
	bool isFind = false;
	for (int i = 0; i < nData; i++) {
		if (a == itemList[i].getsName()) {
			itemList[i].setPrice(newPrice);
			cout << itemList[i].getsName() << " " << itemList[i].getiPrice() << '\n';
			isFind = true;
		}
	}
	if (!isFind)
		cout << "없음" << '\n';
}

int main(){
	Storage Items(5);		// 5개의 이름과 가격
	Items.showList();
	
	string s;
	int newPrice;
	cout << "가격 바꿀 이름 가격 입력 >>";
	cin >> s >> newPrice;
	Items.changePrice(s, newPrice);
	cout << "가격변경" << '\n';
	Items.showList();

	return 0;
}