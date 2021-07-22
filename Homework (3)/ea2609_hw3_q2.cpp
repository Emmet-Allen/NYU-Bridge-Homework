#include <iostream>
#include <string>

using namespace std;

int main() {
	string studentName;
	int graduationYear, currentYear, collegeStatus;

	cout << "Please enter your name: ";
	cin >> studentName;
	cout << "Please enter your graduation year: ";
	cin >> graduationYear;
	cout << "Please enter current year: ";
	cin >> currentYear;


	if (graduationYear > currentYear) {
		collegeStatus = graduationYear - currentYear;
		switch (collegeStatus) {
		case 4: cout << studentName << ", " << "you are a Freshman";
			break;
		case 3: cout << studentName << ", " << "you are a Sophomore";
			break;
		case 2: cout << studentName << ", " << "you are a Junior";
			break;
		case 1: cout << studentName << ", " << "you are a Senior";
			break;
		default: cout << studentName << ", " << "you are not in college yet";
			break;
		}
	}
	else {
		cout << studentName << ", " << "you graduated";
	}


	return 0;
}