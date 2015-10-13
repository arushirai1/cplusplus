#include <string>
#include <iostream>

using namespace std;
class Newton {
  public:
    string type = "Newton";
    double value;
    Newton();
    Newton(double value);
    void operator=(Newton newton);
    void operator=(double val);
    int operator+(Newton newton);
    int operator*(Newton newton1);
    void add(double val);
};

    Newton::Newton() {
        value = 0.0;
    }
    Newton::Newton(double value) {
        this.value = value;
    }
    void Newton::operator=(Newton newton) {
        value = newton.value;
    }
    void Newton::operator=(double val) {
        value = val;
    }
    int Newton::operator+(Newton newton) {

    }
    int Newton::operator*(Newton newton1, Newton newton2) {

    }
    void Newton::add(double val) {
        value += val;

    }

public int main () {

    return 0;
}
