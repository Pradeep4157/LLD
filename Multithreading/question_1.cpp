#include <bits/stdc++.h>
#include <chrono>
#include <condition_variable>
using namespace std;
/*

*/
int service_from_name(string &name)
{
    long long h = 0;
    long long mod = 1000003;
    for (char c : name)
    {
        unsigned char curr = (unsigned char)(tolower(c));
        h = (h * 131 + curr) % mod;
    }
    return 10 + (int)(h % 61);
}

struct Person
{
    int id;
    char party; // 'D' or 'R'
    string name;
    int arrival;
    int service; // amount of time this nigga is gonna be inside bathroom
};

int oldest_arrival(const vector<Person> &v)
{
    if (v.empty())
        return INT_MAX;
    int earliest_arrival_time = INT_MAX;
    for (auto &a : v)
    {
        earliest_arrival_time = min(earliest_arrival_time, a.arrival);
    }
    return earliest_arrival_time;
}

int main()
{

    return 0;
}