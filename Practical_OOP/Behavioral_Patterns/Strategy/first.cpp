#include <bits/stdc++.h>
#define int long long
using namespace std;
/*

    STRATEGY :

        Multiple implementations of some algorithm ..

        use whichever you want..
*/
class PaymentStrategy
{
public:
    virtual void pay(double amount) = 0;
};
class CardPayment : public PaymentStrategy
{
public:
    void pay(double amount) override
    {
        cout << amount << " PAID THROUGH CARD" << endl;
    }
};
class UPIPayment : public PaymentStrategy
{
public:
    void pay(double amount) override
    {
        cout << amount << " PAID THROUGH UPI" << endl;
    }
};
class ShoppingCart
{
    PaymentStrategy *service;

public:
    void setPaymentStartegy(PaymentStrategy *service_)
    {
        service = service_;
    }
    void checkout(double amount)
    {
        if (service == nullptr)
        {
            cout << "NO PAYMENT METHOD DEFINED" << endl;
        }
        else
        {
            service->pay(amount);
        }
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    PaymentStrategy *curr = new UPIPayment();
    ShoppingCart *cart = new ShoppingCart();
    cart->setPaymentStartegy(curr);
    cart->checkout(100);
    return 0;
}
