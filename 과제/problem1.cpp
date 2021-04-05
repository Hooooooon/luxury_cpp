#include "main.h"
#include "problem1.h"

void half(double & n){ // n의 반값
	n = n / 2;
}

void problems::p1(){
	double n = 20;
	half(n);
	cout << n;
}

bool bigger(int a, int b, int &big){
	if (a == b) return true;

	if (a > b)
		big = a;
	else
		big = b;
	return false;
}

void problems::p2(){
	int a, b;
	cin >> a >> b;
	int bigNum;
	if (bigger(a, b, bigNum))
		cout << a << "와 " << b << "는 같습니다" << '\n';
	else
		cout << a << "와 " << b << " 중 " << bigNum << "이 더 큽니다" << '\n';
}

class Circle{
	int radius;
public:
	Circle(int r) { radius = r; }

	Circle(Circle & c){		// 복사 생성자
		this->radius = c.radius;
	}

	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() {
		cout << "반지름이 " << radius << "인 원" << '\n';
	}
};

void increaseBy(Circle &a, Circle &b){
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}


void problems::p3(){

	Circle x(10), y(5);
	increaseBy(x, y);
	x.show();			// 15

}