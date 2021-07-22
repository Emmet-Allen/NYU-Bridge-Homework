#include <iostream>
#include <vector>

using namespace std;
vector <int> getNumbers2();
int* getNumbers1(int& outDynamicArrSize);
int* SearchNumbers1(int arr[], int& dynamicArrSizeIn, int& dynamicArrSizeOut);
int* SearchNumbers2(vector <int> vec, int& arrSize);
void printArray(int arr[], int arrSize);
int main_2();
int main_1();
 
int main() {

    int methodChoice = 0; 
   
    

    cout << "Which method would you like to use, choose either 1 or 2: ";
    cin >> methodChoice;
    
    if (methodChoice == 1) {
        int firstMethod = main_1();
    }
    else if (methodChoice == 2) {
        int secondMethod = main_2();
    }
    else {
        cout << "Invalid Response. Please try again.";
    }
  
    return 0;
}

int main_2() {
    int arrSize = 0;
    int* searchArr2 = NULL; 

    vector <int> vectorNums = getNumbers2();
    searchArr2 = SearchNumbers2(vectorNums, arrSize);

    printArray(searchArr2, arrSize);
    delete[] searchArr2; 

    return 0;
}

int main_1() {
    int* searchArr1 = NULL;
    int* retieveArr = NULL;
    int arrSize1 = 0;
    int arrSize2 = 0;

    retieveArr = getNumbers1(arrSize1);
    searchArr1 = SearchNumbers1(retieveArr, arrSize1, arrSize2);
    printArray(searchArr1, arrSize2);
    
    delete[] retieveArr;
    delete[] searchArr1;
    return 0;
}

int* getNumbers1(int& outDynamicArrSize) {
    int* dynamicArr;
    int dynamicArrSize, dynamicArrPhysicalSize;
    bool seenEndFlag;
    int currNum;

    cout << "Please enter a sequence of numbers." << endl;
    cout << "To end the input, type -1." << endl;

    dynamicArr = new int[5];
    dynamicArrSize = 0;
    dynamicArrPhysicalSize = 1;

    seenEndFlag = false;
    while (seenEndFlag == false) {
        cin >> currNum;
        if (currNum == -1)
            seenEndFlag = true;
        else {
            if (dynamicArrSize == dynamicArrPhysicalSize) {
                int* newDynamicArr;
                newDynamicArr = new int[2 * dynamicArrPhysicalSize];
                for (int i = 0; i < dynamicArrSize; i += 1)
                    newDynamicArr[i] = dynamicArr[i];
                delete[]dynamicArr;
                dynamicArr = newDynamicArr;
                dynamicArrPhysicalSize *= 2;
            }
            dynamicArr[dynamicArrSize] = currNum;
            dynamicArrSize += 1;
        }
    }

    outDynamicArrSize = dynamicArrSize;
    return dynamicArr;
}

vector<int> getNumbers2() {
    vector<int> numberVector;
    bool seenStop;
    int currentNumber;

    cout << "Please enter a sequence of numbers." << endl;
    cout << "To end the input, type -1." << endl;

    seenStop = false;
    while (seenStop == false) {
        cin >> currentNumber;
        if (currentNumber == -1)
            seenStop = true;
        else
            numberVector.push_back(currentNumber);
    }

    return numberVector;
}

int* SearchNumbers2(vector <int> vec, int &dynamicArrSize) {
    int searchNumber;
    int startSize = 1000;
    int* dynamicArr = new int[startSize];
    int counter = 0;

    cout << "Please enter a number you want to search for: ";
    cin >> searchNumber;
    cout << searchNumber << " shows in lines ";

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == searchNumber) {
            dynamicArr[counter] = i;
            counter++;
        }
    }
    dynamicArrSize = counter;
    return dynamicArr;
}

int* SearchNumbers1(int arr[], int &dynamicArrSizeIn, int &dynamicArrSizeOut) {
    int searchNumber;
    int startSize = 1000;
    int* dynamicArr = new int[startSize];
    int counter = 0;

    cout << "Please enter a number you want to search for: ";
    cin >> searchNumber;
    cout << searchNumber << " shows in lines ";

    for (int i = 0; i < dynamicArrSizeIn; i++) {
        if (arr[i] == searchNumber) {
            dynamicArr[counter] = i;
            counter++;
        }
    }
    dynamicArrSizeOut = counter;
    return dynamicArr;
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] + 1;
        if (i < arrSize - 1) {
            cout << ", ";
            }
        else if (i == arrSize - 1) {
                cout << '.';
            }
        }
    }
