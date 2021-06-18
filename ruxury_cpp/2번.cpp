#include <iostream>
#include <string>
using namespace std;
class Converter {
protected:
	double ratio;
public :
	Converter(double ratio) { this->ratio = ratio; }
	// 추상 메소드
	virtual double convert(double src) =0 ; 
	virtual string getSrcStsring() = 0;
	virtual string getDestString() = 0;
};

class WonToDollar : public Converter {
	string won, dollor;
public :
	WonToDollar(int ratio) : Converter(ratio){
		this->won = "원"; this->dollor = "달러";
	}
	double convert(double src);	// 환율 계싼
	string getSrcStsring() { return won; }
	string getDestString() { return dollor; }
};

double WonToDollar::convert(double src) {
	cout << getSrcStsring() << "을 " << getDestString() << "으로 바꿉니다" << endl;
	src /= ratio;
	cout << "변환결과 : " << src << endl;
	return ratio;
}

int main() {
	double src;
	WonToDollar wd(1130);	// ratio 1130
	Converter* cv; // 업 캐스팅
	cv = &wd;
	cv->convert(10000);	// won 10000 -> dolor
}