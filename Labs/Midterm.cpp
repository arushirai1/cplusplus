#include <string>
#include <iostream>
using namespace std;

class Employee {
    string* department;
    double* salary;
public:
    Employee();
    Employee(string dep, double sal);
    Employee(Employee& emp);
    ~Employee();
    void operator=(Employee& emp);

    string getDep() {
        return *department;
    }

    double getSal() {
        return *salary;
    }
};

    Employee::Employee() {
        department = new string(" ");
        salary = new double(0);
    }
    Employee::Employee(string dep, double sal) {
        department = new string(dep);
        salary = new double(sal);
    }
    Employee::Employee(Employee& emp) {
        department= new string(emp.getDep());
        salary = new double(emp.getSal());
    }
    Employee::~Employee() {
        delete department;
        delete salary;
        department = 0;
        salary = 0;
    }
    void Employee::operator =(Employee& emp) {
        *department=emp.getDep();
        *salary = emp.getSal();
    }

    int main() {
        Employee* pemployee = new Employee("IT",85000.0);

        Employee* pdepartment = new Employee[1000];

        //cout << pdepartment[123].getSal();
        Employee aemployee = pdepartment[123];

        pdepartment[555] = *pemployee;

        delete [] pdepartment;
        return 0;
    }
