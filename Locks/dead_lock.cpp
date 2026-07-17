#include <bits/stdc++.h>
#include <chrono>
using namespace std;
/*
`   Here function f has initially taken m1 lock and g function has taken m2 lock, and then f is waiting for m2 lock

    to complete, whereas g function which has this lock, is waiting for m1 lock to complete leading to deadlock.
*/
std::mutex m1, m2;
void f()
{
    // acquiring m1 lock..
    std::lock_guard<std::mutex> g1(m1);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::lock_guard<std::mutex> g2(m2);
    std::cout << "Function F is completed" << std::endl;
}
void g()
{
    std::lock_guard<std::mutex> g2(m2);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::lock_guard<std::mutex> g1(m1);
    std::cout << "Function G is completed" << "\n";
}
int main()
{
    std::thread t1(f), t2(g);
    t1.join();
    t2.join();
    std::cout << "[Main] completed" << "\n";
    return 0;
}