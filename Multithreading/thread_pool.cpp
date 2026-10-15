#include <bits/stdc++.h>
using namespace std;
/*




*/

class ThreadPool
{
public:
    // We write explicit before constructor so that no code can create ThreadPool using Implicit Converstion,
    // that is they need to create Object of threadPool explicitely.
    explicit ThreadPool(std::size_t n = std::thread::hardware_concurrency()) : stop_(false)
    {
        // if i dont get any threads, then i manually set the number of threads to 1.
        if (!n)
            n = 1;
        // here it is reserved with n size, but when you do workers_.size(), it will return the true size(no of elements)
        // existing in the workers_ array.
        workers_.reserve(n);
        for (std::size_t i = 0; i < n; i++)
        {
            workers_.emplace_back([this]
                                  {
                                        for (;;)
                                        {
                                          std::function<void()> task;
                                          {
                                              // here i will wait till it acquires shared mutex lock..
                                              std::unique_lock<std::mutex> lk(m_);
                                              // now we have shared mutex lock..
                                              cv_.wait(lk, [this]
                                                       { return stop_ || !q.empty(); });
                                              // once all the tasks have been finished we quit this infinite for loop..
                                              if (stop_ && q.empty())
                                                  return;
                                              // else this worker takes the front task..
                                              task = std::move(q.front());
                                              q_.pop();
                                          }
                                          // now that we exited from this scope the shared mutex lock will automatically get freed..
                                          // we add this try catch,  in case some excpetion escapes task(), then the infinite for loop
                                          // will end =>  thread dying.
                                          try
                                          {
                                              task();
                                          }
                                          catch (...)
                                          {
                                          }
                                      } });
        }
    }
    template <class F, class... A>
    void enqueue(F &&f, A &&...a)
    {
        (void)submit(std)
    }

private:
    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> q_;
    std::mutex m_;
    std::condition_variable cv_;
    bool stop_;
};

int add(int a, int b)
{
    return a + b;
}
int main()
{

    ThreadPool pool(4);
}