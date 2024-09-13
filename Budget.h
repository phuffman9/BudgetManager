#pragma once
#include <vector>
#include <tuple>
#include <string>
class Budget
{
public:
    Budget();
    double addPurchase(std::string item, double cost);
    void printItems();
    double getTotal();
    void setTotal(double amount);
    double getRemaining();
    void clearPurchases();

private:
    std::vector<std::tuple<std::string, double>> purchases;
    double totalBudget;
    double budgetRemaining;

};

