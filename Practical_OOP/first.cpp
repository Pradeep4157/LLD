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





*/
class A
{

public:
    A(int a)
    {
        a_ = a;
    }
    int GetA()
    {
        return a_;
    }
    ~A()
    {
        cout << "THIS IS WHERE DESTRUCTOR IS CALLED.." << endl;
    }

private:
    int a_;
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        A a(3);
        cout << (a.GetA()) << endl;
    }

    cout << ("THIS IS THE LAST LINE IN MAIN..") << endl;
}
