#include <iostream> 
#include <cmath> 


using namespace std;
int main (){

    int d,q,m,r,exponent; 

    cout << "Enter a decimal number:"<< endl;
    cin >> d;
     
    cout << endl;

    cout << "The number " << d << " in binary is: ";

    //Assign d to q to avoid input tampering
     q = d;

    //Intalize exponent
     exponent = 0;

     //Intalize remainder
     r = 0;        

    //Find largest expoenent and doing that by dividing by 2 until 0;
    if(q == 0){
        cout << 0;
    }
    
    // When quotient is greater than 0, increase exponent by 1 and divide quotient by 2 and re-assign until q is less than 0
    while(q > 0){
        exponent += 1; 
        q /= 2; 
    }

    // Starting from most sig.fig. bit to least sig.fig. bit
    for(int i = exponent - 1; i >= 0;i--){
        
    //divide by the power of 2 ^ i to get either 0 or 1
        int a = d/(int)pow(2.0, i);
        cout << a; 
    // mod by the power of 2 ^ i to get the next number
        d %= (int)pow(2, i);  
    }
    
    return 0;

}