#include <bits/stdc++.h>
#include <chrono>
using namespace std;
/*
    Here to prevent deadlock we write lock(m1, m2) which locks m1, m2 and then we write lock_guard to unlock

    it once we get out of the function. But since it is already locked that's why we write adopt_lock which means

    that it is already locked, just take ownership to unlock it once it exits from here..
*/
std::mutex m1, m2;
int data_1 = 0, data_2 = 0;
void task(int i)
{
    std::lock(m1, m2);
    std::lock_guard<std::mutex> g1(m1, std::adopt_lock);
    std::lock_guard<std::mutex> g2(m2, std::adopt_lock);
    data_1 += i;
    data_2 += (i * 2);
    std::cout << i << " updated : (" << data_1 << " " << data_2 << ")" << "\n";
}
int main()
{
    vector<std::thread> ts;
    for (int i = 1; i <= 4; i++)
    {
        ts.emplace_back(task, i);
    }
    for (auto &t : ts)
        t.join();

    return 0;
}