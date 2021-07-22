#include <iostream>

using namespace std; 

const int DOLLAR_VALUE = 100, QUARTER_VALUE = 25, DIME_VALUE = 10, NICKEL_VALUE = 5, PENNY_VALUE = 1; 

int main() {

	int quarters, dimes, nickels, pennies;
	int quarterTotal, dimesTotal, nickelsTotal, penniesTotal; 
	int currentCents, totalDollars, totalCents; 

	cout << "Please enter number of coins: " << endl;
	
	cout << "# of quarters: ";
	cin >> quarters;
	cout << "# of dimes: ";
	cin >> dimes; 
	cout << "# of nickles: ";
	cin >> nickels;
	cout << "# of pennies: ";
	cin >> pennies; 

	quarterTotal = quarters * QUARTER_VALUE;
	dimesTotal = dimes * DIME_VALUE;
	nickelsTotal = nickels * NICKEL_VALUE; 
	penniesTotal = pennies * PENNY_VALUE; 
	
	currentCents = quarterTotal + dimesTotal + nickelsTotal + penniesTotal;
	totalDollars = currentCents / DOLLAR_VALUE;
	totalCents = currentCents % DOLLAR_VALUE; 

	 cout << "The total is " << totalDollars << " and " << totalCents << " cents"; 
	
	
	return 0;
}