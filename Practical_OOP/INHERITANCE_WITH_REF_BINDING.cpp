#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
    INHERITANCE AND REF BINDING :

    HERE THE DERIVED CLASS IS TAKING SOME FUNCTIONALITIES

    FROM THE BASE CLASS WHICH ARE VIRTUAL  AND IMPLEMENTING

    ITS OWN VERSION..

    NOW IN REF BINDING :

    when we create a ref of some parent object with some child

    object like Base &b = Derived d;


    here b is a ref of Derived D class but we can access only

    the functionalities that are present in Base / parent class but

    incase if any functions are virtual in base class and since

    this is a ref of derived class at runtime it will execute

    the functionality present in derived class instead of Base class.


*/
class Base
{
public:
    virtual void A()
    {
        cout << "A function of Base is called " << endl;
    }
    void B()
    {
        cout << "B function of Base is called" << endl;
    }
    void C()
    {
        cout << "C function of Base is called" << endl;
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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Derived D;
    Base &B = D;
    B.A();
    D.A();
    return 0;
}
