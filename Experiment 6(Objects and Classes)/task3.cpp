/*Extend the BankAccount class with three static members: count (active accounts), 
totalDeposited, and totalWithdrawn (running totals across all accounts). Update count in the 
constructor and destructor, and update the two totals inside deposit() and withdraw() 
respectively. Add static functions BankAccount::getCount(), 
BankAccount::getTotalDeposited(), and BankAccount::getTotalWithdrawn(). Create and 
destroy several accounts inside a nested scope, performing multiple deposits and withdrawals, 
and print all three static values before and after the scope ends to prove they update correctly 
and persist independently of any single object.*/
#include <iostream>
#include <string>
using namespace std;
class BankAccount{
private:
    string owner;
    double balance;
    static int count;
    static double totalDeposited;
    static double totalWithdrawn;
public:
    BankAccount(string o, double b){
        owner = o;
        balance = b;
        count++;
    }
    ~BankAccount(){
        count--;
    }
    void deposit(double amount){
        balance += amount;
        totalDeposited += amount;
    }
    void withdraw(double amount){
        if (amount <= balance){
            balance -= amount;
            totalWithdrawn += amount;
        }
        else{
            cout << "Insufficient funds for " << owner << endl;
        }
    }
    double getBalance() const{
        return balance;
    }
    void display() const{
        cout << "Owner: " << owner << endl;
        cout << "Balance: " << balance << endl;
    }
    static int getCount(){
        return count;
    }
    static double getTotalDeposited(){
        return totalDeposited;
    }
    static double getTotalWithdrawn(){
        return totalWithdrawn;
    }
};

int BankAccount::count = 0;
double BankAccount::totalDeposited = 0;
double BankAccount::totalWithdrawn = 0;

int main(){
    cout << "Before Nested Scope" << endl;
    cout << "Active Accounts: " << BankAccount::getCount() << endl;
    cout << "Total Deposited: " << BankAccount::getTotalDeposited() << endl;
    cout << "Total Withdrawn: " << BankAccount::getTotalWithdrawn() << endl;
    cout << "\n-----------------Entering Nested Scope...-----------------\n" << endl;
    {
        BankAccount acc1("Ali", 5000);
        BankAccount acc2("Ahmed", 7000);
        BankAccount acc3("Sara", 10000);

        acc1.deposit(1000);
        acc1.withdraw(500);

        acc2.deposit(2000);
        acc2.withdraw(1000);

        acc3.deposit(3000);
        acc3.withdraw(1500);

        cout << "-----------------Inside Nested Scope-----------------" << endl;
        cout << "Active Accounts: " << BankAccount::getCount() << endl;
        cout << "Total Deposited: " << BankAccount::getTotalDeposited() << endl;
        cout << "Total Withdrawn: " << BankAccount::getTotalWithdrawn() << endl;
    }

    cout << "\n-----------------After Nested Scope-----------------" << endl;
    cout << "Active Accounts: " << BankAccount::getCount() << endl;
    cout << "Total Deposited: " << BankAccount::getTotalDeposited() << endl;
    cout << "Total Withdrawn: " << BankAccount::getTotalWithdrawn() << endl;

    return 0;
}