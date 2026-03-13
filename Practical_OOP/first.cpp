#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
    CONSTRUCTORS AND DESTRUCTORS :

        constructors are called to initialize some values and destructors are called when objects go out of scope

        and are deleted..

        we need to create our own custom destructors because the default ones only clean the pointers and variables..

        to clean the memory we need to define it explicitely in destructors..

        CPP MEMBER INITIALISER LIST ..

        in constructors we can assign variables values that are passed to constructor like this :

        class_name(variables passed) : variable_which_needs_value(value_to_be_assigned), another_variable_to_be_assigned_value(value_that_we_assign) {}

        declare variables in the order that you are going to use them because inside constructor the variables

        are assigned value not in the order that you write inside the constructor but the order in which you

        have declared or created in class..

        eg : if you have 3 variables a,b,mini and you want to assign mini as min(a,b) in the constructor

        you need to declare mini after a,b else it will be allocated some garbage value..

        https://maang.in/playlists/Live-Session-3676?resourceUrl=cs95-cp543-pl3676-rs8810&returnUrl=%5B%22%2Fcourses%2FLow-level-Design-Live-Bootcamp-95%3Ftab%3Dchapters%22%5D

        48:32

        MEMORY LEAKAGE : when you keep creating objects and do not delete them using destructor they keep getting

        stored which leads to memory leakage.





*/
// class A
// {

// public:
//     A(int a)
//     {
//         a_ = a;
//     }
//     int GetA()
//     {
//         return a_;
//     }
//     ~A()
//     {
//         cout << "THIS IS WHERE DESTRUCTOR IS CALLED.." << endl;
//     }

// private:
//     int a_;
// };
// // INHERITENCE..
// class A
// {
// public:
//     A()
//     {
//         cout << "CONSTRUCTOR OF A IS CALLED" << endl;
//     }
//     ~A()
//     {
//         cout << "DESTRUCTOR OF A IS CALLED" << endl;
//     }
// };
// class B : public A
// {
// public:
//     B()
//     {
//         cout << "CONSTRUCTOR OF B IS CALLED" << endl;
//     }
//     ~B()
//     {
//         cout << "DESTRUCTOR OF B IS CALLED" << endl;
//     }
// };
// class A
// {
// public:
//     int public_a = 10;

// private:
//     int private_a = 5;

// protected:
//     int protected_a = 2;
// };
// class B : public A
// {
// public:
//     void fun()
//     {
//         cout << protected_a << endl;
//     }
// };

// TYPES OF INHERITENCE :
// if you inherit using public then all the data types of parent that are accessible, their type doesnt change..
// EG :
// class A
// {
// public:
//     int public_int_a;

// private:
//     int private_int_a;

// protected:
//     int protected_int_a;
// };
// class B : public A
// {
//     // here the data types of parent that are accesssible still remain the same..
//     // public && protected are still the same..
// };
// class B : private A
// {
//     // here all the data types of parent that are accesssible become private..
//     // public && protected variables -> private..
// };
// class B : protected A
// {
//     // here again all the data types that are accessible become protected..
//     // public && protected variables -> protected..
// };
// when we create object of child / derived class how do we initialise the values of parent / base class..
// we can do that using constructor of parent called in constructor of child class..
// EG :
// class A
// {
// public:
//     int public_int_a;
//     A(int public_a, int private_a, int protected_a) : public_int_a(public_a), private_int_a(private_a), protected_int_a(protected_a)
//     {
//         cout << "CONSTRUCTOR OF A IS CALLED.." << endl;
//     }

// private:
//     int private_int_a;

// protected:
//     int protected_int_a;
// };
// class B : public A
// {
// public:
//     B(int a, int b, int c) : A(a, b, c)
//     {
//         cout << "Constructor of B is called..." << endl;
//     }
// };
// class A
// {
// public:
//     A(int a) : public_int_a(a) {}
//     void fun()
//     {
//         cout << public_int_a << endl;
//     }
//     int public_int_a;
// };

//                                        POLYMORPHISM..

// the idea is to use a general function for all the chidren of a base / parent class instead of creating multiple
// functions for all the children..

class Animal
{
public:
    virtual void Sound()
    {
        cout << "No  Sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void Sound()
    {
        cout << "Bhow Bhow" << endl;
    }
};
class Cat : public Animal
{
public:
    void Sound()
    {
        cout << "Meow Meow Meow Meow " << endl;
    }
};
void PlaySound(Animal &animal)
{
    animal.Sound();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Dog dog;
    PlaySound(dog);
}
