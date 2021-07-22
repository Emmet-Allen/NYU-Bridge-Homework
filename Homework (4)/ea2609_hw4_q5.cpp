#include <iostream>

using namespace std;
int main(){
int lineNumber, lineCount, starCount, spaceCount, lineNumberTwice; 

    cout << "Please enter a number of lines: ";
    cin >> lineNumber; 

    lineNumberTwice = (lineNumber * 2);

// Top Half
        //Incraments Line by 1
    for(lineCount = 1; lineCount <= lineNumber; lineCount++){

            //Provides space if spaceCount is less than or equal to the current lineCount - 1: i.e. 0 Space, 1 Space, 2 space etc...
         for(spaceCount = 0; spaceCount < lineCount - 1; spaceCount++){
            cout << " ";
                }
        
            //Prints out Star if starCount is less than Line Number to satisfy n-1 stars
        for(starCount = lineCount - 1; starCount < lineNumber; starCount++){
           //cout<<"Star Count: " << starCount << " "; 
              cout << "*"; 
        }
            //Because each line of stars is 2n-1, This line provides 'n' number of stars 
        for(starCount = lineCount; starCount < lineNumber; starCount++){
           //cout<<"Star Count: " << starCount << " "; 
              cout << "*"; 
        }

            //Outerloop that ends the line for the Top Half
      // cout <<"Line number: " <<lineCount<<endl;
          cout << endl;
    }

// Bottom Half
    for(lineCount = 1; lineCount <= lineNumber; lineCount++){

        //Reverse amount of spaces such that the spaceCount is going to be n - 1, and will decrament for each level of n, i.e. 1 space, 2 space, 3 space etc...
         for(spaceCount = lineNumber; spaceCount > lineCount; spaceCount--){
            cout << " ";
                }
        
        //This will print out n number of stars
        for(starCount = 0; starCount < lineCount; starCount++){
          //  cout<<"Star Count: " << starCount << " "; 
              cout << "*"; 
        }

        // This will print out n + 2 number of stars when starCount is greater than or equal to lineNumber
        for(starCount = lineCount + 2; starCount >= lineNumber; starCount--){
            cout << "*";
        }

       // cout <<"Line number: " <<lineCount<<endl;
          cout << endl;
    }










    // for(lineCount = 1; lineCount < lineNumber; lineCount++){
       
        
    //     for(spaceCount = 1; spaceCount <= lineCount; spaceCount++){
    //         cout << ".";
            
    //     }
        
    //     for(starCount = lineNumberTwice - 2; starCount > lineCount; starCount--){
    //         cout << "*";
    //     }


    //     for(spaceCount = 0; spaceCount < lineCount; spaceCount++){
    //         cout << ".";
            
    //     }


    //      cout << endl;
    
    // }




    // for(lineCount = 1; lineCount < lineNumber; lineCount++){

    //     for(spaceCount = lineCount; spaceCount < lineCount; spaceCount++){
    //         cout << spaceCount;
    //     }

    //     cout << endl;
    // }

   return 0;
}










// *******
// .*****.
// ..***..
// ...*...
// ...*...
// ..***..
// .*****.
// *******





