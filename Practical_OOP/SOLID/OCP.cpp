#include <bits/stdc++.h>
#define int long long
using namespace std;
/*

    OCP:

    you should be able to extend the logic without modifying the prev one ..

    maybe by adding more classes.


    55:50


*/
class StringFunction
{
public:
    virtual string Edit(string s1, string s2) = 0;
};
class AppendFunction : public StringFunction
{
public:
    string Edit(string str1, string str2) override
    {
        return str1 + str2;
    }
};
class ReverseAppendFunction : public StringFunction
{
public:
    string Edit(string str1, string str2) override
    {
        return str2 + str1;
    }
};
class TextEditor
{
public:
    string format(string str1, string str2, StringFunction &func)
    {
        return func.Edit(str1, str2);
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    AppendFunction first;
    TextEditor text;
    cout << text.format(s1, s2, first) << endl;
    return 0;
}
