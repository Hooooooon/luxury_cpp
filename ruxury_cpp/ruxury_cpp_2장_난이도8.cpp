#include <iostream>
#include <cstring>
using namespace std;

#define buf_size 10000
#define alphabet_size 26

/*
   Wise men say, only fools rush in
   But I can't help, falling in love with you

   Shall I stay? Would it be a sin?
   If I can't help, falling in love with you

   Like a river flows, surely to the sea
   Darling so it goes, some things aren't menat to be ;
   ASCII 코드
    a = 97
    z = 122
    교수님이 말한 가로막대로 히스토그램 출력하기.
    콘솔 버프 사이즈 100으로 해야함 않하면 pq번째 출력 림.
*/

/*&
 조건문 수식(최대갯수-1차원반복문의 컨트롤 변수) - 알파벳갯수 = 출력해야할 공백갯수
 else -> 공백 나머지는 별임
세로(1차원 반복문) ->  최대갯수
가로(2차원 반복문) -> a ~ z 갯수(알파벳갯수)
*/


int main()
{
    char buf[buf_size]; // 사용자가 입력하는 문자열을 담은 배열
    int alphabetSet[alphabet_size] = { 0 }; // a~z 각각의 알파벳의 갯수가 닮긴 배열
    int sumOfalphabet = 0;  // 총 알파벳 갯수
    int alphabetCntMax = 0; // 최대 갯수

    cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다.\n텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;
    cin.getline(buf, buf_size, ';'); // 입력
    
    for (int i = 0; buf[i] != '\0'; i++) {
        if (isalpha(buf[i])) { // 알파벳인지 판별
            /*
              알파벳갯수집합 접근인덱스 = 사용자입력한문자열[i]를 
              소문자로 변환한 값을 int형으로 강제캐스팅하고 그 값을 'a'의 아스키코드에 감산함.
            */
            alphabetSet[(int)tolower(buf[i]) - (int)'a']++; 
            sumOfalphabet++; // 알파벳 갯수 증가
        }
    }
    // 최대갯수 구하기
    for (int i = 0; i < alphabet_size; i++) {
        if (alphabetSet[i] > alphabetCntMax) { 
            alphabetCntMax = alphabetSet[i];
        }
    }
    cout << "총 알파벳 수 " << sumOfalphabet << endl;

    for (int i = 0; i < alphabetCntMax; i++) {
        for (int j = 0; j < alphabet_size; j++) {
            if ((alphabetCntMax-i) - alphabetSet[j] > 0) {
                cout << " \t"; // 공백 출력
            }
            else {
                cout << "*\t"; // 별 출력
            }
        }
        cout << endl;
    }
    // 알파벳 출력
    for (int i = 0; i < alphabet_size; i++) {
        cout << (char)('a' + i) << '\t';
    }
    cout << endl;
    // 알파벳 갯수 출력
    for (int i = 0; i < alphabet_size; i++) {
        cout << '('<<alphabetSet[i]<<')' << '\t';
    }


    return 0;
}
