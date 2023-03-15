#include <iostream>
using namespace std;
class complex
{
    int a, b;

public:
    void getvalue()
    {
        cout << "Enter the value of Complex Numbers a,b:";
        cin >> a >> b;
    }
    complex operator+(complex ob)
    {
        complex t;
        t.a = ob.a + a;
        t.b = ob.b + b;
        return (t);
    }
    complex operator-(complex ob)
    {
        complex t;
        t.a = ob.a - a;
        t.b = ob.b - b;
        return (t);
    }
    void display()
    {
        cout << a << "+" << b << "i" << endl;
    }
};
int main()
{
    complex obj1, obj2, result, result1;
    obj1.getvalue();
    obj2.getvalue();
    result = obj1 + obj2;
    result1 = obj1 - obj2;
    cout << "Input Values:\n";
    obj1.display();
    obj2.display();
    cout << "Result:\n";
    result.display();
    result1.display();
    return 0;
}
