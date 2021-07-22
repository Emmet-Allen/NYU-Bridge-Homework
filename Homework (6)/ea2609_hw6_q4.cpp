#include <iostream>
#include <cmath>

using namespace std;

void printDivisors(int num){

int counter = 0;

    for(int i = 1; i <= sqrt(num); i++){
        // This is for the lower half of the divisors
        if(num % i == 0 ){
            cout << i << ' ';
        }
    }

    for(int i = sqrt(num); i >= 1; i--){
        if(num % i == 0){
            //This is for the upper half of the divisors
            cout << num / i << ' '; 
        }
    }
}




int main(){
    int num;
    cout << "Please enter a positive integer >= 2: ";
    cin >> num; 
    printDivisors(num);

    return 0;
}