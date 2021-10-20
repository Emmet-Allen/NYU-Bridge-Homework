//Overloading operators.
// Linked List Class.
// Templated. Push Front, Push Back, Clear List 
// Merged Sort

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Employee{
private:

string name;
int id;
double payRate; 
int hours; 
// May not be necesscary
double salary;

public: 
Employee(int _id = 0, string _name = "NA", double _payRate=0.00, int _hours=0): id(_id), name(_name), payRate(_payRate), hours(_hours){};

void setId(int sId){
    id = sId; 
}

void setName(string sName){
    name = sName;
}

void setPayRate(double sPayRate){
    payRate = sPayRate; 
}

void setHours(int sHours){
    hours = sHours;
}

int getID(){
    return id;
}

string getName(){
    return name;
}

double getPayRate(){
    return payRate; 
}

int getHours(){
    return hours; 
}

};

template <class T>
class LListNode{
private:
    T data;
    LListNode<T>* next;
public:
    LListNode(T newData = T(), LListNode<T>* newNext = nullptr) : data(newData), next(newNext) {}
    friend class LList<T>*; 
};

void openInputFile(ifstream& inFile){
    string filename;
    cout << "Please enter the first file:";
    cin >> filename;
    inFile.open(filename);
    while(!inFile){
        cout << "Bad file, please retry." << endl;
        cout << "Please enter the first file:";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    } 
}

void openInputFile2(ifstream& inFile2){
    string filename;
    cout << "Please enter the second file:";
    cin >> filename;
    inFile2.open(filename);
    while(!inFile2){
        cout << "Bad file, please retry." << endl;
        cout << "Please enter the second file:";
        cin >> filename;
        inFile2.clear();
        inFile2.open(filename);
    }
}


int main(){
    vector<Employee> vecEmp;
    ifstream inFile, inFile2;
    Employee temp;
    string tempName;
    int tempID; 
    
    openInputFile(inFile);
    openInputFile2(inFile2);


    return 0;
}