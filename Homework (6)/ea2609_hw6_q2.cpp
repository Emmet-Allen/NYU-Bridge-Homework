#include <iostream>

using namespace std;


//For this triangle, we want:
// n to be the maximum row number
// m to be the the number of spaces the triangle is shifted from the margin 
// symbol which takes in a char to print out the traingle with

// Firstly we need to have n be the maximum row number, by having a loop that loops from 1 to n
// Inside the row loop, we need to have our spaces and our triangle.

//when n = 3, m = 4, symbol = +, the output is the below triangle

// ......+   1st Level =  6 Spaces, 1 characters = 7 total
// .....+++  2nd Level =  5 Spaces, 3 characters = 8 total
// ....+++++ 3rd Level =  4 Spaces, 5 characters = 9 total

// So the spaces would need to start atleast 2 above m or 2 + m, then decrement by 1 up to the row number

//Because if we have, n = 3,  m = 8, spaces would be 

//..........+   10 spaces
//.........+++  09 spaces 
//........+++++ 08 spaces

// We need to acount for the fact that the LAST row consist of "m" number of spaces

//For the triangle we can use the formula (rows * 2 - 1) for each iteration of rows up to n


void printShiftedTriangle(int n, int m, char symbol){
    int startSpaces = n + m - 2;
    int maxChara = 1; 

    for(int rows = 1; rows <= n; rows++){

        for(int spaces = 0; spaces < startSpaces; spaces++){
            cout << " ";
         
        } 
        for(int triangle = 1; triangle <= maxChara; triangle++){
            cout << symbol; 
        }
        startSpaces--; 
        maxChara += 2; 
        cout << endl; 
    }

}

// ...#         1st Row: 3 spaces 1 char
// ..###        2nd Row: 2 spaces 3 char

// ...#         3rd row: 3 spaces 1 char
// ..###        4th row: 2 spaces 3 char
// .#####       5th row: 1 spaces 5 char

// ...#         6th row: 3 spaces 1 char
// ..###        7th row: 2 spaces 3 char
// .#####       8th row: 1 spaces 5 char
// #######      9th row: 0 spaces 7 char

//The pyramids loop by the same (n * 2 - 1), 



void printPineTree(int n, char symbol){
    int leftShift = n;

    //We can initalize i to 2 because the smallest pyramid is lower
    //leftShift will go decrament by 1 for each level that is looped   
    for(int i = 2; i <= (n + 1); leftShift--, i++){
        //We can re-use the printShifted function and have the leftShift be the "m" spaces
        printShiftedTriangle(i, leftShift, symbol) ;

    }

    }





int main(){
int n; 
int m;
char symbol;


cout << "Input the maximum row number: " << endl; 
cin >> n; 

cout << "Input the symbol to be used: "<< endl; 
cin >> symbol; 


//printShiftedTriangle(m, n, symbol);
printPineTree(n, symbol);

    return 0;
}