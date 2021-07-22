#include <iostream>

using namespace std;

// Have an array that hold n number of digits
// In the array, there are missing concurent digits up to n + 1
// i.e. {3,1,3,0,6,4} is missing {2,5} b/c the complete array is {0, 1, 2, 3, 4, 5, 6} which is n+1
// the function should return the missing digits in a new array and a new array size

// {3,1,3,0,6,4}
// {0,1,2,3,4,5,6}

int* findMissing(int arr[], int n, int& resArrSize);
void printArray(int arr[], int arrSize);
int main() {

	int logicalArrSize, arrNumberStore;
	int resizedArrSize = 0; 

	cout << "What is the range of the array?" << endl;
	cin >> logicalArrSize;

	int* dynamicArr = new int[logicalArrSize];
	
	cout << "Please input the individual values of array." << endl;

	for (int i = 0; i < logicalArrSize; i++) {
		cin >> arrNumberStore;
		dynamicArr[i] = arrNumberStore;
	}

	int* missingArr = findMissing(dynamicArr, logicalArrSize, resizedArrSize);
	printArray(missingArr, resizedArrSize);


	delete[] missingArr;
	delete[] dynamicArr; 
	return 0;
}

void printArray(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
}


int* findMissing(int arr[], int n, int& resArrSize) {
	int startSize = 1, counter1 = 0;
	int trueSize = n + 1, resize = 0;

	int numberStore = 0;

	int* trueArray = new int[trueSize];

	for (int i = 0; i < n; i++, counter1++) {
     	trueArray[counter1] = i;
	}

	int countCheck = n;
	for (int i = 0; i < n; i++) {
		if (arr[i] < n) {
			if (trueArray[arr[i]] != -1) {
				trueArray[arr[i]] = -1;
				countCheck--;
			}
		}
	}

	int* missingArray = new int[countCheck];
	int counter2 = 0;

	for (int i = 0; i < n; i++) {
		if (trueArray[i] != -1) {
			missingArray[counter2] = trueArray[i];
			counter2++;
		}
	}
	
	resArrSize = countCheck;
	delete[] trueArray; 
	return missingArray; 
}