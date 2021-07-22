#include <iostream>

const int HOUR_VALUE = 60, DAY_VALUE = 24; 

using namespace std; 
int main() {
	int johnDays, johnHours, johnMinutes;
	int billDays, billHours, billMinutes;

	int sumHours, sumMinutes; 
	int totalDays, totalHours, totalMinutes; 
	int additionalHours, additionalDays; 

	cout << "Please enter the number of days John has worked: ";
	cin >> johnDays; 
    cout << "Please enter the number of hours John has worked: ";
	cin >> johnHours;
	cout << "Please enter the number of minutes John has worked: ";
	cin >> johnMinutes;
	
	cout << endl; 

	cout << "Please enter the number of days Bill has worked: ";
	cin >> billDays;
	cout << "Please enter the number of hours Bill has worked: ";
	cin >> billHours;
	cout << "Please enter the number of minutes Bill has worked: ";
	cin >> billMinutes;

	sumMinutes = johnMinutes + billMinutes;
	totalMinutes = sumMinutes % HOUR_VALUE; 
	additionalHours = sumMinutes / HOUR_VALUE; 

	sumHours = johnHours + billHours + additionalHours;
	totalHours = sumHours % DAY_VALUE; 
	additionalDays = sumHours / DAY_VALUE; 

	totalDays = johnDays + billDays + additionalDays; 

	cout << endl; 

	cout << "The total time both of them worked together is: " << totalDays << " days, ";
	cout << totalHours << " hours and " << totalMinutes << " minutes" << endl; 




	return 0; 
}