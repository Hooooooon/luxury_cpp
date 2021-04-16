#include "main.h"

/*
* 3- 1
Storage 객체에 저장되는 자료의 중복을 방지,
데이터의 수에 무관하게 덧셈이 가능하고 동시에 중복 방지하도록 수정.

3 - 2
Storage 객체의 합을 구하는 멤버함수(매개변수 1개)
void add_Strg(Storage s1)를 정의한다.
*/

class Storage {
private:
	int nData;		// 저장된 자료의 수
	int* strg;
public :
	Storage(int nSize);
	Storage(Storage& s);
	~Storage();
	void showList();
	void add_Strg(Storage s1);	// 복사 생성자
};

Storage::Storage(Storage& s) {
	this->nData = s.nData;
	this->strg = new int[nData];
	for (int i = 0; i < nData; i++)
	{
		this->strg[i] = s.strg[i];
	}
}


void Storage::add_Strg(Storage s1) {
	int newSize = nData + s1.nData;
	if (newSize > 20) {
		cout << "덧셈을 수행할 수 없음" << '\n';
		return;
	}
	int * temp = new int[nData + s1.nData];	// 새로운 공간 확보
	for (int i = 0; i < nData; i++) {
		temp[i] = strg[i];	// temp에 복사
	}
	newSize -= s1.nData;
	for (int i = 0; i < s1.nData; i++) {
		int newData = s1.strg[i];
		// s1의 자료와 중복된 자료 탐색
		bool isOverride = false;
		for (int j = 0; j < nData; j++) {
			if (temp[j] == newData) {
				isOverride = true;
				break;
			}
		}
		// 중복된 자료는 복사하지 않는다.
		if(!isOverride)
			temp[newSize++] = newData;
	}
	delete[] strg;	// 기존에 확보한 공간 해제
	// temp의 공간을 s1에 연결.
	strg = temp;
	nData = newSize;
}

Storage::Storage(int nSize) {
	nData = nSize;
	strg = new int[nData];	// 동적 할당
	cout << "자료 " << nData << "개 입력 : \n";
	for (int i = 0; i < nData; i++) {
		int temp;
		cin >> temp;
		bool isOverride = false;
		for (int j = 0; j < nData ; j++) {
			if (strg[j] == temp) {
				i--;
				isOverride = true;
				cout << "<중복>\n";
				break;		// 검색 종료
			}
		}
		if (!isOverride) {
			strg[i] = temp;
		}
	}
}

Storage::~Storage() {
	delete [] strg;
}

void Storage::showList() {
	cout << nData << ":";
	for (int i = 0; i < nData; i++) {
		cout << strg[i] << ' ';
	}
	cout << '\n';
}

// 10 3 3 4 4 5 -> 10 3 4 5	(4)
// 1 12 33 24 5 16 7 28 3 3 27 -> 1 12 33 24 5 16 7 28 3 27(10)
// 10 3 4 5 1 12 33 24 (중복:5) 16 7 28 (중복:3) 27  (12개)
int main(){
	Storage s1(4);
	s1.showList();

	Storage s2(10);
	s2.showList();
	

	s1.add_Strg(s2);
	s1.showList();
	return 0;
}

////////////////////////// 실습문제 2 난이도 6 ///////////////////////
//Date birth(2014, 3, 20);
//Date idd("1945/8/15");
//idd.show();
//birth.show();
////////////////////////// 실습문제 7 난이도 6 ///////////////////////
//Random r; 
//cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10개--" << endl;
//
//int i = 0;
//while (i <= 10){
//	int n = r.next();
//	if (n % 2 == 0){ // 짝수이면
//		cout << n << ' ';
//		i++;
//	}
//	
//}
//cout << endl << endl << "-- 2에서 " << "9 까지의 랜덤 홀수 정수 10 개 --" << endl;
//i = 0;
//while (i <= 10){
//	int n = r.nextInRange(2, 9);
//	if (n % 2 == 1){
//		cout << n << ' ';
//		i++;
//	}
//}
//
//cout << endl;

////////////////////////// 실습문제 9 난이도 6 ///////////////////////
/*/
Oval a, b(3, 4);
a.set(10, 20);
a.show();
cout << b.getWidth() << "," << b.getHeight() << endl;
return 0;
*/

/*
	10번 난이도 7
Family *simpson = new Family("Simpson", 3);
simpson->setName(0, "Mr. Simpson");
simpson->setName(1, "Mrs. Simpson");
simpson->setName(2, "Bart Simpson");
simpson->show();
delete simpson;


// 11번	난이도 6
CoffeVendingMachine coffeMachine;
coffeMachine.run();


	12번 난이도 8
	int size;
	cout << "원의 개수 >> ";
	cin >> size;

	CircleManager circleManager(size);		// size 만큼의 원 생성

	for (int i = 0; i < size; i++){
	string name;
	int r;
	cout << "원 " << i+1 << "의 이름과 반지름 >>";
	cin >> name >> r;
	circleManager.setCircle(i,name, r);
	}
	string searchName;
	cout << "검색하고자 하는 원의 이름 >>"; cin >> searchName;
	circleManager.searchByName(searchName);
	int minArea;
	cout << "최소 면적을 정수로 입력하세요 >> "; cin >> minArea;
	circleManager.searchByArea(minArea);

	// 13번 난이도 8
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();

*/