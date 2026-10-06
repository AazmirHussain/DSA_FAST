#include <iostream>
#include <string>
using namespace std;

class StdRecord{
    int rollNumber;
    string name;
    bool isOccupied;

public:
    StdRecord(): rollNumber(-1), isOccupied(false){}
    
    int getRollNumber(){return rollNumber;}
    string getName(){ return name;}
    bool getIsOccupied(){ return isOccupied;}
    
    void setRecord(int roll, string Name){
        rollNumber = roll;
        name = Name;
        isOccupied = true;
    }
};

class Stdtable{
    static const int TABLE_SIZE = 15;
    StdRecord table[TABLE_SIZE];
    
    int hashFunction(int rollNumber){return rollNumber % TABLE_SIZE;}

public:
    void InsertRecord(int rollNumber, string name){
        int index = hashFunction(rollNumber);
        int attempt = 0;
        
        while (attempt < TABLE_SIZE){
            int probeIndex = (index + attempt * attempt) % TABLE_SIZE;
            
            if (!table[probeIndex].getIsOccupied()){
                table[probeIndex].setRecord(rollNumber, name);
                cout << "Record inserted successfully at index " << probeIndex << endl;
                return;
            }
            attempt++;
        }
        
        cout << "Hash table is full. Cannot insert record." << endl;
    }
    
    void SearchRecord(int rollNumber){
        int index = hashFunction(rollNumber);
        int attempt = 0;
        
        while (attempt < TABLE_SIZE){
            int probeIndex = (index + attempt * attempt) % TABLE_SIZE;
            
            if (!table[probeIndex].getIsOccupied()){break;}
            
            if (table[probeIndex].getRollNumber() == rollNumber && table[probeIndex].getIsOccupied()) {
                cout << "Record found: Roll Number " << rollNumber << ", Name: " << table[probeIndex].getName() << endl;
                return;
            }
            attempt++;
        }
        
        cout << "Record not found for roll number " << rollNumber << endl;
    }
    
    void DisplayTable(){
        cout << "\nHash Table Contents:" << endl;
        cout << "Index\tRoll Number\tName\t\tStatus" << endl;
        cout << endl << endl;
        for (int i = 0; i < TABLE_SIZE; i++){cout << i << "\t";
            if (table[i].getIsOccupied()){
                cout << table[i].getRollNumber() << "\t\t" << table[i].getName() << "\t\tOccupied";} 
            else{cout << "-\t\t-\t\tEmpty";}
            cout << endl;
        }
        cout << endl << endl;
    }
};

int main(){
    Stdtable studentDB;
    
    cout << " Student Record Management System " << endl;
    
    studentDB.InsertRecord(101, "Alice");
    studentDB.InsertRecord(115, "Bob");
    studentDB.InsertRecord(116, "Charlie");
    studentDB.InsertRecord(102, "Diana");
    studentDB.InsertRecord(131, "Eve");
    studentDB.InsertRecord(146, "Frank");
    
    cout << "\n Searching Records " << endl;
    studentDB.SearchRecord(101);
    studentDB.SearchRecord(115);
    studentDB.SearchRecord(116);
    studentDB.SearchRecord(200);
    
    cout << "\n Displaying Hash Table " << endl;
    studentDB.DisplayTable();
    
    return 0;
}