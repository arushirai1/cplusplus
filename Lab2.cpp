#include <iostream>
#include <fstream>
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
		year = 0;
		someFloat = 0;

	}

	virtual void print() {
		cout << *idNum <<'\t' << *id <<'\t' << *name << '\t' << *year <<'\t' << *someFloat << '\t';
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
	Book() : Item(), author(" "), letter(' '), someNumber(0) { }
	Book(int idNum1, string id1, string name1, string author1, char letter1, int year1, int someNumber1, float somefloat1) : Item(idNum1, id1, name1, year1, somefloat1), author(author1), letter(letter1) { }
	~Book() {
		delete author;
		delete letter;
		delete someNumber;
		someNumber = 0;
	}

	virtual void print() {
		Item::print();
		cout << *author << 't' << *letter << 't' <<*someNumber << endl;
	}
	void setAuthor(string author1) {
		*author = author1;
	}
	void setLetter(char letter1) {
		*letter = letter1;
	}
	void setSomeNumber(int someNum){
		*sumNum = sumNum1;
	}
	string getAuthor() {return *author;}
	char getLetter() {return *letter; }
	int getSomeNumber() {return *someNumber;} 
};

class DVD : public Item {
protected:
	string* director1;
	string* director2;
public:
	DVD() : Item(), director1(" "), director2(" ") { };
	DVD(int idNum1, string id1, string name1, int year1, string director01, string director02, float somefloat1) : Item(idNum1, id1, name1, year1, somefloat1), director1(director01), director2(director02) { }
	~DVD() {
		delete director1;
		delete director2;
	}

	virtual void print() {
		cout <<
		Item::print();
		cout << *director1 << '\t' << *director2 <<endl;
	}
	void setDirector1(string d1) {
		*director1 = d1;
	}
	void setDirector2(string d2) {
		*director2 = d2;
	}
	string getDirector1() {
		return *director1;
	}
	string getDirector2() {
		return *director2;
	}
};



int main() {
	istream file ("Inventory.csv");
	int count;
	while (!file.eof()) {
		count ++;	
	}	
	
	Item *item[count];
	
	count = 0;
	char idNum [20];
	char id [20]; 
	char name [40]; 
	char author [20]; 
	char letter [20]; 
	char year[20]; 
	char someNumber[20]; 
	char somefloat[20];
	char director1[20];
	char director2[20];
	while (!file.eof()) {
		//int idNum1, string id1, string name1, int year1, float somefloat1
		getline(file, idNum, ',');
		getline(file, id, ',');
		getline(file, name, ',');
		if ((int) idNum < 5000) {
			//int idNum1, string id1, string name1, string author1, char letter1, int year1, int someNumber1, float somefloat1
			//author(" "), letter(' '), someNumber(0)
			getline(file, author, ',');
			getline(file, letter, ',');
			getline(file, year, ',');
			getline(file, someNumber, ',');
			getline(file, somefloat, ',');
			*item[count] = new Book((int) idNum, (string) id, (string) name1, (string) author1, (char) letter1, (int) year1, (int) someNumber1, (float) somefloat1);

		}
		else {
			getline(file, year, ',');
			getline(file, director1, ',');
			getline(file, director2, ',');
			getline(file, somefloat, ',');
			*item[count] = new DVD((int) idNum, (string) id, (string) name, (int) year, (string) director1, (string) director2, (float) somefloat1);		
		}

		count++;
	}

	for (Item p : item) {
		p.print();
	}
	
	return 0;
}
