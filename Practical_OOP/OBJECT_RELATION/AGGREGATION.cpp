#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
    AGGREGATION :

    the member object can belong to more than 1 class.

    The life time of the member object is not controlled by the base class.

    Eg : A house can belong to more than 1 person. Even if Person obj is destroyed that doesnt mean house is also destroyed.


    37:08



*/

class Home
{
public:
    Home(string address_) : address(address_) {}
    ~Home()
    {
        cout << "~Home of address: " << address << endl;
    }

private:
    string address;
};
// Object 1
class Person
{
public:
    Person(string person_name_, Home *home_) : person_name(person_name_), home(home_) {}
    void Breathe();
    void Walk();
    ~Person()
    {
        cout << "~Person " << person_name << endl;
    }

private:
    Home *home;
    string person_name;
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Home home("Adress_1");
    Person *person1 = new Person("A", &home);
    Person *person2 = new Person("B", &home);

    return 0;
}
