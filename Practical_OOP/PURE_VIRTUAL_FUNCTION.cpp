#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
    PURE VIRTUAL  FUNCTIONS :

    so objects of these classes cannot be created,

    they are meant to be overriden by derived classes,

    if you create object of these classes, you will get

    compilation error.


    you can do reference binding though because

    it allows the virtual  functions to be executed by child

    classes


    you cannot do object slicing because that  does not

    allow child classes function execution in case of

    pure virtual  function..

    SOME TERMS RELATED TO THIS CONCEPT :

    1) ABSTRACT BASE CLASS : if you define some virtual function

    in a class, that is called abstract base class.

    2) INTERFACE CLASS : if all the functions in the class

    are virtual, then it is called interface class.








*/
// class Base
// {
// public:
//     virtual void A() = 0;
//     void B()
//     {
//         cout << "B function of Base is called" << endl;
//     }
//     void C()
//     {
//         cout << "C function of Base is called" << endl;
//     }
// };
// class Derived : public Base
// {
// public:
//     void A()
//     {
//         cout << "A function of derived is called" << endl;
//     }
//     void E()
//     {
//         cout << "E function of derived is called" << endl;
//     }
//     void F()
//     {
//         cout << "F function of derived is called" << endl;
//     }
// };

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     // Base B;  // this will give compilation error.
//     Derived D;
//     Base &b = D; // this is allowed since we can execute using child class..

//     return 0;
// }

/*
    USE CASE OF VIRTUAL FUNCTION AND RUNTIME POLYMORPHISM

    AND REFERENCE BINDING..

*/

class Database
{
public:
    virtual void write() = 0;
    virtual void read() = 0;
    virtual void query() = 0;
};
class MySql : public Database
{
public:
    void write()
    {
    }
    void read()
    {
    }
    void query()
    {
    }
};
class NoSql : public Database
{
public:
    void write()
    {
    }
    void read()
    {
    }
    void query()
    {
    }
};

void ReadFromDatabase(Database &database)
{
    return;
}

signed main()
{
    MySql mysql;
    NoSql nosql;
    if (/* some condition.. */)
    {
        ReadFromDatabase(mysql);
    }
    else if (/* some other condition..*/)
    {
        ReadFromDatabase(nosql);
    }
    else
    {
    }
}