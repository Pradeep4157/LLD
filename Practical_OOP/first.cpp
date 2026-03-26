#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
    CONSTRUCTORS AND DESTRUCTORS :

        https://maang.in/playlists/Live-Session-3676?resourceUrl=cs95-cp543-pl3676-rs8810&returnUrl=%5B%22%2Fcourses%2FLow-level-Design-Live-Bootcamp-95%3Ftab%3Dchapters%22%5D

    LLD SESSION 3 : 01:37:55

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

// class Animal
// {
// public:
//     virtual void Sound()
//     {
//         cout << "No  Sound" << endl;
//     }
// };

// class Dog : public Animal
// {
// public:
//     void Sound()
//     {
//         cout << "Bhow Bhow" << endl;
//     }
// };
// class Cat : public Animal
// {
// public:
//     void Sound()
//     {
//         cout << "Meow Meow Meow Meow " << endl;
//     }
// };
// void PlaySound(Animal &animal)
// {
//     animal.Sound();
// }
// class Base
// {
// public:
//     Base(int a) : a_(a)
//     {
//         cout << "BASE CLASS CALLED" << endl;
//     }
//     int a_;
// };
// class Derived : public Base
// {
// public:
//     Derived(int a, int b) : b_(b), Base(a)
//     {
//         cout << "DERIVED CLASS CALLED" << endl;
//     }
//     int b_;
//     void print()
//     {
//         cout << a_ << " " << b_ << endl;
//     }
// };
// void solve()
// {
//     // reference..
//     int a = 10;
//     int *ptr;
//     // points to the same memory where a is allocated space..
//     int &b = a;
//     cout << a << " " << b << " " << *ptr << endl;
//     // so if i change anyone both will get changed..
//     b = 15;
//     cout << a << " " << b << " " << *ptr << endl;
//     // pointer : is used to point to the address of a variable and we can use it to change and print the
//     // variable by dereferencing it..

//     *ptr = 20;
//     cout << a << " " << b << " " << *ptr << endl;
// }
// class Animal
// {
// public:
//     void Sound()
//     {
//         cout << "No Sound" << endl;
//     }
// };
// class Cat : public Animal
// {
// public:
//     void Sound()
//     {
//         cout << "Meow Meow " << endl;
//     }
// };
// class Kitten : public Cat
// {
// public:
//     void Sound()
//     {
//         cout << "Small Meow Meow Meow Meow" << endl;
//     }
// };

//     // OVERRIDE : this means that the current function is supposed to override some parent virtual function..

// class Animal
// {
// public:
//     virtual void Sound()
//     {
//         cout << "No Sound" << endl;
//     }
// };
// class Cat : public Animal
// {
// public:
//     void Sound() override
//     {
//         cout << "Meow Meow " << endl;
//     }
// };
// class Kitten : public Cat
// {
// public:
//     void Sound()
//     {
//         cout << "Small Meow Meow Meow Meow" << endl;
//     }
// };
// void playSound(Animal &animal)
// {
//     animal.Sound();
// }

// // FINAL : this is used when we do not expect this function to be overridden by any children of this class.
// class Animal
// {
// public:
//     virtual void Sound()
//     {
//         cout << "No Sound" << endl;
//     }
// };
// class Cat : public Animal
// {
// public:
//     void Sound() final
//     {
//         cout << "Meow Meow " << endl;
//     }
// };
// class Kitten : public Cat
// {
// public:
//     void Sound()
//     {
//         cout << "Small Meow Meow Meow Meow" << endl;
//     }
// };

// POLYMORPHISM : when we use heap object allocation, objects stored on heap arent deleted automatically..
// even if we use destructors it is necessary to make it virtual otherwise only the parent class gets del and not
// the child classes.
// class Animal
// {
// public:
//     void Sound()
//     {
//         cout << "No Sound" << endl;
//     }
//     ~Animal()
//     {
//         cout << "DESTRUCTOR OF ANIMAL IS CALLED" << endl;
//     }
// };
// class Cat : public Animal
// {
// public:
//     void Sound()
//     {
//         cout << "Meow Meow " << endl;
//     }
//     ~Cat()
//     {
//         cout << "DESTRUCTOR OF CAT IS CALLED" << endl;
//     }
// };
// class Kitten : public Cat
// {
// public:
//     void Sound()
//     {
//         cout << "Small Meow Meow Meow Meow" << endl;
//     }
//     ~Kitten()
//     {
//         cout << "DESTRUCTOR OF KITTEN IS CALLED" << endl;
//     }
// };

// /*
//     OBJECT SLICING :

//         so when we create an object and copy content

//         from another object (it is necessary that the object from

//         which we are copying should be either equal or some derived object)

//         , then all the class information of that object till the level of this new object will

//         get copied in the new object.

// */
// class Base
// {
// public:
//     int x;
//     int y;
//     virtual void A()
//     {
//         cout << "A function of Base is called " << endl;
//     }
//     void B()
//     {
//         cout << "B is called " << endl;
//     }
//     void C()
//     {
//         cout << "C is called" << endl;
//     }
//     void get_x()
//     {
//         cout << "VALUE OF X IS : " << x << endl;
//     }
//     void get_y()
//     {
//         cout << "VALUE OF Y IS : " << y << endl;
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
    D.A();
    return 0;
}
