#include "Budget.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <tuple>
#include <string>
#include <fstream>

using namespace std;

int main() {
    //necesarry variables
     Budget* months = new Budget[12];
     int monthNum;
     double amount;

     string item;
     char input;
    
      //start of program
     cout << "Welcome to the monthly budget manager!" << endl;
     cout << "Select a month to start budgeting! (1-12)" << endl;
     cin >> monthNum;
     if (monthNum < 0 || monthNum>12) {
         cout << "Invalid month - month set to January (1) by defualt" << endl;
         monthNum = 1;
     }
     if(!(monthNum < 0 || monthNum > 12)){
         monthNum--;
         cout << "Enter total budget for this month:";
         cin >> amount;
         months[monthNum].setTotal(amount);
     }
     for(;;){
         cout << "Enter input for action" << endl;
         cout << "A - Add purchase\nT - Get remaining total for month\nC - Change month\nP - Print purchases\nE - Erase purcahses for month and reset remaining budget\nQ - Quit" << endl;
         cin >> input;
         switch (input)
         {
         case 'A':
             cout << "Enter name of item: ";
             cin.ignore();
             cin >> item;
             cout << "Enter cost of item: $";
             cin >> amount;
             months[monthNum].addPurchase(item, amount);
             break;
         case 'T':
             cout << "Total spending money left: $" << months[monthNum].getRemaining() << "\n" << endl;
             break;
         case 'C':
             cout << "Enter new number for month (1-12)" << endl;
             cin >> monthNum;
             if (monthNum < 0 || monthNum > 12) {
                 cout << "Invalid month - month set to January (1) by defualt" << endl;
                 monthNum = 1;
             }
             else if(months[--monthNum].getTotal() < 0){
                 cout << "Enter total budget for this month:";
                 cin >> amount;
                 months[monthNum].setTotal(amount);
             }
             break;
         case 'P':
             months[monthNum].printItems();
             break;
         case 'E':
             months[monthNum].clearPurchases();
             cout << "Purchases have been cleared for month: " << monthNum + 1 << "\nRemaining budget has been set to: $" << months[monthNum].getRemaining();
             break;
         case 'Q':
             delete [] months;
             return EXIT_SUCCESS;
         default:
             cout << "Input not recognized, be to use correct characters" << endl;
             break;
         }

     }    
     delete [] months;
    return EXIT_SUCCESS;
}