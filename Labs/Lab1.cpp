#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <sstream>

using namespace std;

class Passenger{

private:
	string* firstname;
	string* lastname;
	int* row1;
	string section;
	char* seat;

public:
	Passenger();
	Passenger(string fname, string lname, int row, char letter);
	~Passenger();

	void setFName(string fn);

	void setLName(string ln);

	virtual void list();

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
	void Passenger::list() {
		std::cout << *firstname << '\t' << *lastname << '\t' << *row1<< '\t' << '\t' << *seat << '\t' <<section << endl;
	}

	string Passenger::getFName() {
		return *firstname;
	}

	string Passenger::getLName() {
		return *lastname;
	}



	string Passenger::getSector() {
		if (*row1 <= 4){ section= "First Class"; }
		else if (*row1 <= 14) { section= "Business Class"; }
		else { section= "Economy Class"; }

		return section;
	}


int main() {
    string blank;
    ifstream ice2 ("Airline.csv");
	int passenger_count = 0;
    cout << passenger_count << endl;

	while (!ice2.eof()) {
	    getline(ice2, blank, '\n');
		passenger_count ++;
	}


	Passenger* item [passenger_count+1];


    string firstName, lastName, e;
	char seatLetter;
	int rowNumber,count=0;
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

for (int counter = 0; counter < passenger_count; counter++) {
		if (item[counter]->getSector() == "First Class")
			item[counter]->list();
	}
	for (int counter = 0; counter < passenger_count; counter++) {
		if (item[counter]->getSector() == "Business Class")
			item[counter]->list();
	}


	return 0;
}
