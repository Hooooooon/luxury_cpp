#pragma once
#include "main.h"

class Family{
private:
	Person * p;			// Person 배열 포인터
	string familyname;	// 패밀리 이름을 담는 문자열 변수
	int size;			// Person 배열의 크기, 구성원의 수
public:
	// size 개수 만큼 person 배열 동적 할당
	Family(string name, int size){
		p = new Person[size];
		this->size = size;
		if (!p){
			cout << " 메모리 할당 X ";
		}
		familyname = name;
	}

	void setName(int i, string name){
		p[i].setName(name);
	}

	void show(){
		cout << familyname << "가족은 다음과 같이 " << size << "명 입니다.\n";
		for (int i = 0; i < size; i++){
			cout << p[i].getName() << '\t';
		}
	}

	// 모든 가족 구성원 출력
	~Family(){
		delete[] p;		// 동적 할당한 p 메모리 해제 
	}
};