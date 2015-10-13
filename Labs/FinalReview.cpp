// FinalReview
//

//#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

void print(string s)
{
	cout << s << endl;
}

class Person
{
public:
	Person() { print("Person()"); }
	Person(char*) { print("Person(char*)"); }
	Person(Person&) : Person("Bob") { print("Person(Person&)"); }
	~Person(){ print("~Person()"); }
	Person operator = (Person&) { print("Person op=()"); return *this; }
	void nonvirtualfunction() {print("PARENTTTTTT");}
	virtual void virtualfunction() { print("Person::function"); };
};

class Student : public Person
{
public:
	Student() { print("Student()"); }
	Student(char*) { print("Student(char*)"); }
	Student(Student&) { print("Student(Student&)"); }
	~Student()  { print("~Student()"); }
    void virtual nonvirtualfunction() {print("STUDENTTTTTT");}
	void virtualfunction()  { print("Student::function"); }
};

int main()
{
 Person* pbase = new Person;
 Student* pderived = new Student;
  Person base = *pbase;
  cout<<"---------------"<<endl;
   Student derived = *pderived;
     cout<<"---------------"<<endl;

    base = *pbase;
      cout<<"---------------"<<endl;
      derived = *pderived;

  cout<<"---------------"<<endl;
    *pbase = *pderived;

  cout<<"---------------"<<endl;



	return 0;
}




