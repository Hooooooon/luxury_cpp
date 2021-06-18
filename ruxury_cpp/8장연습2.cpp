#include <iostream>
#include <string>
using namespace std;

template <class T>
class Hello {
	T hi;
public:
	Hello(T hi) {
		this->hi = hi;
	}
	void set(T hi) {
		this->hi = hi;
	}
	void show() {
		cout << hi << endl;
	}
	template<class U>
	void swap(T a, U b) {
		cout << b << ' ' << a << endl;
	}
};

int main() {
	Hello<string> hi("hello");
	Hello<int> hii(123);

	hi.show();
	hi.swap("hi", "hello");
	hii.show();
	hii.swap(1, 2);
	return 0;
}