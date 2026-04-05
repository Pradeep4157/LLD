#include <bits/stdc++.h>
#define int long long
using namespace std;
/*

    OCP :

    the derived class should be substitutable for their base classes and it shouldnt throw any error..






*/

class Rectangle
{
public:
    Rectangle(int length_, int width_) : length(length_), width(width_) {};
    int GetArea()
    {
        return (length * width);
    }
    virtual int GetPerimater()
    {
        return 0;
    }

protected:
    int length, width;
};
class Square : public Rectangle
{
public:
    Square(int length) : Rectangle(length, length) {}
    int GetPerimater()
    {
        return length + length;
    }
};
pair<int, int> GetRectangleInformation(Rectangle &rectangle)
{
    return {rectangle.GetArea(), rectangle.GetPerimater()};
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Square rectangle(3);
    pair<int, int> curr = GetRectangleInformation(rectangle);
    cout << curr.first << ":" << curr.second << endl;
    return 0;
}
