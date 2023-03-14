#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
public:
    Person(string name, int age) : name(name), age(age) {}
    virtual double getBonus() { return 0.0; }
};

class Admin : public Person {
public:
    double salary;
public:
    Admin(string name, int age, double salary) : Person(name, age), salary(salary) {}
    double getBonus() override { return salary * 0.1; }
};

class Account : public Person {
public:
    double balance;
public:
    Account(string name, int age, double balance) : Person(name, age), balance(balance) {}
    double getBonus() override { return balance * 0.05; }
};

class Master : public Admin, public Account {
public:
    Master(string name, int age, double salary, double balance) 
        : Admin(name, age, salary), Account(name, age, balance) {}
    double getBonus() override { return Admin::salary * 0.1 + Account::balance * 0.05; }
};

int main() {
    const int NUM_EMPLOYEES = 3;
    Person* employees[NUM_EMPLOYEES] = {
        new Admin("John", 30, 50000.0),
        new Account("Mary", 25, 100000.0),
        new Master("Bob", 40, 70000.0, 200000.0)
    };

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << "Bonus for " << employees[i]->name << ": " << employees[i]->getBonus() << endl;
    }

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        delete employees[i];
    }

    return 0;
}
