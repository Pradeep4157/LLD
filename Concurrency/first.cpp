#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main()
{
    std::cout << "Main thread id : " << std::this_thread::get_id() << std::endl;
    unsigned hc = std::thread::hardware_concurrency();
    std::cout << "Hardware Concurrency is : " << hc << "\n";
    const int N = 4;
    std::vector<std::thread> threads;
    threads.reserve(N);
    for (int i = 0; i < N; i++)
    {
        threads.emplace_back([i]()
                             {
                                 std::this_thread::sleep_for(std::chrono::milliseconds(10 * (i + 1)));
                                 std::cout << "Worker #" << i << " thread id: " << std::this_thread::get_id() << "\n"; });
    }
    for (auto &t : threads)
    {
        t.join();
    }
    std::cout << "All workers joined" << "\n";
    return 0;
}