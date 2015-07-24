#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>

using namespace std;

class Item {
protected:
	int* idNum;
	long long int* id;
	string* name;
	int* year;
	float* someFloat;
public:
	Item() {
		idNum = new int(0);
		id = new long long int(0);
		name = new string(" ");
		year = new int(0);
		someFloat = new float(0.0);
	}
	Item(int idNum1, long long int id1, string name1, int year1, float somefloat1) {
		idNum = new int(idNum1);
		id = new long long int(id1);
		name = new string(name1);
		year = new int(year1);
		someFloat = new float(somefloat1);
	}
	~Item() {
		delete idNum;
		delete id;
		delete name;
		delete year;
		delete someFloat;

		idNum = 0;
		id = 0;
		name = 0;
		year = 0;
		someFloat = 0;

	}

	virtual void print() {
		cout << *idNum <<'\t' << *id <<'\t' << *name << '\t' << *year <<'\t' << *someFloat << '\t';
	}
	void setID(int *idNum1){
		 idNum = idNum1;
	}
	void setStringID(long long int *id1) {
		id = id1;
	}
	void setName(string *name1) {
		name = name1;
	}
	void setYear(int *year1) {
		year = year1;
	}
	void setSomeFloat(float *some) {
		someFloat = some;
	}
	int *getID() {return idNum;}
	long long int *getStringID() {return id;}
	string *getName(){return name;}
	int *getYear(){return year;}
	float *getFloat(){return someFloat;}
};

class Book : public Item {
protected:
	string *author;
	char *letter;
	int *someNum;
public:

	Book(){
	    author = new string(" ");
	    letter = new char(' ');
	    someNum = new int(0);
	}// : Item(), author(" "), letter(' '), someNumber(0) { }

	Book(int idNum1, long long int id1, string name1, string author1, char letter1, int year1, int someNumber1, float somefloat1) :  Item(idNum1, id1, name1, year1, somefloat1) {
	    author= new string(author1);
	    letter = new char(letter1);
	    someNum = new int(someNumber1);

	}
	~Book() {
		delete author;
		delete letter;
		delete someNum;
		someNum = 0;
	}




	virtual void print() {
	    cout <<"Book: ";
		Item::print();
		cout << *author << 't' << *letter << 't' <<*someNum << endl;
	}
	void setAuthor(string author1) {
		*author = author1;
	}
	void setLetter(char letter1) {
		*letter = letter1;
	}
	void setSomeNumber(int *someNum1){
		someNum = someNum1;
	}
	string *getAuthor() {return author;}
	char *getLetter() {return letter; }
	int *getSomeNumber() {return someNum;}
};

class DVD : public Item {
protected:
	string* director1;
	string* director2;
public:
	DVD(){
	    Item();
	    director1 = new string(" ");
	    director2 = new string(" ");
	}
	DVD(int idNum1, long long int id1, string name1, int year1, string director01, string director02, float somefloat1) : Item(idNum1, id1, name1, year1, somefloat1) {
        director1 = new string(director01);
        director2 = new string(director02);
    }
	~DVD() {
		delete director1;
		delete director2;
		director1 = 0;
		director2 = 0;
	}

	virtual void print() {
		cout <<"DVD: ";
		Item::print();
		cout << *director1 << '\t' << *director2 <<endl;
	}
	void setDirector1(string *d1) {
		director1 = d1;
	}
	void setDirector2(string *d2) {
		director2 = d2;
	}
	string *getDirector1() {
		return director1;
	}
	string *getDirector2() {
		return director2;
	}
};



int main() {

	ifstream ice ("Inventory.csv");
	int count = 0;
	string blank;
	while (!ice.eof()) {
	    getline(ice, blank, '\n');
		count ++;
	}
cout << "This is the count: " << count <<endl;
	Item *item[count+1];
	count = 0;
	int idNum;
	long long int id;
	string name;
	string author;
	char letter;
	int year;
	int someNumber;
	float somefloat;
	string director1;
	string director2;
	string storage;
	ifstream file ("Inventory.csv");
	if (file) {
    stringstream iss;
    while (getline(file, blank)) {
        iss << blank;
		getline(iss, storage, ',');
		idNum = atoi(storage.c_str());
		getline(iss, storage, ',');
		id = atoll(storage.c_str());
		getline(iss, name, ',');
		if (idNum < 5000) {
			getline(iss, author, ',');
			getline(iss, storage, ',');
			year = atoi(storage.c_str());
			getline(iss, storage, ',');
			letter=storage[0];
			getline(iss, storage, ',');
			someNumber = atoi(storage.c_str());
			getline(iss, storage, ',');
			somefloat = atof(storage.c_str());
			item[count] = new Book(idNum, id, name, author, letter, year, someNumber, somefloat);

		}
		else {
			getline(iss, storage, ',');
			year = atoi(storage.c_str());
			getline(iss, director1, ',');
			getline(iss, director2, ',');
			getline(iss, storage, ',');
			somefloat = atof(storage.c_str());
			item[count] = new DVD(idNum, id, name, year, director1, director2, somefloat);
		}
    iss.clear();
    count++;
    }

	}

	for (int c = 0; c < count; c++) {
            item[c]->print();
	}

    delete[] item;
	return 0;
}
