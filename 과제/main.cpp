#include <iostream>
#include <string>
using namespace std;

class Morse{
	string alphabet[26];	// 알파벳의 모스부호
	string digit[10];		// 숫자의 모스부호
	string slash, question, comma, period, plus, equal;	// 특수문자의 모스 부호 지정
public:
	Morse(){				// alphabet[], digit[] 배열 및 특수문자의 모스 부호 초기화
		alphabet[0] = ".-";
		alphabet[1] = "-...";
		alphabet[2] = "-.-.";
		alphabet[3] = "-..";
		alphabet[4] = ".";
		alphabet[5] = "..-.";
		alphabet[6] = "--.";
		alphabet[7] = "....";
		alphabet[8] = "..";
		alphabet[9] = ".---";
		alphabet[10] = "-.-";
		alphabet[11] = ".-..";
		alphabet[12] = "--";
		alphabet[13] = "-.";
		alphabet[14] = "---";
		alphabet[15] = ".--.";
		alphabet[16] = "--.-";
		alphabet[17] = ".-.";
		alphabet[18] = "...";
		alphabet[19] = "-";
		alphabet[20] = "..-";
		alphabet[21] = "...-";
		alphabet[22] = ".--";
		alphabet[23] = "-..-";
		alphabet[24] = "-.--";
		alphabet[25] = "--..";
		digit[0] = "-----";
		digit[1] = ".----";
		digit[2] = "..---";
		digit[3] = "...--";
		digit[4] = "....-";
		digit[5] = ".....";
		digit[6] = "-....";
		digit[7] = "--...";
		digit[8] = "----..";
		digit[9] = "----.";
		slash = "-..-.";
		question = "..--..";
		comma = ".-.-.-";
		period = ".-.-.-";
		plus = ".-.-.";
		equal = "-...-";
	}
	void test2Morse(string text, string & morse){		// 
		for (int i = 0; i < text.length(); i++){
			if (isalpha(text[i])){	// 알파벳 to 모스
				morse += alphabet[(int)text[i] - 'a'] + ' ';
			}
			else if (text[i] >= '0' && text[i] <= '9'){	// 숫자
				morse += digit[(int)text[i] - '0'] + ' ';
			}
			else if (text[i] == '/')	morse += slash + ' ';
			else if (text[i] == '?')	morse += question + ' ';
			else if (text[i] == '.')	morse += comma + ' ';
			else if (text[i] == ',')	morse += period + ' ';
			else if (text[i] == '+')	morse += plus + ' ';
			else if (text[i] == '-')	morse += equal + ' ';
			else{
				morse += ' ';
			}
		}
	}
	void morseTotext(string morse, string & text){
		for (int i = 0; i < morse.length(); i++){

		}
	}
};

int main(){
	Morse m;
	string str;
	cout << "아래에 영문 텍스트를 입력하세요. 모스 부호로 바꿉니다." << '\n';
	getline(cin, str);	
	string text = "";
	m.test2Morse(str, text);
	cout << text << '\n';
}

/*

lets meet 4 pm 2014.




class Buffer{
string text;
public :
Buffer(string text) { this->text = text; }
Buffer(Buffer & buf){	// 복사 생성자
this->text = buf.text;
}
void add(string next) { text += next; }
void print() { cout << text << endl; }
};

Buffer append(Buffer & buf, string str){
buf.add(str);
return buf;
}

int main(){
Buffer buf("Hello");
Buffer & temp = append(buf, "Guys");
temp.print();
buf.print();
return 0;
}



class MyIntStack{
int * p;		// 스택 메모리로 사용할 포인터
int size;		// 스택의 최대 크기
int tos;		// 스택의 탑을 가리키는 인덱스
public:
MyIntStack();
MyIntStack(int size){
p = new int();
this->size = size;
tos = -1;	// 0보다 밑
}
MyIntStack(const MyIntStack & s){
this->p = s.p;
this->size = s.size;
this->tos = s.tos;
}
~MyIntStack(){
//delete p;
}
bool push(int n){ // 정수 n을 스택에 푸쉬한다.
// 스택이 꽉 차 있으면 false, 아니면 true
if (tos == size - 1)	// 스택이 full
return false;
p[++tos] = n;

//cout << p[tos] << '\n';
return true;
}
bool pop(int &n){	// tos에 있는 값을 n에 팝한다.
if (tos == -1){
return false;
}
n = p[tos--];
//cout << p[tos] << '\n';
return false;
}
};

int main(){
MyIntStack a(10);
a.push(10);
a.push(20);

MyIntStack b = a;
b.push(30);

int n;
a.pop(n);
cout << "스택 a에서 팝한 값 " << n << endl;
b.pop(n);
cout << "스택 b에서 팝한 값 " << n << endl;

return 0;
}



*/



/*
작동시기에 k광년을 이동하였을 때는 
k-1 ,k 혹은 k+1 
광년만을 다시 이동할 수 있다. 
예를 들어, 이 장치를 처음 작동시킬 경우 -1 , 0 , 1 광년을 이론상 이동할 수 있으나 
사실상 음수 혹은 0 거리만큼의 이동은 의미가 없으므로 1 광년(k) 을 이동할 수 있으며, 
그 다음에는 0 , 1 , 2 광년을 이동할 수 있는 것이다. 
( 여기서 다시 2(k)광년을 이동한다면 다음 시기엔 1, 2, 3 광년을 이동할 수 있다. )
하지만 y지점에 도착해서도 공간 이동장치의 안전성을 위하여 
y지점에 도착하기 바로 직전의 이동거리는 반드시 1광년으로 하려 한다.

O(n) 으로 

3
an = a + (n-1)d
0	3		3  0 - 1 - (k=1)2 - 3
1	5		3
45 50		4

x,y = long

*/
