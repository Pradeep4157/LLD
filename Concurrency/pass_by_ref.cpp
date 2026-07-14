#include <bits/stdc++.h>
#include <chrono>
using namespace std;
/*
    in the lambda function we can [&], so that it takes value by ref.
*/

int main()
{
    int x = 10;
    std::thread t1([&]()
                   { x += 5; });
    std::thread t2([&]()
                   { x += 5; });
    x = 42;
    t1.join();
    t2.join();
    std::cout << "[main] final value of x = " << x << "\n";
    return 0;
}