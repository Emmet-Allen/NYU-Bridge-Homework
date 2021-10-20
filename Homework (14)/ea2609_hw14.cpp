#include <iostream>
#include <vector>

using namespace std;

template<class T>
vector<T> divAndConq(vector <T>& numbVec, int start, int end){
    //Variables to store the end of the left side and the start of the right side
    int mid = (start + end)/2;
    int secondMid = mid + 1;

    //Vector to store the min and max numbers
    vector<T> minMax = {0,0};

    //1 comparision
    if(start == end){
        minMax[0] = numbVec[start];
        minMax[1] = numbVec[end];
        return minMax;
    }
    //2 comparisions
    else if(start == end - 1){
        if(numbVec[start] <= numbVec[end]){
            minMax[0] = numbVec[start];
            minMax[1] = numbVec[end];
        }
        else{
            minMax[1] = numbVec[start];
            minMax[0] = numbVec[end];
        }
        return minMax;
    }
    //Multiple comparisions, recursively sort left and right sides
    vector<T> leftSide = divAndConq(numbVec, start, mid);
    vector<T> rightSide = divAndConq(numbVec, secondMid, end);
    // Compare the lowest and highest of both left and right side
    // Then store them into the minMax vector
    minMax[0] = std::min(leftSide[0], rightSide[0]);
    minMax[1] = std::max(leftSide[1], rightSide[1]);
    return minMax;
}

int main(){

//Testing purposes
vector <int> test = {12,2,4,5,7,81,1};
int start = 0;
int end = 6;
vector<int> otherMinMax = divAndConq(test, start, end);

cout << "The mininum of the list is:" << otherMinMax[0] << endl;
cout << "The maximum of the list is:" << otherMinMax[1] << endl;
}