#include <bits/stdc++.h>
#define int long long
using namespace std;
/*

    OBSERVER :

        HERE THERE IS AN ARRAY OF OBSERVER OBJECTS WHICH ARE LIKE SUBSCRIBERS AND IN CASE SOME DATA COMES THEN ALL THESE

        OBSERVERSE ARE NOTIFIED..
*/
class Observer
{
public:
    virtual void update(string news) = 0;
};
class Subject
{
public:
    virtual void addObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyUsers() = 0;
};
class NewsAgency : public Subject
{
private:
    string news;
    set<Observer *> observers;

public:
    void setNews(string news_)
    {
        news = news_;
        notifyUsers();
    }
    void addObserver(Observer *observer) override
    {
        observers.insert(observer);
    }
    void removeObserver(Observer *observer) override
    {
        if (observers.count(observer))
        {
            observers.erase(observer);
        }
    }
    void notifyUsers()
    {
        for (auto observer : observers)
        {
            observer->update(news);
        }
    }
};
class NewsChannel : public Observer
{
private:
    string name;

public:
    NewsChannel(string name_)
    {
        name = name_;
    }
    void update(string news)
    {
        cout << "Channel " << name << " has recieved news : " << news << endl;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Observer *a = new NewsChannel("A NEWS CHANNEL");
    Observer *b = new NewsChannel("B NEWS CHANNEL");
    NewsAgency *newsAgency = new NewsAgency();
    newsAgency->addObserver(a);
    newsAgency->setNews("TODAY THIS RANDOM THING HAPPENED..");
    newsAgency->addObserver(b);
    // newsAgency->removeObserver(a);
    newsAgency->setNews("TODAY THIS 2ND RANDOM THING HAPPENED...");
    return 0;
}
