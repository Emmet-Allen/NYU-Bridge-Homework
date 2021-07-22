#include <iostream>

using namespace std;

int jumpIt(int* arr, int arrSize);

int main() {
	int jumpArray[6] = { 0, 3, 80, 6, 57, 10 };
	int jumpArraySize = 6; 
	int jumpSolution = 0;

	jumpSolution = jumpIt(jumpArray, jumpArraySize);
	cout << jumpSolution - 1;

	return 0;
}


int jumpIt(int* arr, int arrSize) {
	if (arrSize == 0){
		return 0; 
	}
	else {
		int min = arr[arrSize - 1]; 
		int lastArray = arr[arrSize - 1];
		cout << "Before Recursion :" << arrSize << endl;
		jumpIt(arr, arrSize - 1);
		cout << "After Recursion: " << arrSize << endl;

		if (min < arr[arrSize]) {
			int min = arr[arrSize];
			
		}
		else {
			int min = arr[arrSize];
		}
		cout << min + lastArray;
		return lastArray + min;
	}
}