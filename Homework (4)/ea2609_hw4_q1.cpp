#include <iostream>

using namespace std;
int main() {

	int input, counter;
	int evenCount = 0;
	int stop;

	cout << "Version 1" << endl;

	cout << "Please enter a positive integer: ";
	cin >> input;
	input *= 2; 

		while (input != evenCount) {
			evenCount += 2;
			cout << evenCount << endl;
	}

	cout << "Version 2" << endl;

	cout << "Please enter a positive integer: ";
	cin >> input;
	input *= 2;

	for(evenCount = 2; evenCount <= input; evenCount += 2) {
		cout << evenCount << endl; 
	}


	return 0;
}