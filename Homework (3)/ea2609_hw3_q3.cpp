#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double a, b, c, bSquared;
	double negativeQuad, positiveQuad, factoredQuad;


	cout << "Please enter a value of a:"; cin >> a;
	cout << "Please enter a value of b:"; cin >> b;
	cout << "Please enter a value of c:"; cin >> c;


	bSquared = (b * b);
	factoredQuad = bSquared - (4*a*c);
	negativeQuad = (-b - sqrt(factoredQuad)) / (2*a);
	positiveQuad = (-b + sqrt(factoredQuad)) / (2*a);


	if (a == 0 && b == 0 && c == 0) {
		cout << "There are an infinite number of solutions";
	}

	else if (a == 0) {
		cout << "There are no solutions" << endl;
	}

	else if (factoredQuad > 0) {
		cout << "This equation has two real solutions x = " << negativeQuad << " & " << positiveQuad << endl;;
	}

	else if (factoredQuad == 0) {
		cout << "This equation has a single real solution x = " << negativeQuad << endl; 
	}

	else {
		cout << "This equation has no real solutions" << endl;;
	}

	return 0;
}





























