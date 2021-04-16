#include "main.h"

// item 클래스 추가
class item {
	int iPrice;
	string iName;
public:
	item();
	void setPrice(int cPrice);
	int  getPrice() {
		return iPrice;
	}
	string getName() {
		return iName;
	}
};

item::item() {
	cin >> iName;
	cin >> iPrice;
}

void item::setPrice(int cPrice){
	iPrice = cPrice;
}

class Storage {
private:
	int nData;		// 저장된 자료의 수
	item * itemStrg;
public :
	Storage(int nSize);
	~Storage();
	void showList();
	void changePrice(string s, int newPrice);
};


Storage::Storage(int nSize) {
	nData = nSize;
	itemStrg = new item[nData];	// 동적 할당
}

Storage::~Storage() {
	delete [] itemStrg;
}

void Storage::showList() {
	for (int i = 0; i < nData; i++) {
		cout << itemStrg[i].getName() << " " << itemStrg[i].getPrice() << " ";
	}
	cout << '\n';
}

void Storage::changePrice(string a, int newPrice) {
	bool isFind = false;
	for (int i = 0; i < nData; i++) {
		if (a == itemStrg[i].getName()) {
			itemStrg[i].setPrice(newPrice);
			cout << itemStrg[i].getName() << " " << itemStrg[i].getPrice() << '\n';
			isFind = true;
		}
	}
	if (!isFind)
		cout << "없음" << '\n';
}


// 컵 1500 집게 2000 연필 200 볼펜 500 줄자 2000
int main(){
	Storage Items(5);		// 5개의 이름과 가격
	Items.showList();

	string s;
	int newPrice;
	cout << "가격 바꿀 이름 가격 입력 >>";
	cin >> s >> newPrice;
	Items.changePrice(s, newPrice);
	cout << "가격변경확인" << '\n';
	Items.showList();
	return 0;
}