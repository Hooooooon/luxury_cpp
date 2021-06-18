#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class MyString {
	int m_nLen;// 문자열 길이
	char* m_pStr; // 문자열
public :
	MyString();
	MyString(const char* str);
	// 복사 대입 연산자 정의
	MyString(MyString& p) { // 복사 생성자
		m_nLen = p.m_nLen;
		m_pStr = new char[m_nLen];
		strcpy(m_pStr, p.m_pStr);
	}
	~MyString();
	MyString& operator = (const MyString& op2) { // 대입 연산자
		this->m_nLen = op2.m_nLen;
		this->m_pStr = new char[this->m_nLen];
		strcpy(this->m_pStr, op2.m_pStr);
		return *this;
	}
	friend ostream & operator << (ostream & os, MyString& temp);
	friend MyString operator + (MyString op1, MyString op2);
	friend MyString operator - (MyString op1, MyString op2);
};

MyString::MyString() {
	m_nLen = 1;
	m_pStr = new char[m_nLen];
	strcpy(m_pStr, "");
}
MyString::MyString(const char* str) {
	m_nLen = strlen(str) + 1;
	m_pStr = new char[m_nLen];
	strcpy(m_pStr, str);
}
MyString::~MyString() {
	delete[] m_pStr;
	m_nLen = 0;
	m_pStr = NULL;
}

ostream& operator << (ostream& os, MyString& temp) {
	cout << temp.m_pStr;
	return os;
}

MyString operator + (MyString op1, MyString op2) {
	MyString newStr;
	newStr.m_nLen = strlen(op1.m_pStr) + strlen(op2.m_pStr) + 1;
	newStr.m_pStr = new char[newStr.m_nLen];
	for (int i = 0; i < strlen(op1.m_pStr); i++) {
		newStr.m_pStr[i] = op1.m_pStr[i];
	}
	for (int i = 0; i < strlen(op2.m_pStr) + 1; i++) {
		newStr.m_pStr[i+strlen(op1.m_pStr)] = op2.m_pStr[i];
	}
	return newStr;
}

MyString operator - (MyString op1, MyString op2) {
	MyString newStr;
	newStr.m_nLen = (op1.m_nLen - 1) + op2.m_nLen;
	newStr.m_pStr = new char[newStr.m_nLen];
	int newSize = 0;

	for (int i = 0; i < op1.m_nLen - 1; i++) {
		bool IsDelete = false;
		for (int j = 0; j < op2.m_nLen - 1; j++) {
			if (tolower(op1.m_pStr[i]) == tolower(op2.m_pStr[j]))
				IsDelete = true;
		}
		if (!IsDelete)
			newStr.m_pStr[newSize++] = op1.m_pStr[i];
	}
	for (int i = 0; i < op2.m_nLen - 1; i++) {
		bool IsDelete = false;
		for (int j = 0; j < op1.m_nLen - 1; j++) {
			if (tolower(op2.m_pStr[i]) == tolower(op1.m_pStr[j]))
				IsDelete = true;
		}
		if (!IsDelete)
			newStr.m_pStr[newSize++] = op2.m_pStr[i];
	}
	newStr.m_nLen = newSize + 1;
	newStr.m_pStr[newSize] = '\0';

	return newStr;
}


int main() {
	MyString strA("Banana");
	MyString strB("Orange");
	MyString strC;
	MyString strD;

	cout << "strA=>" << strA << endl;
	cout << "strB=>" << strB << endl;

	// + 연산자 오버로딩
	strC = strA + strB;
	cout << "strC = " << strC << endl;

	// - 연산자 오버로딩
	strD = strA - strB;
	cout << "strD = " << strD << endl;
	return 0;
}