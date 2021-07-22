#include <iostream>

using namespace std;

void printArray(int* arr, int arrSize);
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main(){
   int arr[6] = {3,-1,-3,0,6,4};
   int staticArrSize = 6;
   int dynamicArrSize = 0; 
   int* outPosArrSize2 = &dynamicArrSize; 
   int* posArr3 = NULL;
   int outPosArrSize1 = staticArrSize;
   int* outPosArr = NULL;
   int** outPosArrPtr = NULL;
   int outPosArrSize3;   
   int* outPosArrSize4 = &dynamicArrSize;
   outPosArrPtr = &posArr3;
   
// Returns the base address of the new array.
// Changes the array size.
// Console outputs the values stored within the new array.      
 cout << "First Function: " << endl;   
 int* posArr1 = NULL;
 posArr1 = getPosNums1(arr, staticArrSize, outPosArrSize1);
 cout << "The base address of the updated array is: " << posArr1 << endl; 
 printArray(posArr1, outPosArrSize1);
 delete[] posArr1; 
 posArr1 = NULL;


 cout << "Second Function: " << endl;
 int* posArr2 = getPosNums2(arr, staticArrSize, outPosArrSize2);
 cout << "The base address of the updated array is: " << posArr2 << endl;
 printArray(posArr2, *outPosArrSize2);
 delete[] posArr2;
 posArr2 = NULL;

cout << "Third Function: " << endl;
getPosNums3(arr, staticArrSize, outPosArr , outPosArrSize3);
// The arrPtr would be the base address of that array that was passed from getPosNums3 to getPosNums1
cout << "The base address of the updated array is: " << outPosArr << endl;
printArray(outPosArr, outPosArrSize3);
delete[] outPosArr;
outPosArr = NULL; 


cout << "Fourth Function: " << endl;
getPosNums4(arr, staticArrSize, outPosArrPtr, outPosArrSize4);
cout << "The base address of the updated array is: " << outPosArrPtr << endl;
printArray(*outPosArrPtr, *outPosArrSize4);
delete[] *outPosArrPtr;
outPosArrPtr = NULL; 

    return 0;
}


void printArray(int* arr, int arrSize){
  for(int i = 0; i < arrSize; i++){
    cout << arr[i] << " ";
  }
  cout << endl; 
}



// returns the base address of the array (containing the positive numbers), and updates
// the output parameter outPosArrSize with the array’s logical size.

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
int counter = 0;           

//Gets size of the dynamic array by counting how many positive numbers there are in array.
    for(int i = 0; i < arrSize; i++){
      if(arr[i] > 0){
        counter++;
      }
    }

// Updates the outPosArrSize with the value of counter;
outPosArrSize = counter; 
// Intializes a dynamic array with the size of the positive numbers in the previous array
int* newArr = new int[counter];

int posCounter = 0; 
// Stores the the positive numbers from the previous array into the new array
  for(int i = 0; i < arrSize; i++){
    if(arr[i] > 0){
      newArr[posCounter] = arr[i];  
      posCounter++; 
    }
  }
//Returns the base address of the new array
  return newArr;
}



int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
// Create a counter for dynamically sized array
int counter = 0;

//Gets size of the dynamic array by counting how many positive numbers there are in array.
    for(int i = 0; i < arrSize; i++){
      if(arr[i] > 0){
        counter++;
      }
    }

// Have the positive array size pointer, be assigned the value of the counter 
*outPosArrSizePtr = counter; 

// Create a dynamic array, have it have the value of counter.
// Tried assigning it with outPosArrSizePtr, but error.
int* newArr = new int[counter];
int posCounter = 0; 
// Stores the the positive numbers from the previous array into the new array
  for(int i = 0; i < arrSize; i++){
    if(arr[i] > 0){
      newArr[posCounter] = arr[i];  
      posCounter++; 
    }
  }
//Returns the base address of the new array
  return newArr;
}

// This function uses a pointer-reference of an array. Arrays are called using this same logic. 
// So we can assign the value of the outPosArr to that of the function of getPosNums1
// This will create a new array, using arguments that were passed in getPosNums3
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
  outPosArr = getPosNums1(arr, arrSize, outPosArrSize);
}


void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){

int counter = 0; 

  for(int i = 0; i < arrSize; i++){
    if(arr[i] > 0){
      counter++;
    }
  }
  
*outPosArrSizePtr = counter; 

int* newArr = new int[counter];
int posCounter = 0; 

  for(int i = 0; i < arrSize; i++){
    if(arr[i] > 0){
      newArr[posCounter] = arr[i];  
      posCounter++; 
    }
  } 

// By dereferencing the pointer, you are subtracting a layer from the pointer
// Then that pointer will point to the address of the newArr array
  *outPosArrPtr = newArr;
}


