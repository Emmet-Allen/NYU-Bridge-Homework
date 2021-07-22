#include <iostream>
#include <string>

using namespace std; 
const int MAX_CHAR = 26; 

int wordCount(string &str);
int letters(string &str2);
string removeSpaces(string &str5); 
void countOrderedLetters (string str6);



int main(){
    string str1;

    cout << "Enter a sentence: " << endl; 
    getline(cin, str1);

int wordCounter = wordCount(str1);
cout << wordCounter << '\t' << "words" <<endl; 

string Nospaces = removeSpaces(str1);

countOrderedLetters(Nospaces);
    
    return 0;
}

// Counts Words using spaces, assuming the user won't over space. Need to clarify, would use substr to count spaces instead, but it was ill advised. 
int wordCount(string &str){
    int spaceCounter = 0; 
    
    for(int i = 0; i < str.length(); i++){
        if( (str[i] == ' ' || str[i] == ',' || str[i] == '.') && ( (str[i - 1]) >= 'a' || (str[i - 1]) <= 'z' || (str[i - 1]) >= 'A' || (str[i - 1]) <= 'Z' ) ){
            spaceCounter+= 1;
        }
    }
     return spaceCounter;
}

// Counts Letters using chars in string, not necesscary but I used it as a check function. 
int letters(string &str2){
    int letterCounter = 0; 
    
    for(int i = 0; i < str2.length(); i++){
        if( (str2[i] >= 'a' && str2[i] <= 'z') || ( str2[i] >= 'A' && str2[i] <= 'Z' ) ){
            letterCounter++;
        }
    }
    return letterCounter; 
}

// Remove spaces, comma's and periods from string, and returns a new string without them. 
string removeSpaces(string &str5){ 
string NoSpaces;
char upperToLower;  

    for (int i = 0; i < str5.length(); i++){
        if ( (str5[i] >= 'A'  && str5[i] <= 'Z' ) ){
            //Wasn't sure if we can use 'uppertoLower' so I just made it myself. Casted str5 to int for safety. 
            upperToLower = (int)str5[i] + 32;
            NoSpaces += upperToLower; 
        }
        else if ( (str5[i] >= 'a' && str5[i] <= 'z')  ){ 
            NoSpaces += str5[i];
        }
    }
    return NoSpaces; 
}

void countOrderedLetters (string str6){
    int letters[MAX_CHAR] = {0};
    int counter = 0; 
    
    for(int i = 0; i < str6.length(); i++){
        letters[str6[i] - 'a'] += 1;
    }
    
    for(int i = 0; i < MAX_CHAR; i++){
        if(letters[i] > 0){
        cout << letters[i] << "\t" << char(i + 'a') << endl;
        }
    }
    }