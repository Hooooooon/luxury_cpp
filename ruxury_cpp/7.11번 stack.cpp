#include "main.h"

class Stack {
	int * ptr;
	int top; // size;
public:
	Stack() { ptr = new int[3]; top = -1; }
	~Stack() {
		delete [] ptr;
	}
	Stack& operator << (int n);
	Stack& operator >> (int& n);
	bool operator !();
};

bool Stack::operator!() { // empty
	return (top == -1) ? true : false;
}

Stack& Stack::operator<<(int n) { // push
	ptr[++top] = n;
	return *this;
}

Stack& Stack::operator>>(int& n) { // pop
	if (!this->operator!()) {
		int temp;
		temp = ptr[top--];
		n = temp;
	}
	return *this;
}

int main() {
	Stack st;
	st << 3 << 5 << 10; // 3, 5, 10 Push 
	while (true) {
		if (!st) break;
		int x;
		st >> x;
		cout << x << ' ';
	}
	cout << endl;
	return 0;
}