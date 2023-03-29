#include <iostream>
#include <string>

using namespace std;

class person{
public:
    int id;
    char* name;
    virtual void input(){};
    virtual void data(){};
    virtual ~person(){}
};

class admin : virtual public person {
public:
    int alvl;
    virtual void input(){};
    virtual void data(){};
};

class account : virtual public person {
public:
    int basepay;
    virtual void input(){};
    virtual void data(){};
};

class master : public admin, public account {
public:
    int gross;
    void input(){cout<<"enter ";
        cin>>person::name;
        cout<<"ID";
        cin>>admin::id;
        cout<<"ALVL";
        cin>>admin::alvl;
        cout<<"basepay:";
        cin>>account::basepay;
        gross=basepay*2;
    }
    void data(){
        cout<<admin::name;
        cout<<admin::id;
        cout<<admin::alvl;
        cout<<account::basepay;
        cout<<gross;
    }
};

int main() {
    cout << "Hello world!";
    person *p;
    master m;
    p=&m;
    p->input();
    p->data();

    return 0;
}