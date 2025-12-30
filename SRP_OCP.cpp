#include <bits/stdc++.h>
#define int long long
using namespace std;
/*


    HERE IN THIS PART WE WILL REMOVE THE IF ELSE THINGS BY CREATING

    A INOTIFIER CLASS AND WHATEVER THE TYPES ARE , THEY ARE GOING TO

    EXTEND THE BASE INOTIFIER CLASS.


    IN THIS CODE SINGLE RESPONSIBILITY AND OPEN CLOSED PRINCIPLE IS FOLLOWED.

*/
class User
{
public:
    string number;
    string email;
    string name;

    User(string name, string number, string email)
    {
        this->number = number;
        this->email = email;
        this->name = name;
    }
};

struct INotifier
{
    // we define a virtual function that is going to be implemented by its children class
    virtual void send(User &user, const string &message) = 0;
};

class EmailSender : public INotifier
{
public:
    void send(User &user, const string &message) override
    {
        cout << "THIS IS THE MESSAGE : " << message << " , THAT SHOULD BE SENT TO THIS EMAIL ADDRESS : " << user.email << endl;
    }
};

class SMSSender : public INotifier
{
public:
    void send(User &user, const string &message) override
    {
        cout << "THIS IS THE MESSAGE : " << message << " , THAT SHOULD BE SEND TO THIS NUMBER : " << user.number << endl;
    }
};

class NotificationService
{
public:
    void sendViaChannel(INotifier &notifier, User &user, const string &message)
    {
        notifier.send(user, message);
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    User alice("alice", "123456789", "alice@gmail.com");
    EmailSender emailSender;
    SMSSender smsSender;
    NotificationService notifier;
    notifier.sendViaChannel(emailSender, alice, "WELCOME BSDK");

    return 0;
}
