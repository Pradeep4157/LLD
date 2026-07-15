#include <bits/stdc++.h>
#include <chrono>
using namespace std;
/*

*/

int main()
{
    auto msg = std::make_shared<std::string>("Hello World");
    std::thread t([sp = msg]()
                  {
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        std::cout << "[worker] msg : " << sp << "\n"; });
    // t.detach();
    msg.reset();
    std::cout << "[main] exit" << "\n";
    if (t.joinable())
    {
        std::cout << "Worker thread is still running and not yet completed." << "\n";
    }

    return 0;
}