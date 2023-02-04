#include <iostream>
using namespace std;
class student
{  public:
    int age;
    char name[20];
};

int main(void)
{    
    student s1;
        cin>>s1.name;
        cin>>s1.age;

        cout<<s1.name<<endl<<s1.age<<endl;
        
        
}