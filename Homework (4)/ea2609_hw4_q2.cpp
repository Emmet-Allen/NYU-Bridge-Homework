#include <iostream>


const int M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1; 
using namespace std;
int main() {

	int m, d, c, l, x, v, i; 
    int input;

	cout << "Enter decimal number:" << endl;
	cin >> input; 

    cout << input << " is ";


	//While the input is is greater than or equal to 0 
	while (input >= 0) {
		//For each case of the Input that is greater than the assigned Roman numerals
		if (input >= M) {
		//Assign a holder value that div's the input by that Roman Numeral Value 
			m = input / M;
		//Now loop through a variable up until the holder value and print out the Roman numeral	
			for (int j = 0; j < m; j++) {
				cout << "M";
			}
		// After the loop, take the mod of the Roman Numeral value and assign it to Input to remove those values	
			input %= M;
		}
		//The same logic above contains for each case of Roman Numerals
		else if (input >= D) {
			d = input / D;
			for (int j = 0; j < d; j++) {
				cout << "D";
			}
			input %= D;
		}
		else if (input >= C) {
			c = input / C;
			for (int j = 0; j < c; j++) {
				cout << "C";
			}
			input %= C;
		}
		else if (input >= L) {
			d = input / L;
			for (int j = 0; j < l; j++) {
				cout << "L";
			}
			input %= L;
		}
		else if (input >= X) {
			x = input / X; 
			for (int j = 0; j < x; j++) {
				cout << "X";
			}
			input %= X;
		}
		else if (input >= V) {
			v = input / V;
			for (int j = 0; j < v; j++) {
				cout << "V";
			}
			input %= V;
		}
		else if (input >= I) {
			i = input / I;
			for (int j = 0; j < i; j++) {
				cout << "I";
			}
			input %= I;
		}

	}

	return 0;
}