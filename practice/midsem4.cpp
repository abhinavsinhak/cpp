#include <iostream>
#include <string>
using namespace std;

class Train {
  public:  string name;
    int number;
    string source;
    string destination;
    string journeyDate;
    int capacity;
public:
    Train() {
        name = "";
        number = 0;
        source = "";
        destination = "";
        journeyDate = "";
        capacity = 0;
    }
    void input() {
       
        cout << "Enter Train Name: ";
        getline(cin, name);
        cout << "Enter Train Number: ";
        cin >> number;
        cout << "Enter Source Station: ";
        cin.ignore();
        getline(cin, source);
        cout << "Enter Destination Station: ";
        getline(cin, destination);
        cout << "Enter Journey Date (dd/mm/yyyy): ";
        cin.ignore();
        getline(cin, journeyDate);
        cout << "Enter Capacity: ";
        cin >> capacity;
        
    }
    void display() {
        cout << "Train Name: " << name << endl;
        cout << "Train Number: " << number << endl;
        cout << "Source Station: " << source << endl;
        cout << "Destination Station: " << destination << endl;
        cout << "Journey Date: " << journeyDate << endl;
        cout << "Capacity: " << capacity << endl;
    }
    ~Train() {
        cout << "Train details have been destroyed" << endl;
    }
};

int main() {
    Train train1;
    train1.input();
    Train train2;
    train2.input();
    Train train3;
    train3.input();
    
    string source, destination;
    cout << "Enter Source Station: ";
    getline(cin, source);
    cout << "Enter Destination Station: ";
    getline(cin, destination);
    
    try {
        if (train1.source == source && train1.destination == destination) {
            cout << "Train 1 details:" << endl;
            train1.display();
        } else if (train2.source == source && train2.destination == destination) {
            cout << "Train 2 details:" << endl;
            train2.display();
        } else if (train3.source == source && train3.destination == destination) {
            cout << "Train 3 details:" << endl;
            train3.display();
        } else {
            throw "No train matches the required source and destination";
        }
    } catch(const char* msg) {
        cerr << msg << endl;
    }
    
    return 0;
}
