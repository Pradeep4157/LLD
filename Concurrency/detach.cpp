#include <bits/stdc++.h>
#include <chrono>
using namespace std;
/*
    Here detach is method that is used for parallel execution.
    But the risk is that function will complete and OS will delete this thread without the thread completing its
    execution because it declares it as zombie process with no parent.
*/

int main()
{
    std::thread t([]
                  {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "[bg] background task finished" << "\n"; });
    if (t.joinable())
        t.detach();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> jitter(0, 250);
    int ms = jitter(gen);
    std::cout << "Main exiting in : " << ms << "ms\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    std::cout << "Main exited now" << "\n";
    return 0;
}