#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <sstream>

using namespace std;

class Row {
private:
	int* rowNumber;
public:
	Row() {
		rowNumber = new int(0);
	}
	Row(int rownum) {
        rowNumber = new int(rownum);
	}
	~Row() {
		delete rowNumber;
		rowNumber = 0;
	}

	void setRowNumber(int rownum) {
		*rowNumber = rownum;
	}

	int* getRowNumber() {
		return rowNumber;
	}

};

class Section {
	string sectionName;
public:
	Section() {
		sectionName = " ";
	}
	Section(int rowNum) {
        sectionLocator(rowNum);
	}

	~Section() {
		sectionName = "";
	}

	Section(string sectionstr) {
		sectionName = sectionstr;
	}
	string getSection() {
		return sectionName;
	}

	string sectionLocator(int rowNum) {

		if (rowNum <= 4){ sectionName = "First Class"; }
		else if (rowNum <= 14) { sectionName = "Business Class"; }
		else { sectionName = "Economy Class"; }

		return sectionName;

	}
};

class Seat {
	char* seatLetter;
public:
	Seat() {
		*seatLetter = ' ';
	}

	~Seat() {

	}

	Seat(char seat) {
		*seatLetter = seat;
	}

	void setSeat(char seat) {
		*seatLetter = seat;
	}

};

class Passenger {

private:
	string* firstname;
	string* lastname;
	Row* row1;
	Section* section;
	Seat* seat;

public:
	Passenger();
	Passenger(string fname, string lname, int row);
	~Passenger();

	void setFName(string fn);

	void setLName(string ln);

	void list();

	string getFName();

	string getLName();

	void setOtherVariables(int row01, char seatLetter1);

	string getSector();


};

    Passenger::Passenger() {
		*firstname = " ";
		*lastname = " ";
	}

	Passenger::Passenger(string fname, string lname, int row) {
		firstname = new string(fname);
		lastname = new string(lname);
		row1 = new Row;
		section = new Section(row);
        seat = new Seat;
		row1->setRowNumber(row);

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
	void Passenger::list() {
		std::cout << firstname << '\t' << lastname << '\t' << row1->getRowNumber();
	}

	string Passenger::getFName() {
		return *firstname;
	}

	string Passenger::getLName() {
		return *lastname;
	}

	void Passenger::setOtherVariables(int row01, char seatLetter1) {
		//row1 = new Row(row01);
		row1->setRowNumber(row01);
		seat->setSeat(seatLetter1);
	}

	string Passenger::getSector() {
		return section->getSection();
	}


int main() {
	ifstream input1;
	input1.open("Airline.csv");
	int count = 0;
	Passenger *p [400];
	string firstName, lastName, e;
	char seatLetter;
	int rowNumber;
    stringstream input;
    count = 0;

    while (count < 400) {
        //cout <<"Round2";
        getline(input1, e);
        cout << "Test" << endl;
        input << e;
		getline(input, lastName, ',');
		getline(input, firstName, ',');
		getline(input, e, ',' );
		rowNumber = atoi(e.c_str());
		getline(input, e, ',');
		seatLetter = e[0];
		getline(input, e, ' ');

		p[count] = new Passenger (firstName, lastName, rowNumber);
		cout << lastName << endl;
		cout << rowNumber << endl;
		cout << p[count] -> getSector();
        input.clear();
        count++;
    }
	for (int counter = 0; counter < 2; counter++) {
		if (p[counter]->getSector() == "First Class")
			p[counter]->list();
	}
	for (int counter = 0; counter < 2; counter++) {
		if (p[counter]->getSector() == "Business Class")
			p[counter]->list();
	}
}
