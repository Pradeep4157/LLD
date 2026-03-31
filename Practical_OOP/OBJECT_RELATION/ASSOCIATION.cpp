#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
    ASSOCIATION:

    this is similar to many to many relationship Person owns multiple homes and home is owned by multiple

    people..

    so one of the solution is that when a Person owns a House :

        we pass pointer of Person -> Home

        and pointer of Home -> Person.

    but the issue in CPP that we get is that if a class is not yet defined we cannot use them ..

    so we will have to DECLARE the class. We can implement it anywhere below.


*/

class Home
{
public:
    Home(string address_) : address(address_) {}
    ~Home()
    {
        cout << "~Home of address: " << address << endl;
    }
    void AddPerson(Person *person)
    {
        persons.push_back(person);
    }

private:
    vector<Person *> persons;
    string address;
};
// Object 1
class Person
{
public:
    Person(string person_name_) : person_name(person_name_) {}
    void Breathe();
    void Walk();
    ~Person()
    {
        cout << "~Person " << person_name << endl;
    }
    void addHome(Home *home)
    {
        homes.push_back(home);
    }
    void getHomes()
    {
        for (auto a : homes)
            cout << a << ' ';
        cout << endl;
    }

private:
    vector<Home *> homes;
    string person_name;
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Home home("Delhi");
    Home home2("Banglore");
    Home home3("Mumbai");
    Person *person1 = new Person("A");
    Person *person2 = new Person("B");
    person1->addHome(&home);
    person2->addHome(&home2);
    person1->getHomes();
    person2->getHomes();

    return 0;
}
