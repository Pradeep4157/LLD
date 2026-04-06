#include <bits/stdc++.h>
#define int long long
using namespace std;
/*

    FACTORY METHOD :

    here which class is going to implement the request is decided at runtime.

    Here an Interface is defined and the type of subclass object that is going to be created is decided by Factory class.

    1:40:07

*/
class ShapeInterface
{
public:
    virtual void draw() = 0;
};
class Square : public ShapeInterface
{
public:
    void draw() override
    {
        cout << "SQUARE" << endl;
    }
};
class Circle : public ShapeInterface
{
public:
    void draw() override
    {
        cout << "CIRCLE" << endl;
    }
};
class ShapeFactory
{
public:
    ShapeInterface *GetShape(string shape)
    {
        if (shape == "square")
        {
            return new Square();
        }
        if (shape == "circle")
        {
            return new Circle();
        }
        else
        {
            return new Circle();
        }
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string type;
    cin >> type;
    ShapeFactory finder;
    ShapeInterface *curr = finder.GetShape(type);
    curr->draw();
    return 0;
}
