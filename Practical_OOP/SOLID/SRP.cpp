#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
    SRP:

    class should have only 1 responsibility.


    44:22






*/
class IndianIncome
{
public:
    IndianIncome(double avg_income_) : avg_income(avg_income_) {}
    double GetAverageTax()
    {
        return 0.0;
    }
    double GetAverageIncome() const
    {
        return 0.0;
    }

private:
    double avg_income;
};
class USIncome
{
public:
    USIncome(double avg_income_) : avg_income(avg_income_) {}
    double GetAverageTax()
    {
        return 0.0;
    }
    double GetAverageIncome() const
    {
        return 0.0;
    }

private:
    double avg_income;
};
class AverageIncomeTaxCalculator
{
public:
    double GetAverageIncomeTax(const IndianIncome &indian_income)
    {
        return indian_income.GetAverageIncome() / 15;
    }
    double GetAverageIncomeTax(const USIncome &us_income)
    {
        return us_income.GetAverageIncome() / 10;
    }
};
class AverageIncomePrinter
{
public:
    void PrintAverageIncome(const IndianIncome &india_income)
    {
        cout << india_income.GetAverageIncome() << endl;
    }
    void PrintAverageIncome(const USIncome &us_income)
    {
        cout << us_income.GetAverageIncome() << endl;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
