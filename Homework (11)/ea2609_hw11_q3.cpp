#include <iostream>

using namespace std;

const int MIN_INT = -2147483647;
int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

int main() {

	int arr[10] = { 9, -2, 14, 12, 3, 6, 2, 1, -9, 15 };
	int res1, res2, res4, res3; 

	res3 = minInArray2(arr, 2, 5);
	res2 = minInArray2(arr, 0, 9);
	res4 = minInArray1(arr + 2, 4);
	res1 = minInArray1(arr, 10);
	cout << res1 << ' ' << res4 << endl;

	cout << res2 << ' ' << res3 << endl; 

	return 0;
}

int minInArray1(int arr[], int arrSize) {

	if (arrSize == 0) {
		return 0;
	}
	else {
		minInArray1(arr, arrSize - 1);
		int min = MIN_INT;
		int temp = arr[arrSize];
		if (temp < arr[arrSize - 2]) {
			temp = arr[arrSize - 2];
			min = temp;
		}
		return min;
	}
	
}

int minInArray2(int arr[], int low, int high) {
	if (arr[low] == arr[high]) {
		return arr[low];
	}
	else {
		int min = minInArray2(arr, low + 1, high);
		if(arr[low] < min){
			min = arr[low];
		}
		return min;
		
	}
}