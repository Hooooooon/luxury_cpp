#include <iostream>
#include <string>
using namespace std;
class Book {
	string str;
	int price;
	const char* publishedDate;	// 출판인
public:
	Book() {
		str = "";
		price = 0;
		publishedDate = NULL;
	}
	Book(const char* title, int price, const char* pDate) {
		str = title;
		this->price = price;
		publishedDate = pDate;
	}
	void set(const char* title, int price, const char* pDate) {
		str = title;
		this->price = price;
		publishedDate = pDate;
	}
	void show() {
		cout << str << ' ' << price << ' ' << publishedDate << endl;
	}
	void setTitle(string str) {
		this->str = str;
	}
	string getTitle() {
		return str;
	}
};

// oldTitle이 있다면 nteTitle로 변경하고 없으면 -1
int replaceBookTitle(Book* books, int nbks, const char* oldtitle, const char* newtitle) {
	int changeIndex = -1;
	for (int i = 0; i < nbks; i++) {
		if (books[i].getTitle() == oldtitle) {
			books[i].setTitle(newtitle);
			changeIndex = i;
		}
	}
	return changeIndex;
}

int main() {
	Book bookShelf[3] = {
		Book("C#프로그래밍", 20000, "09012016"),
		Book("c++", 25000, "09022018"),
		Book()
	};
	bookShelf[2].set("Java programming", 28000, "12052017");

	bookShelf[2].show();
	bookShelf[0].show();
	bookShelf[1].show();
	int n = replaceBookTitle(bookShelf, 3, "c++", "C++");
	if ( n < 0)
		cout << "책이름이 없습니다." << endl;
	else
		bookShelf[n].show(); 
	return 0;
}