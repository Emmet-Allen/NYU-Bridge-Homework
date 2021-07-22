#include <iostream>
#include <cmath>

using namespace std;

int main (){

    int sequenceInput, Numbers, counter = 0;
    float geoMean, rootValue = 1.0, nthRoot;

    cout << "Version A" << endl;

    cout << "Please enter the length of the sequence: ";
    cin >> sequenceInput;
    cout << "Please enter the sequence: " << endl;

    do{
        
        counter++; 
        cin >> Numbers;
        
        rootValue *= Numbers; 

        
    }
    while(counter < sequenceInput);

    geoMean = pow( (rootValue), (1 / (double)sequenceInput) );
    cout << "The geometric mean is: " << geoMean << endl; 
    
    cout << "Version B" << endl; 
    cout << "Please enter the sequence: " << endl;

    // Reset Counter
    counter = 0;

    //Reset rootValue
    rootValue = 1.0;

    //Reset geoMean
    geoMean = 0;

    //Use a do-while loop, so that user input is assigned atleast once
        do{
        
        //Increament a counter to get the number of inputs
        counter++; 
        cin >> Numbers;
        
        // Multiply each input and assign it to the root value
        rootValue *= Numbers; 

        
    }
    //Continue the loop until user inputs -1
    while(Numbers != -1);

    // Use the negative root value to so that we can take into account the subtraction of the counter value.
    //We don't include the -1 to the counter because we do not include the stop input (-1)
    geoMean = pow( -rootValue, ( 1 / (double) (counter - 1)) );
    cout << "The geometric mean is: " << geoMean; 

    return 0;
}