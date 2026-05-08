#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
    ADAPTER :

    when the type of parameters or some input format change, then we create new class, call it adapter, do the changes and let the old code execute it with its required parameter format and types


*/
class OldPaymentService
{
public:
    void makePaymentInPaise(long paise)
    {
        cout << "OldPaymentService: paid " << paise << " paise" << endl;
    }
};
class PaymentProcessor
{
public:
    virtual void processPayment(double amount) = 0;
};
class OldPaymentAdapter : public PaymentProcessor
{
    OldPaymentService service;

public:
    OldPaymentAdapter(OldPaymentService service_) : service(service_) {}
    void processPayment(double amount) override
    {
        long paise = amount * 100;
        service.makePaymentInPaise(paise);
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    OldPaymentService service;
    PaymentProcessor *newProcessor = new OldPaymentAdapter(service);
    newProcessor->processPayment(98.56);
    return 0;
}
