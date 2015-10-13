
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;
class ItemInterface {
    public:
    string *person_name; //could be author or passenger name concatenated
    ItemInterface() {
        person_name = new string(" ");
    }

    ItemInterface(string person) {
        person_name = new string(person);
    }

    virtual void print() = 0;

};

template <class T> class Container : public ItemInterface{
public:
    vector<T> storage;

    Container(int numberofitems) {
        storage.resize(numberofitems);
    }
};


class Item {
protected:
	int* idNum;
	long long int* id;
	string* name;
	int* year;
	float* someFloat;
public:
	Item(){
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

class Book : public ItemInterface, public Item {
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

class Passenger : public ItemInterface {

private:
	string* firstname;
	string* lastname;
	int* row1;
	string* section;
	char* seat;

public:
	Passenger();
	Passenger(string fname, string lname, int row, char letter);
	~Passenger();

	void setFName(string fn);

	void setLName(string ln);

	virtual void print();

	string getFName();

	string getLName();

	void setOtherVariables(int row01, char seatLetter1);

	string getSector();


};

    Passenger::Passenger() {
		*firstname = " ";
		*lastname = " ";
	}

	Passenger::Passenger(string fname, string lname, int row, char letter) {
		firstname = new string(fname);
		lastname = new string(lname);
		seat = new char(letter);
		row1 = new int(row);
		//section = new string(" ");
	}

	Passenger::~Passenger() {
		delete firstname;
		delete lastname;
		firstname = NULL;
		lastname = NULL;
	}

	void Passenger::setFName(string fn) {
		*firstname = fn;
	}

	void Passenger::setLName(string ln) {
		*lastname = ln;
	}
	void Passenger::print() {
		std::cout << *firstname << '\t' << *lastname << '\t' << *row1<< '\t' << '\t' << *seat;
	}

	string Passenger::getFName() {
		return *firstname;
	}

	string Passenger::getLName() {
		return *lastname;
	}


int main() {

	ifstream ice ("Books.csv");
	int book_count = 0;
		cout << book_count << endl;

	string blank;
	while (!ice.eof()) {
	    getline(ice, blank, '\n');
		book_count ++;
	}
    ifstream ice2 ("Airline.csv");
	int passenger_count = 0;
		cout << passenger_count << endl;

	while (!ice2.eof()) {
	    getline(ice2, blank, '\n');
		passenger_count ++;
	}

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
    int count = 0;
	//Container<ItemInterface> c = new (ItemInterface)Container(passenger_count+book_count+1);
	ItemInterface* item [passenger_count+book_count+1];
	ifstream file ("Books.csv");
	if (file) {
    stringstream iss;
    while (getline(file, blank)) {
        iss << blank;
		getline(iss, storage, ',');
		idNum = atoi(storage.c_str());
		getline(iss, storage, ',');
		id = atoll(storage.c_str());
		getline(iss, name, ',');
        getline(iss, author, ',');
        getline(iss, storage, ',');
        year = atoi(storage.c_str());
        getline(iss, storage, ',');
        letter=storage[0];
        getline(iss, storage, ',');
        someNumber = atoi(storage.c_str());
        getline(iss, storage, ',');
        somefloat = atof(storage.c_str());
        //c.storage.push_back(new Book(idNum, id, name, author, letter, year, someNumber, somefloat));
        item[count] = new Book(idNum, id, name, author, letter, year, someNumber, somefloat);
    iss.clear();
    count++;
    }}

    string firstName, lastName, e;
	char seatLetter;
	int rowNumber;
	ifstream file2("Airline.csv");
    if (file2) {
        stringstream iss;
        while (getline(file2, blank)) {
            iss << blank;
            getline(iss, lastName, ',');
		getline(iss, firstName, ',');
		getline(iss, e, ',' );
		rowNumber = atoi(e.c_str());
		getline(iss, e, ',');
		seatLetter = e[0];
		getline(iss, e, ' ');

		//c.storage.push_back(new Passenger (firstName, lastName, rowNumber, seatLetter));
        item[count] = new Passenger(firstName, lastName, rowNumber, seatLetter);
        iss.clear();
        count++;
        }
    }

    for (int counter = book_count; counter < passenger_count-1; counter++)
		item[counter]->print();

    for (int counter = 0; counter < book_count-1; counter++)
		item[counter]->print();

	return 0;
}
