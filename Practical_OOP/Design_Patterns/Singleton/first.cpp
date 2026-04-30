#include <bits/stdc++.h>
#define int long long
using namespace std;
/*

    SINGLETON :

    These classes are created to have one instance of object and eveyone uses this instance of object only.

    This single instance is achieved by creating object inside the class and returning the pointer of the

    object to whoever asks for it.

    BEFORE C++ 11 we had to create object in class and return pointer to that obj, but now by writing static

    it will create only 1 instance of that object and store it in static storage.




*/
// OLD VERSION TO BE THREAD SAFE :
// class Singleton
// {
// private:
//     inline static Singleton *instance = nullptr;
//     Singleton() {}

// public:
//     static Singleton &getInstance()
//     {
//         if (instance == nullptr)
//         {
//             instance = new Singleton();
//         }
//         return *instance;
//     }
// };

class Singleton
{
private:
    Singleton() {} // this is to preven multiple instances of singleton class..

public:
    static Singleton &getInstance()
    {
        static Singleton instance;
        return instance;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
