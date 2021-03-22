#include "main.h"

int main(){
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
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << "," << b.getHeight() << endl;
	return 0;
}