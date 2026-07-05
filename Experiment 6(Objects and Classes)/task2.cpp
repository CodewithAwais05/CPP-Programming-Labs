/*Design a BankAccount class with private members owner (string) and balance (double). Add: 
a parameterized constructor, void deposit(double amount), void withdraw(double amount) 
that rejects the transaction if funds are insufficient, double getBalance() const, and void 
display() const. */
#include <iostream>
#include <string>
using namespace std;
class BankAccount{
private:
    string owner;
    double balance;
public:
    BankAccount(string name, double initialBalance){
        owner = name;
        balance = initialBalance;
    }
    void deposit(double amount){
        if (amount > 0){
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
        else{
            cout << "Invalid deposit amount!" << endl;
        }
    }
    void withdraw(double amount){
        if (amount <= 0){
            cout << "Invalid withdrawal amount!" << endl;
        }
        else if (amount > balance){
            cout << "Transaction failed: Insufficient funds!" << endl;
        }
        else{
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }
    double getBalance() const{
        return balance;
    }
    void display() const{
        cout << "Owner   : " << owner << endl;
        cout << "Balance : " << balance << endl;
    }
};

int main()
{
    BankAccount acc("Awais", 1000.0);
    cout << "===== Initial Account Details =====\n";
    acc.display();

    acc.deposit(500);
    acc.withdraw(300);
    acc.withdraw(1500);

    cout << "\n===== Final Account Details =====\n";
    acc.display();

    cout << "\nCurrent Balance: " << acc.getBalance() << endl;

    return 0;
}