#include <bits/stdc++.h>
#include <chrono>
using namespace std;
/*
    Mutex locks are used when we want to avoid race conditions in critical sections so that we avoid multiple

    threads updating that critical section at same time..
*/
std::mutex m;
int counter = 0;
void increment()
{
    for (int i = 1; i <= 1000; i++)
    {
        // another way : std::lock_guard<std::mutex> lock(m) , this starts the lock here only when this object is created
        // gets destryed when it goes out of scope.
        m.lock();
        counter++;
        m.unlock();
    }
}
int main()
{
    std::thread t1(increment), t2(increment);
    t1.join();
    t2.join();
    std::cout << "This is value of counter after all the updates : " << counter << "\n";
    return 0;
}