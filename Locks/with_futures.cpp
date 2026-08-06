#include <bits/stdc++.h>
#include <chrono>
#include <condition_variable>
using namespace std;
/*

*/

void compute(std::promise<int> p)
{
    try
    {
        int r = 42;
        p.set_value(r);
    }
    catch (...)
    {
        p.set_exception(std::current_exception());
    }
}
int main()
{
    std::promise<int> p;
    std::future<int> f = p.get_future();
    // p.set_value(100);
    std::thread t(compute, std::move(p));
    int result = f.get();
    std::cout << "Result: " << result << "\n";
    t.join();
    return 0;
}