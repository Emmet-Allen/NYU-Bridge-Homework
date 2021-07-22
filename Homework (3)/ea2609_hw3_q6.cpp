#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const float PEAK_RATE = 0.40, OFF_PEAK_RATE = 0.25, WEEKEND_RATE = 0.15; 

int main() {
	
	int hours, minutes, callLength;
	float totalCost; 
	char colon;  // Stores colon for time input
	string day;

	cout << "What time of the day was the call made: ";
	cin >> hours >> colon >> minutes;
	cout << "What day of the week was the call made: ";
	cin >> day;
	cout << "How long was the call in minutes: ";
	cin >> callLength; 

	cout << endl; 
 	cout << fixed << setprecision(2);
	

		 if (day == "Sa" || day == "Su") {
		//Weekend Rate Calculation
		totalCost = callLength * WEEKEND_RATE;

		cout << "The total cost at a Weekend Rate of $" << WEEKEND_RATE << " is " << "$" << totalCost; 
	}

	else {
		//Peak Rate Calculation
		if  (hours >= 8 && hours < 18) {
			totalCost = callLength * PEAK_RATE;

			cout << "The total cost at a Peak Rate of $" << PEAK_RATE << " is " << "$" << totalCost;
		}
		//Off Peak Rate Calculations
		else if( hours == 18 && minutes != 0 ) {
			totalCost = callLength * OFF_PEAK_RATE;

			cout << "The total cost at an Off Peak Rate of $" << OFF_PEAK_RATE << " is " << "$" << totalCost;
		}
		else{
			totalCost = callLength * OFF_PEAK_RATE;

			cout << "The total cost at an Off Peak Rate of $" << OFF_PEAK_RATE << " is " << "$" << totalCost;

		}
	}

	return 0;
}