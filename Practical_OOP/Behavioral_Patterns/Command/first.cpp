#include <bits/stdc++.h>
#define int long long
using namespace std;
/*

    COMMAND:

    Here we wrap actions into objects and execute them on some event.

*/

class Command
{
public:
    virtual void execute() = 0;
};
class Light
{
public:
    void on()
    {
        cout << "LIGHT IS ON" << endl;
    }
    void off()
    {
        cout << "LIGHT IS OFF" << endl;
    }
};
class LightOnCommand : public Command
{
private:
    Light *light;

public:
    LightOnCommand(Light *light_) : light(light_) {}
    void execute()
    {
        light->on();
    }
};
class LightOffCommand : public Command
{
private:
    Light *light;

public:
    LightOffCommand(Light *light_) : light(light_) {}
    void execute()
    {
        light->off();
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Command *firstCommand = new LightOffCommand(new Light());
    firstCommand->execute();

    return 0;
}
