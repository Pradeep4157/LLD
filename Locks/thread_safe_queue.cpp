#include <bits/stdc++.h>
#include <chrono>
#include <condition_variable>
using namespace std;
/*

*/

class ThreadSafeQueue
{
private:
    std::queue<int> q_;
    std::mutex mu_;
    std::condition_variable cv_;

public:
    void push(int x)
    {
        {
            std::lock_guard<std::mutex> lk(mu_);
            q_.push(x);
        }
        cv_.notify_one();
    }
    int pop(int x)
    {
        std::unique_lock<std::mutex> lk(mu_);
        cv_.wait(lk, [this]
                 { return !q_.empty(); });
        int v = q_.front();
        q_.pop();
        return v;
    }
};
int main()
{

    return 0;
}