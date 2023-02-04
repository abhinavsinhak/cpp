#include <iostream>
using namespace std;
class hero
{
    int health;
    char level;

public:
    int gethealth()
    {
        return health;
    }
    void sethealth(int n)
    {
        health = n;
    }
    char getlevel(){

        return level;
    }
    void setlevel(char t)
    {
        level = t;
    }
    
};

int main()
{

    hero h1;
    int n1;char n2;
    cout << "give health" << endl;
    cin>>n1;
    h1.sethealth(n1);
    cout << "give the level" << endl;
    cin>>n2;
    h1.setlevel(n2);

    // printing the level hh
     
    cout<<"health\n"<<h1.gethealth()<<endl;
    cout<<"level\n"<<h1.getlevel()<<endl;

    return 0;
}