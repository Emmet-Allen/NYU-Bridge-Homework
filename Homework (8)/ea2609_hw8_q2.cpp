#include <iostream>
#include <string>

using namespace std; 

bool isPlaindrome(string str);

int main(){
    string userStringInput; 

    cout << "Please enter a word: ";
    cin >> userStringInput; 

bool checkPlaindrome = isPlaindrome(userStringInput);  

    if(checkPlaindrome == true){
        cout << userStringInput << " is a palindrome.";
    }
    else{
        cout << userStringInput << " is not a palindrome."; 
    }

    return 0;
}

//Checks if the string is a plaindrome
bool isPlaindrome(string str){
    //same and differen are counters to see if the char at the 'i' and 'j' indexes are the same or different
    int same = 0, different = 0;

    // forward and backward are going to hold the char values of the string at the 'i' and 'j' indecies
    char forward, backward; 

    // We intialize i as 0 for the start of the string because i is going forward, and we have the condition for the length of the string
    // We initalize j as "str.length() - 1" so that it starts at the end of the string, after the null char. 
    // The condition is dependent on i and the total length of the string (besides the null char, so we -1).
    // 'i' increments forward along the string, while 'j' decrements backwards along the string.
    for(int i  = 0, j = str.length() - 1; i <= str.length() - 1; i++, j--){

    //foward and backward hold the char of the string at the 'i' and 'j' index
        forward = str[i];
        backward = str[j];

    // we then compare and increment based on if the words are the same or not. 
        if (forward == backward){
            same++; 
        }
        else{
            different++; 
        }

    }

    // A palindrome will always have a value of same characters, greater than the ones that are different, and there will be no different chars. 
    // We could probably take out the "same" counter, but it may be useful if we want to see how same and different words that aren't palindromes are, i.e. apple: 2 same, 3 different etc. 
    if(different == 0){
        return true;
    }
    else{
        return false;
    }
}




//    for(int j = (str.length() -1); j > str.length(); j--){

//     }

// l e v e l 
// 0 1 2 3 4 ->
// 4 3 2 1 0 <-