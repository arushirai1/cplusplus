#include <string>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Date {

private:
    int month;
    int year;
    int day;

public:
    Date();
    Date(int month,int year,int day);
    void displayDate();
    bool isLeapYear();
    void add(string date);
    void addDay(int day);
    void addMonth(int month);
    void addYear(int year);
};

Date::Date() {
    month = 0;
    year = 0;
    day = 0;
}

Date::Date(int month, int day, int year) {
    this->month = month;
    this->year = year;
    this->day = day;
}

void Date::displayDate() {
    cout << month << "/" << day << "/" << year <<endl;
}

bool Date::isLeapYear() {
    bool isLeapYear = false;
    if(year%4 == 0 && year%100 != 0)
        isLeapYear = true;
    else if(year%100 == 0 && year%400 == 0)
        isLeapYear = true;

    return isLeapYear;
}

void Date::add(string date) {
    int num = atoi(date.substr(0,date.length()-2).c_str());
    char* type = new char(date[date.length()-1]);
    char* typeComp = new char('Y');
    if(!strcmp(type, typeComp))
        addYear(num);
    *typeComp = 'M';
    if(!strcmp(type, typeComp))
        addMonth(num);
    else
        addDay(num);

    delete type;
}
void Date::addDay(int day) {
    if((this->day + month*30)+ day <= 365 || isLeapYear() && this->day + day <= 366) {
        addMonth(day%30);
        this->day = day-30*(day%30);
    }

    else {
        isLeapYear()? day-=366 : day-=365;
    }
}
void Date::addMonth(int month) {
    if(this->month + month <= 12)
        this->month += month;
    else {
        addYear(1);
        addMonth(month - 12);
    }
}
void Date::addYear(int year) {
    this->year+= year;
    isLeapYear()? day-=1 : day-=0;
}

int main() {
    Date* date = new Date(4, 3, 2015);
    date->add("1Y"); //4/2/2016 (leap year added 1 day)
    date->displayDate();
    /*4/3/2015 + 120D = 8/2/2015
    4/3/2015 + 3M = 8/2/2015 */
    return 0;
}
