#include <iostream>

using namespace std;


// Fibonacci numbers are F(n) = F(1) + F(2) ... F(n), where n is number within the sequence
// OR F(n) = F(n-1) + F(n-2) 
// So F(7) = F(7 - 1) + F(7 - 2) = F(6) + F(5) = 8 + 5 = 13
// We need a variable to hold the first number f(0) = 0
// And a second variable to hold the second number f(1) = 1

// We then need a for loop that will loop through 2 to n (2 because f(2) = f(2-1) + f(2-2) = f(1) + f(0) = 0)

// From there we would need to itterate the loop from 2 to 3
// 3 would then be (f(3) = f(3-1) + f(3-2) = f(2) + f(1) = 2)

// So we need to reassign the first number from f(0) to f(1) or from 0 to 1
// And also reassing the second number from f(1) to f(2) or from 1 to 1

// For the first number, we can reassign it the value of f(1) by having it equal to the previous fibonnaci sequence
// For the second number, we need that to hold the second previous sequence. We can do this by assigning it the first number before reassigning it, so it holds the value


int fib(int n){

int fibnumber =0;
int firstHolder = 0;
int secondHolder = 1;

    


    if(n == 0){
        cout << fibnumber << endl;
        return fibnumber = 0;
    }
    
    else{
    for(int i = 1; i <= n; i++){
        fibnumber = firstHolder + secondHolder;
        secondHolder = firstHolder;
        firstHolder = fibnumber;
    }

    return fibnumber;
}
}



int main(){

int n;

    cout << "Please enter a positive integer: ";
    cin >> n; 
    cout << fib(n) << endl;


    return 0;
}