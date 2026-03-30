#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
    COMPOSITION :

        An Object1 has another object2 inside it ..

        This Object2 only belong to Object1.

        Object2 is not aware of Object1, but Object 1 is.

        It is somewhat similar relationship like human and heart.

        Object1 can have other smaller members objects like Object2.

        when Object1 gets deleted Object2 also gets deleted.

        member's parameterized constructor should be called in the constructor of Base class.





20:24



*/
class Derived
{
public:
    void solve() {}
    ~Derived()
    {
        cout << "~ Derived " << endl;
    }
};
class Heart
{
public:
    Heart(string name) : person_name(name) {}
    void Beats();
    ~Heart()
    {
        cout << "~Heart" << " : " << person_name << endl;
    }

private:
    string person_name;
    Derived deri;
};
// Object 1
class Human
{
public:
    Human() : heart_("Pradeep") {}
    void Breathe();
    void Walk();
    ~Human()
    {
        cout << "~Human" << endl;
    }

private:
    // Object 2
    Heart heart_; // Composition
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Human h;
    return 0;
}
