#include <bits/stdc++.h>
#include <chrono>
using namespace std;
/*
    JOIN Method is used to stop the function so that thread can complete its task,

    else :
        if the function completed its execution and exited before the thread completes its execution, then OS will

        kill the thread and thread's process will remaing uncomplete.
*/
void work()
{
    std::cout << "[worker] started on : " << std::this_thread::get_id() << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    std::cout << "[woker] done " << "\n";
}
int main()
{
    std::thread t(work);
    std::cout << "joinable before join? " << std::boolalpha << t.joinable() << "\n";
    t.join();
    std::cout << "joinable after join? " << std::boolalpha << t.joinable() << "\n";
    std::cout << "[main] finished safely" << "\n";
    return 0;
}