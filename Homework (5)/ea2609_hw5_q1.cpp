#include <iostream>

using namespace std;

int main() {

	//Write a program that reads a positive integer n from the user and prints out a nxn
	//multiplication table. The columns should be spaced by a tab.

	int input;


	cout << "Please enter a positive integer: " << endl;
	cin >> input; 

	// Row of numbers from 1 to user input
	for (int start = 1; start <= input; start++) {
	
		// Multiplication of numbers from n*n
		for (int multiple = 1; multiple <= input; multiple++) {
			cout << multiple * start << '\t';
		}
		cout << endl;
	}


	return 0;
}