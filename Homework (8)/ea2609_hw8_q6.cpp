#include <iostream>
#include <string>

using namespace std;


void censor(string& str);

int main(){
string lineText, outLineText;

cout << "Please enter a line of text:";
getline(cin, lineText); 

censor(lineText);

return 0;
}

void censor(string& str){
string seperatedWord;
int lastChar = str.length() - 1;
int spacePos = 0;
    for(int i = 0, j = 0; i < str.length(); i++){
        if(str[i] == ' ' && j == 0){
            spacePos = i;
            seperatedWord = str.substr(j, spacePos);
            for(int k = 0, q = 1; k < seperatedWord.length(); k++, q++){
                if(seperatedWord[0] >= 'A'){
                    cout << seperatedWord;
                    break; 
                }
                else{
                    seperatedWord[k] = 'x';
                    cout << seperatedWord[k];
                }
            }
            j = i;
        }
        else if (str[i] == ' ' && str[j] == ' '){
            spacePos = i; 
            seperatedWord = str.substr(j, spacePos - j);
            for(int k = 0, q = 1; k < seperatedWord.length(); k++, q++){
                if(seperatedWord[k] >= 'A'){
                    cout << seperatedWord;
                    break;
                }
                else if(seperatedWord[k] == ' '){
                    cout << seperatedWord[k];
                }
               else{
                    seperatedWord[k] = 'x';
                    cout << seperatedWord[k];
                }
            }
            j = i; 
        }
        else if(i == lastChar && str[j] == ' '){
            seperatedWord = str.substr(j, i - j + 1);
            for(int k = 0, q = 1; k < seperatedWord.length(); k++, q++){
                if(seperatedWord[k] >= 'A' || seperatedWord[k] == ' '){
                    cout << seperatedWord[k];
                }
                else if(seperatedWord[k] >= 'A'){
                    cout << seperatedWord;
                    break;
                }
               else{
                    seperatedWord[k] = 'x';
                    cout << seperatedWord[k];
                }
            }
        }
    }
    }