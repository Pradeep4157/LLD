#include <bits/stdc++.h>
using namespace std;
/*

    atomic is used to do  thread safe operations..



*/

std::atomic<int> counter(0);
void increment()
{
    for (int i = 0; i < 1000; i++)
    {
        counter++;
    }
}
int main()
{
    std::vector<std::thread> ts;
    for (int i = 0; i < 10; ++i)
    {
        ts.emplace_back(increment);
    }
    for (auto &a : ts)
    {
        a.join();
    }
    std::cout << "This is the final counter : " << counter.load() << "\n";
    return 0;
}