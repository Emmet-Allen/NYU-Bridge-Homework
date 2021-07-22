#include <iostream>

using namespace std;

void removeSpaces(string &firstStirng, string& secondString);
bool isAnagram(string &firstString, string& secondString);


const int MAX_CHAR = 10000;
// Used to convert char's from Uppercase to Lowercase
const int LOWER_CONVERSION_VALUE = 32;

int main(){
    string firstSentence, secondSentence;

    cout << "Please enter two sentences to comapre." << endl;
    cout << "First Sentence: ";
    getline (cin, firstSentence);
    cout << "Second Sentence: ";
    getline (cin, secondSentence);

    removeSpaces(firstSentence, secondSentence);

    bool checkAnagram = isAnagram(firstSentence, secondSentence);

    if(checkAnagram == true){
        cout << "Is anagram" << endl;
    }
    else{
        cout << "Is not anagram" << endl; 
    }
    return 0;
}

// Remove spaces, comma's and periods from string, and returns a new string without them.
// Also converts all characters in the string into lower-case, for ease of use. 
void removeSpaces(string &firstString, string &secondString){ 
string firstNoSpaces, secondNoSpaces;
char upperToLower;  

    for (int i = 0; i < firstString.length(); i++){
        if ( (firstString[i] >= 'A'  && firstString[i] <= 'Z' ) ){
            //Wasn't sure if we can use 'uppertoLower' so I just made it myself. Casted str5 to int for safety. 
            upperToLower = (int)firstString[i] + LOWER_CONVERSION_VALUE;
            firstNoSpaces += upperToLower; 
        }
        else if ( (firstString[i] >= 'a' && firstString[i] <= 'z')  ){ 
            firstNoSpaces += firstString[i];
        }
    }

    for (int i = 0; i < secondString.length(); i++){
        if ( (secondString[i] >= 'A'  && secondString[i] <= 'Z' ) ){
            //Wasn't sure if we can use 'uppertoLower' so I just did it myself. Casted str5 to int for safety. 
            upperToLower = (int)secondString[i] + LOWER_CONVERSION_VALUE;
            secondNoSpaces += upperToLower; 
        }
        else if ( (secondString[i] >= 'a' && secondString[i] <= 'z')  ){ 
            secondNoSpaces += secondString[i];
        }
    }
   firstString = firstNoSpaces;
   secondString = secondNoSpaces;
}

// This function is doing alot, and I could've broken it down to subfunctions, but eh. 
// First it converts the strings into ASCII and puts them in an array.
// Then it adds the ASCII values in the arrays and compares them. 
bool isAnagram(string &firstString, string& secondString){
//First and Second Array holds values of characters
int firstArray[MAX_CHAR] = {0};
int secondArray[MAX_CHAR] = {0}; 
//First and Second counter is used to add all the valeus in the array
int firstCounter = 0;
int secondCounter = 0;
bool anagramFlag; 


    for (int i = 0; i < firstString.length(); i++){
        //Converts each char in the string into a int of ASCII value, and appends it to an array
        firstArray[i] += (int)firstString[i];
    }

    for (int j = 0; j < secondString.length(); j++){
        secondArray[j] += (int)secondString[j];
    }

    for (int i = 0; i <  MAX_CHAR; i++){
        // Adds up all the ASCII values in the array
        firstCounter += firstArray[i];
    }

    for (int i = 0; i <  MAX_CHAR; i++){
        secondCounter += secondArray[i];
    }

    // If the ASCII values of both first and second counter are equal, it safe to say its an anagram. 
    // Assuming proper use of the program. 
    if(firstCounter == secondCounter){
        anagramFlag = true;
    }    
    else{
        anagramFlag = false;
    }

    return anagramFlag; 

}