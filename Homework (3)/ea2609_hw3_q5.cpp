#include <iostream>
#include <string>

using namespace std;

const float LBS_TO_KG = 0.453592, IN_TO_M = 0.0254; 


int main() {

	float bmi, weightKilos, heightMeters, weightPounds, heightInches, heightSquared;
	string Obese, Overweight, Normal, Underweight, weightStatus;

	cout << "Please enter weight (in pounds): ";
	cin >> weightPounds;
	cout << "Please enter height (in inches): ";
	cin >> heightInches; 

	weightKilos = weightPounds * LBS_TO_KG;
	heightMeters = heightInches * IN_TO_M;

	cout << weightKilos << endl;
	cout << heightMeters << endl;

	heightSquared = heightMeters * heightMeters;

	bmi = weightKilos / heightSquared;

	cout << bmi << endl; 

	weightStatus = "The weight status is: ";

	Obese = weightStatus + "Obese";
	Overweight = weightStatus + "Overweight";
	Normal = weightStatus + "Normal";
	Underweight = weightStatus + "Underweight";

	if (bmi > 30) {
		cout << Obese << endl;
	}
	else if (30 <= bmi || bmi >= 25) {
		cout << Overweight << endl;
	}
	else if (25 <= bmi || bmi >= 18.5) {
		cout << Normal << endl;
	}
	else{
		cout << Underweight << endl;
	}


	return 0;
}