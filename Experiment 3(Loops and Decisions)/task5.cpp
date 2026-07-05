/*Write a program that plays a number-guessing game. The program picks a secret number (you 
can hard-code it as 42). The user keeps guessing; the program responds "Too high", "Too 
low", or "Correct!" and counts the number of attempts before the correct guess.*/
#include<iostream>
using namespace std;
int main(){
    int secret = 42;
    int guess;
    int attempt_count = 0;
    while(true){
        cout << "Enter your Guess:  ";
        cin >> guess;
        attempt_count++;
        if(guess > secret){
            cout << "Too high\n";
        }
        else if(guess < secret){
            cout << "Too low\n";
        }
        else{
            cout << "Correct!!\n";
            break;
        }
    }
    cout << "Total Attempts:  " << attempt_count << endl;
    return 0;
}