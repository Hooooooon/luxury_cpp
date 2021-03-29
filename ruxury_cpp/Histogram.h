#pragma once
#include "main.h"


// 대문자는 소문자로 변환

class Histogram{
	string sentence;
public :
	Histogram(string s){
		sentence = s + '\n';
	}

	void put(string str){
		sentence.append(str);
	}

	void putc(char ch){
		sentence += ch;
	}

	void makeGraph(){
		// 전체 탐색
		int chCnt[26] = { 0 };	// 'a' ~ 'z' 각각 대응하는 갯수를 담는 배열
		int cnt = 0; // 알파벳 개수를 담는 변수
		for (int i = 0; i < sentence.length(); i++){
			if (isalpha(sentence[i])){	// 입력받은 배열이 알파벳이면
				chCnt[tolower(sentence[i]) - 'a']++;	// 대응하는 알파벳 위치의 개수 1씩 증가
				cnt++;									// 총 알파벳 개수 증가
			}
		}
		cout << "총 알파벳 수 " << cnt << "\n\n";

		for (int i = 0; i < 26; i++){					// a ~ z 
			cout << (char)('a' + i) << " (" << chCnt[i] << ")\t";	// 알파벳에 해당하는 개수 출력
			for (int j = 0; j < chCnt[i]; j++){						// 개수에 따른 별 출력
				cout << '*'; 
			}
			cout << '\n';
		}
	}

	void print(){
		cout << sentence << "\n\n";
		// 히스토그램 출력
		makeGraph();
	}
};