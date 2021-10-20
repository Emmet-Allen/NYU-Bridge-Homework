#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stack> 

using namespace std;

// class CompilerStack{
//     private:
//     list<char> validChar;

//     public:
//     void push(char openingChar){
//         validChar.push_front(openingChar);
//     }

//     char pop(){
//         return validChar.pop_front();
//     }

//     char top() const{
//         return *validChar.begin();
//     }

//     bool isEmpty() const{
//         return validChar.size() == 0;
//     }

//     int size()  const{
//         return validChar.size();
//     }

// };

// class openChar{
//     private:
//     char validChar;

//     public:
//     openChar(char readin){
//         if(readin == '{' || readin == '(' || readin == '['){
//             validChar = readin; 
//         }
//     };
//     char setValidChar(char opening){
//         validChar = opening;
//     }

//     void getValidChar(){
//         return validChar; 
//     }

// }

//Take in the file, and read each char line-by-line
// If the char is an openChar '{([' push it into the stack
// If a char is pushed into the stack, keep a running count as a safety measure.

// If a char is a closeChar '}])' then pop an openChar out of the stack
// If the stack is empty, and the running count is 0. Then it is a valid program
// If the stack is not empty, or the running count is not 0, then the program has an error.

void openInputFile(ifstream& inFile){
    string fileName;
    cout << "Please enter a PASCAL Program text file: ";
    cin >> fileName;
    inFile.open(fileName);
    while(!inFile){
        cout << "File Failed to open." << endl;
        cout << "Please enter a PASCAL Program text file: ";
        cin >> fileName; 
        inFile.clear(); 
        inFile.open(fileName);
    }
}

int main(){

    stack<char> compilerCheck; 
    string readLine;

    ifstream inFile;
    openInputFile(inFile);
    while(inFile >> readLine){
        for(int i = 0; i < readLine.length(); i++){
            if(readLine[i] == '{' || readLine[i] == '(' || readLine[i] == '['){
                compilerCheck.push(readLine[i]);
            }
            else if(readLine[i] == '}' || readLine[i] == ')' || readLine[i] == ']'){
                if(compilerCheck.top() == '{' && readLine[i] == '}'){
                    compilerCheck.pop();
                }
                else if(compilerCheck.top() == '(' && readLine[i] == ')'){
                    compilerCheck.pop();
                }
                else if(compilerCheck.top() == '[' && readLine[i] == ']'){
                    compilerCheck.pop();
                }
            }
            if(readLine == "BEGIN" || readLine == "begin"){
                compilerCheck.push('b');
            }
            if(readLine == "END" || readLine == "end"){
                if (compilerCheck.top() == 'b')
                        compilerCheck.pop(); 
            }
        }
    }

    int stackSize = compilerCheck.size();
    bool validProgram(stackSize);
    return 0;
}

bool validProgram(int size){
    if(size == 0){
        return true;
    }
    else{
        return false;
    }
}