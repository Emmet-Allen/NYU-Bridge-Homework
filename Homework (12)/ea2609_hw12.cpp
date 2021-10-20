#include <iostream>
#include <string>

using namespace std;

class Money{
    private:
    long all_cents;
    
    public:
    // Constructors
    Money() : all_cents{0} {}; 

    Money(long dollars) {  
        this->all_cents = dollars * 100; 
    }

    Money(long dollars, int cents) {
        if(dollars * cents < 0) {
            cout << "llegal input!\n";
            exit(1);
        }
        this->all_cents = dollars * 100 + (long)cents;
    }

    //Getters
    double getValue(){return this->all_cents*(0.01) ;}

    // Overloads
    // This works but the other way doesnt
        Money operator+(const Money& amount) {
        Money totalValue;
        totalValue.all_cents = this->all_cents + amount.all_cents;
        return totalValue; 

    }

    Money operator-(const Money& amount) {
        Money totalValue;
        totalValue.all_cents = this->all_cents - amount.all_cents;
        return totalValue; 
    }

    //takes all_cents and converts it to negative
    Money operator-(){
        Money negValue;
        negValue.all_cents = -(this->all_cents);
        return negValue; 
    }

    bool operator==(const Money& amount){
        return this->all_cents == amount.all_cents; 
    }

    bool operator<(const Money& amount){
        return this->all_cents < amount.all_cents; 
    }

    // istream/ostream Overloads
    friend istream& operator>>(istream& input, Money& amount);
    friend ostream& operator<<(ostream& output, const Money& amount);

    // Value Getter
    double get_value() const{return this->all_cents * (0.01); }
    
};

class Check{
    private:
    int id;
    bool cashed;
    Money checkAmount; 

    public:
    //Constructors
    Check () {}

    //Setters
    void setId(int newId) {id = newId;}

    // We are using amount from the Money Class to set the checkAmount. 
    void setAmount(Money amount) {this->checkAmount = amount;} 


    void setCashed(bool ifCashed){
        cashed = ifCashed;
    }

    //Getters
    int getId() {return this->id;}
    bool getCashed() {return this->cashed;}
    Money getCheckAmount() {return this->checkAmount;}

    //Overloaders... Type this up and take a break
    friend istream& operator>>(istream& input, Check& randCheck);
    friend ostream& operator<<(ostream& output, Check& randCheck);


};

int main(){
    // Ask for number of checks to push through loop
    // Push checks into 'check vector' 
    // Ask for number of deposits,  'Money totalDeposit' , 'Money totalCashedChecks'
    
    // 2 loops:
    // In cashedCheck input, sum up with totalCashedChecks
    // With total deposits, sum up with totalDeposits

    //For loop that prints out all checks cashed
    // Another for loop that prints out all checks uncashed




    Money b(10,20);

return 0;
}

istream& operator>>(istream& input, Money& amount){
    char firstDig, secondDig, decimal, leadingChar;  
    bool negative = false; 
    long dollars;
    int cents, firstCents, secondCents;

    input >> leadingChar; 
    if(leadingChar == '-'){
        negative = true; 
        input >> leadingChar; 
    }
    input >> dollars >> decimal >> firstDig >> secondDig; 

    if(leadingChar != '$' || decimal != '.' || !isdigit(firstDig) || !isdigit(secondDig) ){
        cout << "Not valid" << endl;
        exit(1);
    }

    firstCents = firstDig - '0';
    secondCents = secondDig - '0';

    cents = (firstCents * 10) + secondCents;
    amount.all_cents = (dollars * 100) + cents; 

    if(negative == true){
        amount = -(amount);
    }

    return input;
}

ostream& operator<<(ostream& output, const Money& amount) {
   long absolute_cents, dollars, cents;
   absolute_cents = labs(amount.all_cents);
   dollars = absolute_cents / 100;
   cents = absolute_cents % 100;

    if(amount.all_cents < 0){
        output << '-';
    }
    output << "$" << dollars << '.' << cents; 

    if(cents < 10){
        output << "0";
    }
    output << cents;

    return output;
}

istream& operator>>(istream& input, Check& randCheck){
    input >> randCheck.id >> randCheck.checkAmount >> randCheck.cashed;
    return input;
}

ostream& operator<<(ostream& output, Check& randCheck) {
    output << randCheck.getId() << randCheck.getCheckAmount() << randCheck.getCashed();
    return output;
}