#include <iostream>
#include <string>
using namespace std;

// 결론적으로 클래스에 가상함수가 있고 클래스가 반드시 소멸자를 사용해야하는 상황(업캐스팅 객체가 동적으로 할당되었을때)
//이라면 소멸자도 가상함수로 선언해야합니다.
// 오버라이딩 (virtual 키워드)
class P {
	string * name;
public:
	P(string temp = "B") {
		cout << "P 생성자 호출" << endl;
		name = new string(temp);
	}
	virtual ~P() {
		cout << "P 소멸자 호출" << endl;
		delete name;
	}
	string getName() { return *name; }
	virtual void show() {
		cout << *this->name << endl;
	}
};

class B : public P {
	string * age;
public:
	B() : P("B"){
		cout << "B 생성자 호출" << endl;
		age = new string("20");
	}
	~B() {
		cout << "B 소멸자 호출" << endl;
		delete age;
	}
	void show() override {
		cout << this->getName() << ", " << *this->age<< endl;
	}
};

int main() {
	P * a = new B();
	a->show();
	delete a;
	return 0;
}