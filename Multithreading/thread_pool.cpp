#include <bits/stdc++.h>
using namespace std;
/*




*/

class ThreadPool
{
public:
    explicit ThreadPool(std::size_t n = std::thread::hardware_concurrency())
        : stop_(false)
    {
        if (!n)
            n = 1;
        workers_.reserve(n);
        for (std::size_t i = 0; i < n; i++)
        {
            workers_.emplace_back([this]
                                  {
                for(;;) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lk(m);
                        cv_.wait(lk, [this] { return stop_ || !q.empty();});
                    }
                } })
        }
    }
};
int main()
{

    return 0;
}