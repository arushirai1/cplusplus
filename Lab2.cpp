#include <iostream>
#include <string>

using namespace std;

class Item {
protected:
	int* idNum;
	string* id;
	string* name;
	int* year;
	float* someFloat;
public:
	Item() {
		*idNum = 0;
		*id = " ";
		*name = " ";
		*year = 0;
		*someFloat = 0.0;
	}
	Item(int idNum1, string id1, string name1, int year1, float somefloat1) {
		*idNum = idNum1;
		*id = id1;
		*name = name1;
		*year = year1;
		*someFloat = somefloat1;
	}
	~Item() {
		delete idNum;
		delete id;
		delete name;
		delete year;
		delete someFloat;

		idNum = 0;
		id = NULL;
		name = NULL;
		year = 0;
		someFloat = 0;

	}
	void setID(int idNum1){
		*idNum = idNum1;
	}	
	void setStringID(string id1) {
		*id = id1;
	}
	void setName(string name1) {
		*name = name1;
	}
	void setYear(int year1) {
		*year = year1;
	}
	void setSomeFloat(float some) {
		*someFloat = some;
	}
	int getID() {return *idNum;}
	string getStringID() {return *id;}
	string getName(){return *name;}
	int getYear(){return *year;}
	float getFloat(){return *someFloat;}
};

class Book : public Item {
protected:
	string* author;
	char* letter;
	int* someNumber;
public:
	Book();
	Book(int idNum1, string id1, string name1, string author, char letter1, int year1, int someNumber1, float somefloat1);
	~Book();
	void setAuthor(string author1);
	void setLetter(char letter);
	void setSomeNumber(int someNum);
	string getAuthor();
	char getLetter();
	int getSomeNumber();

};

class DVD : public Item {
protected:
	string* director1;
	string* director2;
public:
	DVD();
	DVD(int idNum1, string id1, string name1, int year1, string director01, string director02, float somefloat1);
	~DVD();
	void setDirector1(string d1);
	void setDirector2(string d2);
	string getDirector1();
	string getDirector2();

};



int main() {
	int idNum1 = 1;
	Item *it [13];
	it[0] = new DVD();
	return 0;
}
