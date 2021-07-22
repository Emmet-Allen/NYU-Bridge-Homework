#include <iostream>

using namespace std; 

const int DOLLAR_VALUE = 100, QUARTERS_VALUE = 25, DIMES_VALUE = 10, NICKEL_VALUE = 5, PENNIE_VALUE = 1; 

int main() {

	int dollars, cents; 
	int quaters, dimes, nickels, pennies; 
	int quatersRemainder, dimesRemainder, nickelsRemainder, penniesRemainder; 
	int totalCents;

	cout << "Please enter your amount in the format of dollars and cents separated by a space: ";
		cin >> dollars >> cents;

		cout << dollars << " dollars and " << cents << " cents are: " << endl;

		totalCents = (dollars * DOLLAR_VALUE) + cents;

		quaters = totalCents / QUARTERS_VALUE;
		quatersRemainder = totalCents % QUARTERS_VALUE; 

		dimes = quatersRemainder / DIMES_VALUE;
		dimesRemainder = quatersRemainder % DIMES_VALUE;

		nickels = dimesRemainder / NICKEL_VALUE;
		nickelsRemainder = dimesRemainder % NICKEL_VALUE;

		pennies = nickelsRemainder; 
		

		cout << quaters << " quarters, " << dimes << " dimes, " << nickels << " nickels, and ";
		cout << pennies << " pennies";

return 0;
}