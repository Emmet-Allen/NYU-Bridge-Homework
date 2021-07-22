#include <iostream>

using namespace std; 

int minInArray(int arr[], int arrSize);
const int MAX_ARRAY_SIZE = 20;
void minInArrayIndex(int arr[], int arrSize, int minNumber);

int main(){
int valueArr[MAX_ARRAY_SIZE];
int array; 

// Prompt user for array values
    cout << "Please enter 20 integers separated by a space: " << endl;
    for(int i = 0; i < MAX_ARRAY_SIZE; i++){
        cin >> valueArr[i];
    }

// Store the value of the minInArray function into minNumber, pass the array "valueArr" and Array Size
int minNumber = minInArray(valueArr, MAX_ARRAY_SIZE); 
cout << "The minimum value is " << minNumber << ", and it is located in the following indices:";

// Void function to print out the indices of the min number in the array
minInArrayIndex(valueArr, MAX_ARRAY_SIZE, minNumber);

return 0;
}

//minInArray function
int minInArray(int arr[], int arrSize){
int maxInteger = 2147483647;
int minNumber = 0; 

    for(int i = 0; i < arrSize; i++){
        //Compare max int value to current array index, and if maxInteger is bigger than array index value
        if(maxInteger >= arr[i]){
            // Assign the array index value to the minNumber in the Array
            minNumber = arr[i];
            // Also assign the array index value to the maxInteger and further compare for each index value
            maxInteger = arr[i];
        }
    }
    return minNumber; 
 }

// Print Function for the mininum array index value, extra parameter of minNumber from the "minInArray" function 
 void minInArrayIndex(int arr[], int arrSize, int minNumber){
    for(int i = 0; i < arrSize; i++){
        // If the minNumber is equal to the array value at that index
        if(minNumber == arr[i]){
            // Return the value of i, which would be the position in the array of that value
            cout << i << " "; 
        }
    }
 }
