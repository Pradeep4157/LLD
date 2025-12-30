#include <bits/stdc++.h>
#define int long long
using namespace std;

// ===================================================================================================

//     NOW IN THIS IMPLEMENTATION THINGS ARE TIGHTLY COUPLED, THERE IS GOING

//     TO BE SCALABILITY ISSUES, TESTING AND MAINTENANCE

//     SO WE ADD SOLID PRINCIPLES TO IT

// ====================================================================================================

class User
{

public:
    string name, email, number;
    User(string name, string email, string number)
    {
        this->name = name;
        this->email = email;
        this->number = number;
    }
};
class NotificationService
{
public:
    void sendNotification(const User &user, const string &message, const string &type)
    {
        if (type == "email")
        {
            cout << "Send this message : " << message << " to this email :" << user.email << endl;
        }
        else if (type == "sms")
        {
            cout << "Send this message : " << message << " to this number : " << user.number << endl;
        }
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    User alice("Alice", "alice@example.com", "123456789");
    NotificationService service;
    service.sendNotification(alice, "Welcome Alice!", "email");
    service.sendNotification(alice, "You have recieved the delivery! ", "sms");

    return 0;
}
