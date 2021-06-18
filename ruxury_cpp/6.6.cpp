#include "main.h"


class ArrayUtility2 {
public:
	ArrayUtility2() {
	}
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

// s1과 s2를 연결한 새로운 배열을 동적 생성하고 리턴
int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int* tempArr = new int[size];
	for (int i = 0; i < size - 5; i++) {
		tempArr[i] = s1[i];
	}
	for (int i = 5; i < size; i++) {
		tempArr[i] = s2[i - 5];
	}

	return tempArr;
}

// s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴
// 리턴하는 배열의 크기는 retSize에 전달, 0인 경우 NULL 리턴
int* ArrayUtility2::remove(int s1[], int s2[], int size, int & retSize) {
	retSize = 0;
	// s1에서 s2에 있는 숫자를 삭제
	int * newArr = new int[size];
	int addIndex;
	for (int i = 0; i < size; i++) {
		addIndex = -1;
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j]){ // s1에 s2에 있는 숫자가 있다면
				addIndex = i;
				break;
			}
		}
		if (addIndex == -1) { 
			newArr[retSize++] = s1[i];
		}
	}
	if (retSize == 0)
		return NULL;
	return newArr;
}



int main(){
	int x[5], y[5];
	cout << "정수를 5개 입력하라. 배열 x에 삽입한다>>"; 
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}

	cout << "정수를 5개 입력하라. 배열 y에 삽입한다>>"; 
	for (int i = 0; i < 5; i++) {
		cin >> y[i];
	}
	
	int * newArr = ArrayUtility2::concat(x, y, 10);
	cout << "합친 정수 배열을 출력한다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << newArr[i] << ' ';
	}
	cout << endl;
	int newSize;
	int * newArr2 = ArrayUtility2::remove(x, y, 5, newSize);
	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다 개수는 "<< newSize << endl;
	for (int i = 0; i < newSize; i++) {
		cout << newArr2[i] << ' ';
	}
	cout << endl;

	return 0;
}