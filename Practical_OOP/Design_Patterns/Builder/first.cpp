#include <bits/stdc++.h>
#define int long long
using namespace std;
/*

    BUILDER :

    when a class has a lot of data members, and we dont alwasy want to assign

    all the data members with some values we cant use the usual assignment using

    the constructors..

    in these cases we use Builder pattern..

*/
class User
{
public:
    string name;
    string email;
    string phone;
    User(const string name_, const string email_, const string &phone_) : name(name_), email(email_), phone(phone_) {}
    class Builder
    {
    private:
        string name;
        string email;
        string phone;

    public:
        Builder &withName(const string &name_)
        {
            name = name_;
            return *this;
        }
        Builder &withEmail(const string &email_)
        {
            email = email_;
            return *this;
        }
        Builder &withPhone(const string &phone_)
        {
            phone = phone_;
            return *this;
        }
        User build() const
        {
            return User(name, email, phone);
        }
    };
    void print()
    {
        cout << "User Name is : " << name << endl;
        cout << "Phone Number is : " << phone << endl;
        cout << "Email Address is : " << email << endl;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    User u = User::Builder().withName("Pradeep").withPhone("1561651651651").build();
    u.print();

    return 0;
}
