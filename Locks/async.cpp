#include <bits/stdc++.h>
#include <chrono>
#include <condition_variable>
using namespace std;
/*

*/

int compute()
{
    return 44;
}
int main()
{
    std::future<int> f = std::async(std::launch::async, compute);
    std::cout << f.get() << "\n";
    return 0;
}