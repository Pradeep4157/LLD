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

// Object 1
class Person
{
public:
    Person(string person_name_) : person_name(person_name_) {}
    void Breathe();
    void Walk();
    ~Person()
    {
        cout << "~Human" << endl;
    }

private:
    string person_name;
};
class Home
{
public:
    Home(string address_) : address(address_) {}

private:
    string address;
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
