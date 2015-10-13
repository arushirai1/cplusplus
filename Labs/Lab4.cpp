#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <sstream>
using namespace std;
class Scores {
    vector<int> scores;
    double average;

public:
    string* firstname;
    string* lastname;
    Scores();
    Scores(string first, string last);
    ~Scores();
    friend bool operator < (const Scores& one, const Scores& two) {
        bool result = false;
        string f1 = const_cast<Scores&>(one).getName();
        string f2 = const_cast<Scores&>(two).getName();
        int res = f1.compare(f2);
        if (res < 0) {result = true;}
        return result;
    }

    string getName() {
        return *firstname;
    }
    void calculateAverage();
    void init(string first, string last);
    void add(int score);
};
    Scores::Scores() {
        firstname = new string (" ");
        lastname = new string (" ");
    }
    Scores::Scores(string first, string last) {
        firstname = new string(first);
        lastname = new string(last);
    }

    Scores::~Scores() {
        delete firstname;
        delete lastname;
        firstname = 0;
        lastname = 0;
    }
   /* bool Scores::operator < (const Scores& one, Scores& two) {
        bool result = false;
        int res = one.firstname.compare(two.firstname);
        if (res < 0) {result = true;}
        return result;
    } */

    void Scores::init(string first, string last) {
        *firstname = first;
        *lastname = last;
    }

    void Scores::add(int score) {
        scores.push_back(score);
    }

    void Scores::calculateAverage() {
        average = accumulate(scores.begin(), scores.end(), 0.0, plus<int>());
        average = average/10;
    }


int main() {
    vector<Scores> student (501);
    ifstream file("Scores.csv");
    string blank;
    stringstream stream;
    int count = 0;
    while (getline(file, blank)) {
        stream << blank;
        int counter = 1;
        while (getline(stream, blank, ',')) {
            if(counter < 2) {
                string s;
                getline(stream, s, ',');
                student[count].init(blank, s);
                counter++;
            }

            else {
                student[count].add(atoi(blank.c_str()));
            }
        }
         stream.clear();
         count++;
    }

    sort(student.begin(), student.end());

    for (int counter = 0; counter < 501; counter++) {
        student[counter].calculateAverage();
    }



    return 0;
}
