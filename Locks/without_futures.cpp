#include <bits/stdc++.h>
#include <chrono>
#include <condition_variable>
using namespace std;
/*

*/

int result = 0;
std::mutex m;
void compute()
{
    int r = 42 * 42;
    std::lock_guard<std::mutex> lg(m);
    result = r;
}
int main()
{
    std::thread t(compute);
    t.join();
    std::lock_guard<std::mutex> lg(m);
    std::cout << "Result: " << result << "\n";
    return 0;
}