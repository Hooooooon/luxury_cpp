
#include <iostream>
using namespace std;

template <class T>
T * remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	int newSize = 0;
	T* temp = new T[sizeSrc + sizeMinus];

	for (int i = 0; i < sizeSrc; i++) { 
		bool IsDelete = false;
		for (int j = 0; j < sizeMinus; j++) {
			if (src[i] == minus[j]) { // 뺴야하는 원소가 있다면.
				IsDelete = true;
			}
		}
		if (!IsDelete) {
			temp[newSize++] = src[i];
		}
	}
	retSize = newSize;
	return temp;
}

int * remove(int src[], int sizeSrc, int minus[], int sizeMinus, int& retSize) {
	int newSize = 0;
	int* temp = new int[sizeSrc + sizeMinus];

	for (int i = 0; i < sizeSrc; i++) {
		bool IsDelete = false;
		for (int j = 0; j < sizeMinus; j++) {
			if (src[i] == minus[j]) { // 뺴야하는 원소가 있다면.
				IsDelete = true;
			}
		}
		if (!IsDelete) {
			temp[newSize++] = src[i];
		}
	}
	retSize = newSize;
	return temp;
}

int main() {
	cout << "정수 배열 [1,2,3,4]에서 정수 배열 [-3, 5, 10, 1, 2, 3]을 뺍니다" << endl;

	double x[] = { 1.2, 2.2, 3.2, 4.2 };
	double y[] = { -3, 5, 10, 1.2, 2.2, 3.2 };
	int retSize;

	double * p = remove(x, 4, y, 6, retSize);
	if (retSize == 0) {
		cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
	}
	else {
		for (int i = 0; i < retSize; i++) {
			cout << p[i] << ' ';
		}
		cout << endl;
		delete[] p;	// 할당받은 배열 반환
	}

	return 0;
}