// Write a program that asks the user to input a positive integer n, and print all of the numbers
// from 1 to n that have more even digits than odd digits.


#include <iostream>

using namespace std;
int main (){
    int input, evenCount, oddCount, holder, lastDigit;

    cout << "Please enter a positive integer: ";
    cin >> input;

//Have a loop that starts at 1 goes to i <= input
        // # of even digits
        // # of odd digits
        // # holder
    
        // Inner Loop : every digit of holder, check if digit is even or odd
        //get digit with mod 10
        // check if digit is even or odd if( digit % 2 == 0) evenHolder++ , else oddHolder++
        // divide by 10 to removed last digit
         // increament even or odd counter




    // For loop that increments through the input from 1 to input
    for(int counter = 1; counter <= input; counter++){
        holder = counter; //intialize holder to counter DONT MODIFY
        evenCount = 0; //intialize even counter
        oddCount = 0;   // initalize odd counter

        //Loop while counter > 0
        while(holder > 0){
        //Get the last digit of holder so if 76 then  76 % 10 = 6
        lastDigit = holder % 10;

            //If the last digit is even
            if(lastDigit % 2 == 0){
                //increment count
                evenCount++; 
                }
            // If the last digit is odd 
            else{
            //increment count
                oddCount++;
                }
        
        holder/= 10;
         }        
        
        //if evenCount greater than oddCount
        if(evenCount > oddCount){
            //output counter
            cout << counter << endl; 
        }
           


    }





    //     if(lastDigit % 2 == 0){
    //         for(int evenCount = 0; evenCount < lastDigit; evenCount+=2){
    //         cout << evenCount << endl;
    //             }
    //     }
    //     else{
    //         for(int oddCount = 1; oddCount < lastDigit; oddCount+=2)
    //         cout << oddCount << endl; 
    //     }
    // }
    return 0;
}
    
    
    
//     holder = input;

//     evenCount = 0;
//     oddCount = 1;
//     lastDigit = 0;

//     while(holder > 0){
//         lastDigit = holder % 10;

//             if(lastDigit % 2 == 0){
//                 for(int evenCount = 0; evenCount < lastDigit; evenCount+=2){
//                 cout << evenCount << endl;
//                 lastDigit /= 10;
//                 }
//             }
//             else{
//                 for(int oddCount = 1; oddCount < lastDigit; oddCount+=2)
//                 cout << oddCount << endl; 
//                 lastDigit /= 10;
//             }

//             holder/=10; 

//     }

//     return 0;
// }




//     while(holder <= 0){

//         holder /= 10;

//         if(input % 2 == 0){
//         for(int i = 2; i < input; i+= 2){
//             cout << i << endl; 
//         } 
//     }

//     else{
//         for(int j = 3; j < input; j+= 3){
//             cout << j << endl; 
//         }
//     }
//   }

//    return 0;
// }



    //Loop from 1 to n
    // for(int i = 1; i <= n; i++){
    //     //In loop holder for currentLoop
    //     //Variable to hold odds or evens
    //    // currentLoop++;

    //     //while(i < 0){
    //         holder % 10;
    //         if(holder % 2 == 0){
    //             evenCount++;
    //         }
    //         else{
    //             oddCount++; 
    //         }

            
    //     //}

    // }

    // if(evenCount > oddCount){
    //     cout << evenCount << endl;
    // }
    // else{
    //     cout << oddCount << endl; 
    // }

        //while Loop: While holder > 0 
            //holder % 10 for last digit
            // Check last digit even / odd

            // if - else
            // increment even / odd variable
            // divide holder / 10
        
        // Print if even > odd

        // else print "xyz"



//    return 0;
// }