#pragma once
#include "main.h"
#include <string>

class Circle{
	int radius;			// 반지름
	string name;		// 원의 이름
public:
	void setCircle(string name, int radius){
		this->name = name;
		this->radius = radius;
	}
	double getArea(){
		double result = 3.14 * this->radius * this->radius;
		return result;
	}
	string getName(){
		return name;
	}
};


class CircleManager
{
	Circle * p;		// Circle 배열
	int size;		// 배열의 크기
public:
	CircleManager(int size)		// size 크기의 배열 동적생성, 입력받는다.
	{
		p = new Circle[size];
		this->size = size;
	}

	~CircleManager()
	{
		delete[] p;
	}
	// p의 i번째를 초기화한다.
	void setCircle(int i, string name, int r){
		p[i].setCircle(name, r);
	}

	void show(){	// 그냥 원이름이랑 면적 출력할려고 만든 함수
		for (int i = 0; i < this->size; i++){
			cout << p[i].getName() << " " << p[i].getArea() << endl;
		}
	}

	// 사용자로부터 원의 이름을 입력받아 그 원의 면적 출력
	void searchByName(string name){
		// p의 0부터 size 까지의 name과, 입력한 name이 일치하면 그 원의 면적을 출력한다.
		for (int i = 0; i < this->size; i++){
			if (p[i].getName().compare(name) == 0)
				cout << name << "의 면적은 " << p[i].getArea() << "\n";
		}
	}
	// 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름 출력
	void searchByArea(int area){
		// 입력받은 area보다 더 큰 원의 이름 출력
		cout << area << "보다 큰 원을 검색합니다.\n";
		for (int i = 0; i < size; i++){
			if (p[i].getArea() > area){
				cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ',';
			}
		}
	}
};

