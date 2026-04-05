#include <bits/stdc++.h>
#define int long long
using namespace std;
/*


    ISP :

    clients / child classes shouldnt be forced to implement the methods that they dont use..

    like all the function that are being used in the base class should be such that it can also be implmented in the child

    class..

    like if there base class of ShapeInterface and it has 2 function volume and area..

    shapes like sphere, cube etc can inherit this but rect / square cannot implement this because they dont have any concept of

    volume in them..




*/

class ShapeInterface
{
public:
    virtual double volume() = 0;
    virtual double area() = 0;
};
class Sphere : public ShapeInterface
{
public:
    Sphere(double radius_) : r(radius_) {};
    double volume()
    {
        return 3.14 * r * r * r * 4 / 3;
    }
    double area()
    {
        return 4 * 3.14 * r * r;
    }

private:
    double r;
};
// class Square : public ShapeInterface
// {
// public:
//     Square(double length) : len(length) {};
//     double area()
//     {
//         return len * len;
//     }
//     // no concept of volume so we will get error.. and voilates interface seg principle..
// private:
//     double len;
// };
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
