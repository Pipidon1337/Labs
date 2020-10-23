#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Ticket {
    struct Place{
        string country;
        string town;
    };
    int raceNumber;
    Place arrive_place;
    string fullname;
    struct Date{
        int day;
        int month;
        int year;
    };
    Date arrive_date;
};
int menu() {
    int choose;
    cout << "Select operation\n";
    cout << "1 - Add ticket " << endl << "2 - Delete ticket " << endl ;
    cout << "3 - Show tickets list with your number and name" << endl << "4 - Show all tickets" << endl;
    cout << "0 - Exit" << endl;
    cout << "Select: ";
    cin >> choose;
    return choose;
}
bool operator<(const Ticket& c1, const Ticket& c2)
{
    return c1.raceNumber < c2.raceNumber;
}
void operator<<(ostream& stream,const Ticket& c){
    stream << "1)Full name: " << c.fullname<< endl << "2)Race Number: " << c.raceNumber << endl;
    stream << "3)Place of arriving: " << c.arrive_place.country << "," << c.arrive_place.town << endl;
    stream<<"4)Date of arriving: "<<c.arrive_date.day<<"."<<c.arrive_date.month<<"."<<c.arrive_date.year<<endl;
}
int main() {
    priority_queue<Ticket> q;
    int rep = 1, a = 0;
    while (rep == 1)
    {
        Ticket item;
        a = menu();
        switch (a) {
            case 1: {
                cout << "Enter passenger name" << endl;
                cin >> item.fullname;
                cout << "Enter country of arriving" << endl;
                cin >> item.arrive_place.country;
                cout << "Enter town of arriving" << endl;
                cin >> item.arrive_place.town;
                cout << "Enter year of arriving" << endl;
                cin >> item.arrive_date.year;
                cout << "Enter month of arriving" << endl;
                cin >> item.arrive_date.month;
                cout << "Enter day of arriving" << endl;
                cin >> item.arrive_date.day;
                cout << "Enter RaceNumber" << endl;
                cin >> item.raceNumber;
                cout<< "item is:";
                cout << item;
                q.push(item);
                break;
            }
            case 2: {
                string d_fullname;
                cout << "Enter your name which ticket you want to delete" << endl;
                cin >> d_fullname;
                vector<Ticket> buff;
                while(!q.empty()){
                    buff.push_back(q.top());
                    q.pop();
                }
                for(auto& item : buff){
                    if(item.fullname != d_fullname){
                        q.push(item);
                    }
                }
                buff.clear();
                break;
            }
            case 3: {
                vector<Ticket> buff;
                while(!q.empty()){
                    buff.push_back(q.top());
                    q.pop();
                }
                for(auto& item : buff){
                    cout << item;
                }
                buff.clear();
                break;
            }
            case 4:
            {
                vector<Ticket> buff;
                for(auto& item : buff) {
                    cout << item;
                }
            }
        }
        while(!q.empty()) {q.pop();}
        return 0;
    }
}
