#include "main.h"

int main(){

	// 14번 난이도 8
	GamblingGame game;
	game.start();


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