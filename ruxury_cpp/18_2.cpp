#include <iostream>
using namespace std;

class Converter {
protected:
	double ratio;
public :
	Converter(double ratio) : ratio(ratio) {}
	virtual double convert(double src) = 0;
	virtual string getSrcString() = 0;
	virtual string getDestString() = 0;
};

class WonToDollar : public Converter{
	string src, dest;
public:
	WonToDollar(int ratio) : Converter(ratio) { src = "원"; dest = "달러"; }

	double convert(double src) override {
		double result = src / ratio;

		cout << getSrcString() << "을 " << getDestString() << "로 바꿉니다. 입력된 " 
			<< getSrcString() << "은 " << src << getSrcString() << "입니다." << endl;
		cout << "변환결과 : " << result << getDestString() << endl;
		return result;
	}
	string getSrcString() override { return this->src; }
	string getDestString() override { return this->dest; }
};

class WonToYen : public Converter {
	string src, dest;
public:
	WonToYen(double ratio) : Converter(ratio) { src = "원"; dest = "엔"; }

	double convert(double src) override {
		double result = src / ratio;

		cout << getSrcString() << "을 " << getDestString() << "로 바꿉니다. 입력된 "
			<< getSrcString() << "은 " << src << getSrcString() << "입니다." << endl;
		cout << "변환결과 : " << result << getDestString() << endl;
		return result;
	}
	string getSrcString() override { return this->src; }
	string getDestString() override { return this->dest; }
};

int main() {
	WonToDollar wd(1130);
	Converter * cv;
	cv = &wd;
	cv->convert(10000);
	WonToYen wy(100.6);
	cv = &wy;
	cv->convert(10000);
	return 0;
}