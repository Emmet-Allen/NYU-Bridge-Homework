#include <iostream>
#include <cmath>

using namespace std; 

//Input: A postive number (M) greater than 2
//Output #1: All perfect numbers between 2 and that number (M)
//Output #2: All pairs of amicable numbers that are between 2 and M

//For Output #1: We can loop from 2 to M, the loop will loop through the anaylze dividors function
// We can then pass the loop iteration from each number between 2 to M and have it check if its a perfect number or not. 

//For Output #2: We would need some type of holder, that would hold the value of the sumDivs,
// We would then compare the value of sumDivs to a future number... I think? 


void anaylzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main(){
    int num, countDivs, sumDivs; 
    int i, j, temp, secondTemp; 
   

    cout << "Please enter a number greater than 2: ";
    cin >> num;

    for (i = 2; i <= num; i++){ 
        anaylzeDividors(i, countDivs, sumDivs);
        


         bool perfectNum = isPerfect(i);
            if(perfectNum == true){
            cout << i << " is a perfect number. " << endl; 
            }
    }

        //Iterate from 2 to M , save i in a temp variable, 
        // Call anaylzeDividors(i, countDivs, temp) because we are saving the sum of the divisors into temp 
        // Check if temp > i && temp <= M, because we want to print the pair once 
            //secondTemp to save the sum of the divisors in the first temp 
            //Call anaylzeDividors(firstTemp, count, secondTemp)
            //if secondtemp = i, then i and firstemp are a pair 

    for(i  = 2; i <= num; i++){
        temp = i;
        anaylzeDividors(i, countDivs, temp);

        if(temp > i && temp <= num){
            anaylzeDividors(temp, countDivs, secondTemp);
            if(secondTemp = i){
                cout << i << " and " << temp << " are an amicable pair." << endl;
            }
        }

    }


    return 0;
}

void anaylzeDividors(int num, int& outCountDivs, int& outSumDivs){
int firstOutCounter = 0, firstSumCounter = 0, secondOutCounter = 0, secondSumCounter = 0; 
    
    //Lower Half Divisors
    for (int i = 1; i <= sqrt(num); i++){
        if(num % i == 0){
            firstOutCounter++;
            firstSumCounter += i;
        }
    }
    //Upper Half Divisiors 
        for(int i = sqrt(num); i > 1; i--){
        if(num % i == 0){
            secondOutCounter++;
            //We need to get the upper sum of these numbers by dividing the number by the value of i
            secondSumCounter += num / i;
        }
    }

    outCountDivs = firstOutCounter + secondOutCounter;
    outSumDivs = firstSumCounter + secondSumCounter; 
}

bool isPerfect(int num){
int countDivs, sumDivs; 
// Re-use the anaylzeDividors function
anaylzeDividors(num, countDivs, sumDivs);

    //If the input number is equal to the sum of its dividors, it is a perfect number
   if(num == sumDivs){
        return true;
    }
    // Otherwise it is not
    else{
        return false; 
    }

}