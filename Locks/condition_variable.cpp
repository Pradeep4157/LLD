#include <bits/stdc++.h>
#include <chrono>
using namespace std;
/*

*/
bool done = false;
std::queue<int> q;
std::mutex mtx;
std::condition_variable cv;
void producer()
{
    for (int i = 1; i <= 5; i++)
    {
        {
            std::lock_guard<std::mutex> lk(mtx);
            q.push(i);
            std::cout << "Produced: " << i << "\n";
        }
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    {
        std::lock_guard<std::mutex> lk(mtx);
        done = true;
    }
    cv.notify_all();
}
int main()
{

    return 0;
}