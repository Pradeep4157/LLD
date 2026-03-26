#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
//     OBJECT SLICING :

//         so when we create an object and copy content

//         from another object (it is necessary that the object from

//         which we are copying should be either equal or some derived object)

//         , then all the class information of that object till the level of this new object will

//         get copied in the new object.

 */

class Base
{
public:
    int x;
    int y;
    virtual void A()
    {
        cout << "A function of Base is called " << endl;
    }
    void B()
    {
        cout << "B is called " << endl;
    }
    void C()
    {
        cout << "C is called" << endl;
    }
    void get_x()
    {
        cout << "VALUE OF X IS : " << x << endl;
    }
    void get_y()
    {
        cout << "VALUE OF Y IS : " << y << endl;
    }
};
class Derived : public Base
{
public:
    void A()
    {
        cout << "A function of derived is called" << endl;
    }
    void E()
    {
        cout << "E function of derived is called" << endl;
    }
    void F()
    {
        cout << "F function of derived is called" << endl;
    }
};