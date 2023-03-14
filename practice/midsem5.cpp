#include <iostream>
#include <memory>

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
    std::unique_ptr<Person> employees[NUM_EMPLOYEES] = {
        std::make_unique<Admin>("John", 30, 50000),
        std::make_unique<Account>("Mary", 25, 100000),
        std::make_unique<Master>("Bob", 40, 70000, 200000)
    };

    for (const auto& employee : employees) {
        std::cout << employee->getBonus() << std::endl;
    }

    return 0;
} 
