#pragma once
#include "main.h"

class Container{
	int size;
public:
	Container() : size(10) {}
	void fill(){		// 최대량으로 충기
		size = 10;
	}
	void consume(){		// 1만큼 소모
		size -= 1;
	}
	int getSize(){
		return size;
	}

};

class CoffeVendingMachine{
	Container tong[3];		// 에스프레소, 아메리카노, 설탕 커피

	void fill(){			// 3개의 통을 모두 10으로 채움
		for (int i = 0; i < 3; i++){
			tong[i].fill();
		}
		show();
	}

	int CanMakeCoffe(){	// 커피를 만들수 있는지 확인하는 함수 1은 No, 0은 가능
		if (tong[0].getSize() < 1 ){
			cout << "원료가 부족합니다\n";
			return 1;
		}
		else if (tong[1].getSize() < 1){
			cout << "원료가 부족합니다\n";
			return 1;

		}
		else if (tong[2].getSize() < 1){
			cout << "원료가 부족합니다\n";
			return 1;

		}
		return 0;
	}

	void selectEspresso(){	// 에스프레소를 선택한 경우,커피 1, 물 1 소모
		tong[0].consume();	// 커피
		tong[1].consume();	// 물
		if (CanMakeCoffe()){
			return;
		}
		cout << "에스프레소 드세요\n";
	}
	
	void selectAmerican(){	// 아메리카노를 선택한 경우, 커피 1, 물 2 소모
		tong[0].consume();	// 커피
		tong[1].consume();	// 물	
		tong[1].consume();
		if (CanMakeCoffe()){
			return;
		}

		cout << "아메리카노 드세요\n";
	}

	void selectSugarCoffee(){	// 설탕 커피 , 커피1, 물2, 설탕 1소모
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		tong[2].consume();		// 설탕
		if (CanMakeCoffe()){
			return;
		}

		cout << "설탕커피 드세요\n";
	}

	void show(){	// 현재 잔량 출력
		cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << '\n';
	}
	

public:
	void run()				// 자판기 작동
	{
		int n;
		cout << "***** 커피자판기를 작동합니다. *****\n";
		while (true){
			cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>>";
			cin >> n;

			switch (n)
			{
			case 1:
				selectEspresso();
				break;
			case 2:
				selectAmerican();
				break;
			case 3:
				selectSugarCoffee();
				break;
			case 4:
				show();
				break;
			case 5:
				fill();
				break;
			default:
				return;
			}

		}
	}
};


