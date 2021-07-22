#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
const int ARRAY_SIZE = 10; 
const int RANDOM_RANGE = 3;
const string PASSWORD = "42069"; 
const int PIN_LENGTH = 5; 

void randomGenerator(int arr[], int arrSize);
bool passwordCheck (int arr[], string userInput, string goalPin, int arrSize);

int main(){

int randomArray[ARRAY_SIZE];
int logicalArrSize = 10;
string userInput;  

    cout << "PIN: " << '\t'; 
    for(int i = 0; i < logicalArrSize; i++){
    cout << i << ' ';
    }

    cout << endl; 

randomGenerator(randomArray, logicalArrSize);

cin >> userInput; 

cout << endl; 
bool isCorrect = passwordCheck (randomArray, userInput, PASSWORD, logicalArrSize);

    if(isCorrect == true){
        cout << "Password is correct" << endl; 
    }
    else{
        cout << "Password is incorrect" << endl;
    }


return 0; 
}

void randomGenerator(int arr[], int arrSize){
srand(time(0));

    cout << "NUM: " << '\t';
    
    for(int j = 0; j < arrSize; j++){   
        arr[j] = ((rand() % RANDOM_RANGE) + 1);
        cout << arr[j] << ' ';
    }
    cout << endl;    
}

bool passwordCheck (int arr[], string userInput, string goalPin,  int arrSize){
bool passwordFlag = true;  

    for(int i = 0; i < PIN_LENGTH; i++){
        int digitInput = userInput[i] - '0';         
        int digitPin = PASSWORD[i] - '0';

        if(arr[digitPin]  != digitInput){
            passwordFlag = false; 
        }
    }
    return passwordFlag; 
}

       
       
       
       
       // cout << endl; 
       // cout << "Random Array Index " << i << "th place " << arr[i] << endl;
       // cout << "User Input " << i << "th place " << (int)userInput[i] - '0' << endl;
       // cout << "Goal Input " << i << "th place " << (int)goalPin[i] - '0' << endl;

        




        // Taking 1 value, 
        // if( (arr[i] == (int)userInput[i] - '0') && (arr[i] ==(int)goalPin[i] - '0') ){
        //     return passwordFlag = true; 
        // }
        // else{
        //     return passwordFlag = false;
        //     break;
        // }

