#include <iostream>

using namespace std;

int main() {
	int firstNumber, secondNumber; 
	int totalSum, totalDifference, totalProduct, totalDiv, totalMod; 
	float totalDivision;

	cout << "Please enter two positive integers, seperated by a space: " << endl;
	cout << endl;
	cin >> firstNumber >> secondNumber; 
	
	totalSum = firstNumber + secondNumber;
	totalDifference = firstNumber - secondNumber;
	totalProduct = firstNumber * secondNumber;
	totalDiv = firstNumber / secondNumber;
	totalMod = firstNumber % secondNumber; 

	// "Real Divison"
	totalDivision = (float)firstNumber / (float)secondNumber; 

	cout << endl;

	cout << firstNumber << " + " << secondNumber << " = " << totalSum << endl;
	cout << endl;
	cout << firstNumber << " - " << secondNumber << " = " << totalDifference << endl;
	cout << endl;
	cout << firstNumber << " * " << secondNumber << " = " << totalProduct << endl;
	cout << endl;
	cout << firstNumber << " / " << secondNumber << " = " << totalDivision << endl;
	cout << endl;
	cout << firstNumber << " div " << secondNumber << " = " << totalDiv << endl;
	cout << endl;
	cout << firstNumber << " mod " << secondNumber << " = " << totalMod << endl;


	return 0; 
}