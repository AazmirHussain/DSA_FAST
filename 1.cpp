#include<iostream>
using namespace std;

class BankAccount{
    double balance;
public:
    BankAccount() : balance(0.0){
        cout << "Initial balance is: $" << balance << endl;
    }
    BankAccount(double a): balance(a){
        cout << "Current balance is: $" << balance << endl;
    }
    BankAccount(BankAccount& b): balance(b.balance){
        cout << "Amount copied is: $" << balance << endl;
    }

    void withdraw(double amt){
        if(balance > amt){
            balance -= amt;
            cout << "Amount withdrawn: $" << amt << endl;
            cout << "New Balance is: $" << balance << endl;
        }
        else{
            cout << "Insufficient Balance!" << endl;
        }
        cout << endl;
    }

    double getbalance(){return balance;} 
    void display(string acct){
        cout << "Balance in "<< acct << " is: $" << balance << endl;
    }
};

int main(){
    BankAccount account1;
    account1.display("account1");
    cout << endl;

    BankAccount account2(999.99);
    account2.display("account2");
    cout << endl << endl;

    BankAccount account3(account2);
    account2.display("account2");
    account3.display("account3");
    cout << endl;

    account3.withdraw(77777);
    account2.display("account2");
    account3.display("account3");
    cout << endl;

    account3.withdraw(245.56);
    account2.display("account2");
    account3.display("account3");
    cout << endl;

    return 0;
}