#include <iostream>
using namespace std;

class Person {
protected:
    std::string name;
    int age;
public:
    Person(std::string name, int age) : name(name), age(age) {}
    virtual int getBonus() const { return 0; }
    virtual ~Person() {}
};

class Admin : public Person {
protected:
    int salary;
public:
    Admin(std::string name, int age, int salary) : Person(name, age), salary(salary) {}
    int getBonus() const override { return salary * 0.1; }
};

class Account : public Person {
protected:
    int balance;
public:
    Account(std::string name, int age, int balance) : Person(name, age), balance(balance) {}
    int getBonus() const override { return balance * 0.05; }
};

class Master : public Person {
protected:
    Admin admin;
    Account account;
public:
    Master(std::string name, int age, int salary, int balance)
        : Person(name, age), admin(name, age, salary), account(name, age, balance) {};

    int getBonus() const override { return admin.getBonus() + account.getBonus();}
};


int main() {
    const int NUM_EMPLOYEES = 3;
    Person* employees[NUM_EMPLOYEES] = {
        new Admin("John", 30, 50000),
        new Account("Mary", 25, 100000),
        new Master("Bob", 40, 70000, 200000)
    };

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << employees[i]->getBonus() << endl;
    }

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        delete employees[i];
    }

    return 0;
}