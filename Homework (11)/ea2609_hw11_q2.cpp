#include <iostream>

using namespace std;
int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
	int arr[] = { 1, 2, 3 ,4 };
	int arrSize = 4;
	int sum = 0;
	bool sortFlag = false;

	sum = sumOfSquares(arr, arrSize);
	sortFlag = isSorted(arr, arrSize);
	cout << sum << endl;
	cout << sortFlag; 

	return 0;
}

int sumOfSquares(int arr[], int arrSize) {
	if (arrSize == 0) {
		return 0;
	}
	else {
		return sumOfSquares(arr, arrSize - 1) + arr[arrSize - 1] * arr[arrSize - 1] ;
		}
	}

bool isSorted(int arr[], int arrSize) {
	if (arrSize == 0) {
		return true;
	}
	else {
		isSorted(arr, arrSize - 1);
		int max = arrSize - 1; 
		if (arr[arrSize - 1] < arr[arrSize - 2]){
			return false;
		}
		else {
			return isSorted(arr, arrSize - 1);
		}
	}

}