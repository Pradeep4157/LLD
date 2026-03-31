#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
    AGGREGATION :

    the member object can belong to more than 1 class.

    The life time of the member object is not controlled by the base class.

    Eg : A house can belong to more than 1 person. Even if Person obj is destroyed that doesnt mean house is also destroyed.

    So for aggregations instead of creating objects inside the Parent class i.e., instead of making member variables.

    We give pointers of that object to the required classes.

    It is similar to 1 ->  many relationship where 1 is home and many are the people that own the home ..

    home doesnt know how many person have the pointer to  this home or how many are deleted

    But Each of the person knows the amount of houses it has.


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
