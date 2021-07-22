#include <iostream>

using namespace std; 

// void splitParity(int arr[],int arrSize)
void oddsKeepEvensFlip(int arr[], int arrSize);

int main(){

int arrSize; 

    cout << "How many values would you like in the Array: ";
    cin >> arrSize;

// Size is 'n', I'm assuming this means size is declared at runtime. 
int* arr = new int[arrSize]; 

    cout << "Please enter the values below." << endl;
    for(int i = 0; i < arrSize; i++){
        cin >> arr[i];  
    }

oddsKeepEvensFlip(arr, arrSize);

// Finished using "main" array so delete and NULL
delete[]arr; 
arr = NULL; 

    return 0;
}


void oddsKeepEvensFlip(int arr[], int arrSize){

// Used to create dynamic arrays of evens and odds
// Because we aren't sure how many evens and odds the user will use within in the "main" array
int* evensArr = new int[arrSize];
int* oddsArr = new int[arrSize];


int counter1 = 0;
int counter2 = 0;
// Keeps odds by looping through the array going forward.
    for(int i = 0; i < arrSize; i++, counter1++){
        //If its odd, put it in the odds Array
        if(arr[i] % 2 != 0){
        oddsArr[counter1] = arr[i];
        cout << oddsArr[counter1] << ' ';
        }
    }

// Reverses evens by looping through the array going backward.
    for(int i = arrSize; i > 0; i--, counter2++){
        //If its even, put it in the evens Array
        if(arr[i] % 2 == 0){
            evensArr[counter2] = arr[i];
            cout << evensArr[counter2] << ' ';
        }
    }

//Finished using those arrays, so delete and NULL
    delete[] evensArr;
    evensArr = NULL;
    delete[] oddsArr;
    oddsArr = NULL;
}








