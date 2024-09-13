#include "Budget.h"
#include <string>
#include <vector>
#include <tuple>
#include <iostream>


double Budget::addPurchase(std::string item, double cost) {
    purchases.push_back(make_tuple(item, cost));
    budgetRemaining -= cost;
    std::cout << "After purchase, total left this month is: $" << budgetRemaining << std::endl;
    return cost;
}

Budget::Budget() {

    totalBudget = -1;
    budgetRemaining = -1;
}

void Budget::printItems() {
    if (purchases.size() == 0) {
        std::cout << "There are no purchases for this month." << std::endl;
        return;
    }
    for (int i = 0; i < purchases.size(); i++) {
        std::cout << "Purchase #" << i + 1 << " " << std::get<0>(purchases[i]) << ", " << std::get<1>(purchases[i]) << std::endl;
    }
    std::cout << "\n";
}
double Budget::getTotal() { return totalBudget; }

void Budget::setTotal(double amount) {
    totalBudget = amount;
    budgetRemaining = totalBudget;
 
    return;
}

double Budget::getRemaining() { return budgetRemaining; }

void Budget::clearPurchases() {
    purchases.clear();
    budgetRemaining = totalBudget;
}