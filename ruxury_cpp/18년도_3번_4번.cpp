#include <iostream>
using namespace std;

class Storage {
	int nData;
	int* strg;
public:
	Storage(int nData) {
		this->nData = nData;
		strg = new int[nData];
		cout << "자료 " << nData << "개 입력" << endl;

		bool IsOverlap; // 중복 체크
		for (int i = 0; i < nData; i++) {
			IsOverlap = false;
			int temp;	// 입력 임시 변수
			cin >> temp;
			for (int j = 0; j < i; j++) {
				if (strg[j] == temp) // 중복
				{
					IsOverlap = true;
					break;
				}
			}
			if (!IsOverlap) {
				strg[i] = temp;
			}
			else
			{
				cout << temp << "<중복>" << endl;
				i--;
			}
		}
		cout << "입력완료: ";
		for (int i = 0; i < nData; i++) {
			cout << strg[i] << ' ';
		}
		cout << endl;
	}
	~Storage() {
		delete[]strg;
	}
	Storage(const Storage& s1) {
		// 깊은 복사
		this->nData = s1.nData;
		this->strg = new int[nData];
		for (int i = 0; i < nData; i++) {
			strg[i] = s1.strg[i];
		}
	}
	void showList() {
		cout << nData << ":";
		for (int i = 0; i < nData; i++) {
			cout << strg[i] << ' ';
		}
		cout << endl;
	}
	void addnDatas(int n) {
		cout << "자료 " << n << "개 추가 입력:";
		int* newArr = new int[nData + n];
		for (int i = 0; i < nData; i++) {
			cout << strg[i] << ' ';
			newArr[i] = strg[i]; // 임시 배열에 기존에 있는거 복사
		}
		cout << endl;

		bool IsOverlap;
		for (int i = 0; i < n; i++) {
			int temp;
			IsOverlap = false;
			cin >> temp;
			for (int j = 0; j < nData; j++) {
				if (temp == strg[j]) {
					IsOverlap = true;
					break;
				}
			}
			if (IsOverlap) {
				cout << temp << "<중복>" << endl;
				i--;
			}
			else { // 중복이 아니면 추가
				newArr[nData + i] = temp;
			}
		}
		nData += n;
		cout << "자료 ";
		for (int i = nData-n; i < nData; i++) {
			cout << newArr[i] << ' ';
		}
		cout << "추가" << endl;
		// 기존거 삭제후 추가
		delete[]strg;
		strg = newArr;
	 }
	void subStrg(Storage& s2) {
		// this 객체와 s2와 비교 후 s2와 동일한 자료면 this에서 중복제외
		// 10 3 4 5 1 12 15 - 3 9 10
		int* newArr = new int[nData];
		int newSize = 0;
		bool IsSame;
		for (int i = 0; i < nData; i++) {
			IsSame = false;
			for (int j = 0; j < s2.nData; j++) {
				if (strg[i] == s2.strg[j]) {
					IsSame = true;
					break;
				}
			}
			if (!IsSame)
				newArr[newSize++] = strg[i];
		}
		nData = newSize;
		delete[] strg;
		strg = newArr;
	 }
};

int main() {
	Storage s1(4); // 10 3 4 5
	s1.showList();

	Storage s2(s1); // 복사생성자
	s2.showList();
	s2.addnDatas(3);
	s2.showList();
	//------------------ 3번

	Storage s3(3); // 3 9 10
	s3.showList();
	s2.subStrg(s3);
	s2.showList();
	// s2에 대하여 s3와 같은 자료가 있다면 s2에서 삭제한다.
	
	return 0;
}
