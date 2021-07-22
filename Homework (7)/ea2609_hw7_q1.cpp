#include<iostream>


using namespace std;


int printMonthCalender(int numOfDays, int startingDay);
bool isLeapYear (int year); 
void printYearCalender(int year, int startingDay);

int main(){
int numOfDays,startingDay, lastDay;
int year; 

// cout << "Please enter the amount of days in the month, and the starting day: ";
// cin >> numOfDays;
// cin >> startingDay; 

// lastDay = printMonthCalender(numOfDays, startingDay);
// cout << endl;
// cout << lastDay;

   cout << "Please enter the year number, and the starting day: ";
   cin >> year >> startingDay; 

 printYearCalender(year, startingDay);

 return 0;
}

int printMonthCalender(int numOfDays, int startingDay){
//Calendar Days
   for (int day = 1; day <= 7; day++){
       switch (day)
       {
       case 1:
           cout << "Mon" << '\t'; 
           break;
       case 2:
           cout << "Tue" << '\t'; 
           break;
       case 3:
           cout << "Wed" << '\t'; 
           break;
       case 4:
           cout << "Thr" << '\t'; 
           break;
       case 5:
           cout << "Fri" << '\t'; 
           break;
       case 6:
           cout << "Sat" << '\t'; 
           break;
       case 7:
           cout << "Sun" <<'\t'; 
           break;       
       default:
           break;
       }
          }

          cout << endl;

int spaces = 1;
int number = 1;
int currentDay;

        for(number = 1; number <= numOfDays; number++){

                    while(startingDay > spaces){
                    spaces++;
                    cout << " " << '\t';
                    }


                if(startingDay + number < 7){
                    cout << number << '\t';
                 }
                 // Lol idk why this works... neither do like 4 other people
                else if( (startingDay + number - 1) % 7 == 0){
                    cout << number << endl; 
                  }
                else{
                    cout << number << '\t';
                 }

        
    }
    if  ( (startingDay + number - 2) % 7 == 0 ){
        return 7;
    }
    else{
        return ( (startingDay + number - 2) % 7);
    }
}


bool isLeapYear (int year){
int leapyear; 

    if( (leapyear % 4 == 0 && leapyear % 100 != 0) || leapyear % 400 == 0 ){
        return true;
    }
    else{
        return false; 
    }
}


void printYearCalender(int year, int startingDay){
bool leapYear = isLeapYear (year); 
int lastDay, month;

for(month = 1; month <= 12; month++){
           
       switch (month)
       {
       case 1:
           cout << "January " << year << endl; 
            lastDay = printMonthCalender(31, startingDay);
            cout << endl;
           break;
       case 2:
           cout << "Feburary " << year << endl; 
           if(leapYear == true){
            lastDay =  printMonthCalender(29, lastDay + 1);
            cout << endl;
           }
           else{
             cout << endl;
             lastDay = printMonthCalender(28, lastDay + 1);
            cout << endl;
           }
           break;
       case 3:
           cout << endl;
           cout << "March " << year << endl; 
           lastDay = printMonthCalender(31, lastDay + 1);
            cout << endl;
           break;
       case 4:
           cout << endl;
           cout << "April " << year << endl; 
           lastDay = printMonthCalender(30, lastDay + 1);
            cout << endl;
           break;
       case 5:
           cout << endl;
           cout << "May " << year << endl; 
            lastDay =printMonthCalender(31, lastDay + 1);
             cout << endl;
           break;
       case 6:
           cout << endl;
           cout << "June " << year << endl; 
           lastDay = printMonthCalender(30, lastDay + 1);
            cout << endl;    
           break;
       case 7:
           cout << endl;
           cout << "July " << year << endl; 
           lastDay = printMonthCalender(31, lastDay + 1);
            cout << endl;
           break;       
       case 8:
           cout << endl;
           cout << "August " << year << endl; 
           lastDay = printMonthCalender(31, lastDay + 1);
            cout << endl;
           break; 
       case 9:
           cout << endl;
           cout << "September " << year << endl; 
           lastDay = printMonthCalender(30, lastDay + 1);
            cout << endl;
           break;      
       case 10:
           cout << endl;
           cout << "October " << year << endl; 
           lastDay = printMonthCalender(31, lastDay + 1);
            cout << endl;
           break;      
       case 11:
           cout << endl;
           cout << "November " << year << endl; 
           lastDay = printMonthCalender(30, lastDay + 1);
            cout << endl;
           break;      
       case 12:
           cout << endl;
           cout << "December " << year << endl; 
          lastDay =  printMonthCalender(31, lastDay + 1);
            cout << endl;
           break;      
       default:
           break;
       }
    }
}

