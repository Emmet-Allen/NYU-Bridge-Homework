#include <iostream>

using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;


int main() {

	double realNumber, fractionalNumber;
	int roundingMethod, floorNumber, ceilingNumber, nonFractional, roundNumber;

	cout << "Please enter a Real number: " << endl;
	cin >> realNumber;

	cout << "Choose your rounding method: " << endl;
	cout << "1. Floor round" << endl;
	cout << "2. Ceiling round" << endl;
	cout << "3. Round to the nearest whole number" << endl;
	cin >> roundingMethod;

	nonFractional = (int)realNumber; 


	if (realNumber >= 0) {

		fractionalNumber = realNumber - nonFractional;

		if (fractionalNumber >= 0.5) {
			ceilingNumber = 0;
			ceilingNumber = nonFractional + 1;

			floorNumber = 0;
			floorNumber = nonFractional;

			roundNumber = ceilingNumber;
		}

		else if (fractionalNumber < 0.5) {
			ceilingNumber = 0;
			ceilingNumber = nonFractional + 1;

			floorNumber = 0;
			floorNumber = nonFractional;
			roundNumber = floorNumber;
		}
	}

	else{
		// Multiply by -1 to get non-negative value
		fractionalNumber =  (realNumber - nonFractional) * -1;

		if (fractionalNumber >= 0.5) {
			ceilingNumber = 0;
			ceilingNumber = nonFractional;

			floorNumber = 0;
			floorNumber = nonFractional + (-1);
			roundNumber = floorNumber;
		}

		else if (fractionalNumber < 0.5) {
			ceilingNumber = 0;
			ceilingNumber = nonFractional;

			floorNumber = 0;
			floorNumber = nonFractional + (-1);
			roundNumber = ceilingNumber;
		}
	}

	switch (roundingMethod) {
	case(FLOOR_ROUND):
		cout << floorNumber << endl;
		break;
	case(CEILING_ROUND):
		cout << ceilingNumber << endl;
		break;
	case(ROUND):
		cout << roundNumber << endl;
		break;
	}

	return 0; 
}