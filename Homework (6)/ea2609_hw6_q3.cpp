#include <iostream>
#include <cmath>

using namespace std;


double eApprox(int n){
double inverseHolder = 0;
double factorialHolder = 1; 

// Use factorial Holder multiply into it (1! * 2! )
// This runs in constant time because we are using 

    for(int i = 1; i <= n; i++){
         factorialHolder *= i;
        inverseHolder += (1 / factorialHolder);
    }
    double eApproxHolder = (1 + inverseHolder);

    

    return eApproxHolder;
}



int main() {
int n; 

cout << "Please enter an integer: ";
cin >> n; 

cout.precision(30);
cout << eApprox(n);

    return 0;
}
