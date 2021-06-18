#include "main.h"

class SortedArray {
	int size;
	int* p; // 배열
	void sort() {
		// 선택 정렬
		int minIndex;
		for (int i = 0; i < size - 1; i++) { // 0, 1, 2
			minIndex = i;
			// 가장 최소값을 찾음
			for (int j = i + 1; j < size; j++) {
				if (p[j] < p[i]) {
					minIndex = j;
				}
			}
			// 자리 교체
			int temp = p[minIndex]; // 최소값 저장
			p[minIndex] = p[i];
			p[i] = temp;	
		}
		// 정렬 완료
	}
public :
	SortedArray() {
		size = 0;
		p = NULL;
	}
	SortedArray(SortedArray& src) { // 복사 생성자
		this->size = src.size;
		this->p = new int[size];
		for (int i = 0; i < this->size; i++) {
			this->p[i] = src.p[i];
		}
		sort(); 
	}
	SortedArray(int p[], int size) {
		this->size = size;
		this->p = new int[size];
		for (int i = 0; i < size; i++) {
			this->p[i] = p[i];
		}
		sort();
	}
	~SortedArray() {
		delete[] p;
	}

	SortedArray operator + (SortedArray& op2) { // 
		// 임시 객체
		SortedArray temp; 
		int newSize = this->size + op2.size; // 새로운 사이즈
		temp.size = newSize;
		temp.p = new int[newSize];
		// this 뒤에부터 새로운 op2 를 추가함
		for (int i = 0; i < this->size; i++) {
			temp.p[i] = this->p[i];
		}
		for (int i = this->size; i < newSize; i++) {
			temp.p[i] = op2.p[i - (this->size)];
		}
		temp.sort();
		return temp;
	}

	SortedArray& operator = (const SortedArray& op2) { // 치환 연산자
		delete  this->p;
		this->size = op2.size;
		this->p = new int[this->size];
		for (int i = 0; i < size; i++) {
			this->p[i] = op2.p[i];
		}
		return *this;
	}

	void show() {
		cout << "배열 출력 :";
		for (int i = 0; i < this->size; i++) {
			cout << this->p[i] << ' ';
		}
		cout << endl;
	}
};

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;

	a.show();
	b.show();
	c.show();
	return 0;
}