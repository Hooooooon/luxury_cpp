#pragma once
#include "main.h"
#include <random>
#include <stdio.h>

#define player1 0
#define player2 1

class Player{
	string name;
public:
	void setName(string n){
		name = n;
	}

	string getName(){
		return name;
	}
};

class GamblingGame{
	Player p[2];		// 플레이어 변수
	int turn;			// 현재 누구 차례인지 담는 변수
	int end;			// 게임 종료를 받는 변수
public:
	GamblingGame(){

	}
	~GamblingGame(){

	}
	// 게임 구동
	void start(){
		Init();

		while (end != 0){
			Update();
		}
	}

	void Init(){
		cout << "***** 겜블링 게임을 시작합니다. *****\n";
		string temp;	
		cout << "첫번쨰 선수 이름>>";
		cin >> temp;
		p[player1].setName(temp);
		cout << "두번째 선수 이름>>";
		cin >> temp;
		p[player2].setName(temp);

		turn = player1; // 시작은 P1 부터
	}
	// Enter를 치게되면 랜덤한 숫자 3개가 발생.
	// 동일한 숫자가 나오면 게임 승리

	void Update(){
		char input;
		cout << p[turn].getName() << ":<Enter>\n";
		cin.get();	// Enter를 입력받는다.
		// -> 0 ~ 2
		int num1 = rand() % 3;		
		int num2 = rand() % 3;
		int num3 = rand() % 3;

		cout << "\t\t" << num1 << "\t\t" << num2 << "\t\t" << num3 << "\t\t";
		if (num1 == num2 && num2 == num3){
			cout << p[turn].getName() << "님의 승리!!\n";
			end = 0;
		}
		else {
			cout << "아쉽군요.\n";
		}
		cout << '\n';
		turn = !turn;	// 턴 전환
	}
};