#include "main.h"

/*
정수형 자료를 저장할 수 있는 배열 strg[20]
저장된 자료의 수를 나타내는 nData를 가지는 클래스 Storage

자료의 수를 입력한 후
자료의 수만큼 정수형 자료를 입력하여 배열에 저장 하는 생성자

저장된 자료를 "자료의수:자료목록"형식으로 출력하는 멤버함수
*/

// 1. 저장된 자료중에서 일의 자리수가 n의 배수인 "수의 개수"
// 를 "반환"하는 멤버함수 int multipleN(int n)을 정의

// 2. Storage 객체의 합을 구하는 멤버함수(파라미터는 한개)
// void add_Strg(Storage s1)을 정의해보자.
// 객체의 합은 각 객체의 저장된 자료들을 저장한다.

class Storage {
private:
	int nData;		// 저장된 자료의 수
	int strg[20];	// 정수형 자료를 저장한 배열
public :
	Storage(int nSize);
	void showList();
	int multipleN(int n);
	void add_Strg(Storage s1);	// 복사 생성자
};

int Storage::multipleN(int n) {
	int count = 0;
	for (int i = 0; i < nData; i++) {
		if (strg[i] % 10 == n) {
			++count;
		}
	}
	return count;
}

void Storage::add_Strg(Storage s1) {
	int newSize = nData + s1.nData;
	if (newSize > 20) {
		cout << "덧셈을 수행할 수 없음" << '\n';
		return;
	}
	for (int i = nData; i < newSize; i++) {
		this->strg[i] = s1.strg[i - nData];
	}
	nData = newSize;
}

Storage::Storage(int nSize) {
	nData = nSize;
	cout << "자료 " << nData << "개 입력 : ";
	for (int i = 0; i < nData; i++) {
		cin >> strg[i];
	}
}

void Storage::showList() {
	cout << nData << ":";
	for (int i = 0; i < nData; i++) {
		cout << strg[i] << ' ';
	}
	cout << '\n';
}

// 10 3 3 4
// 1 12 33 24 5 16 7 28 3 27

int main(){
	Storage s1(4);
	s1.showList();

	Storage s2(10);
	s2.showList();
	
	cout << "3의 배수는 " << s1.multipleN(3) << "개입니다.\n";

	s1.add_Strg(s2);
	s1.showList();
	
	return 0;
}