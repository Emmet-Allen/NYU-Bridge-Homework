#include <iostream>
#include <string>

using namespace std;

//Input : First Name, Middle Name, Last Name
//Output : Last Name(,) First Letter of Middle Name(.) First Name

// For example, the input
// Mary Average User
// should produce the output:
// User, Mary A.

// Ask the user for names


void properName(string str1); 

int main(){
string firstName, middleName, lastName;
string outputName; 

    cout << "Please input your First, Middle, and Last Name. Make sure to press \"Enter\" for each name: ";
    cin >> firstName >> middleName >> lastName;

    cout << lastName << ", " << firstName << " ";
    properName(middleName);  
    return 0; 
}

void properName(string str1){
char holder;

    for(int i = 0; i < str1.length() - 1; i++){
        holder = str1[i];

        if(holder = '.'){
            cout << str1[0] << holder << endl;
            break;
        }
        else{
            cout << str1[0] << "." << endl; 
        }
    }
       
    }
