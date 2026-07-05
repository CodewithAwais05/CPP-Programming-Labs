/*Write a program that prints the first n Fibonacci numbers, where n is entered by the user. The 
series starts: 0, 1, 1, 2, 3, 5, 8 ...*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter any number:  ";
    cin >> n;
    int first = 0, second = 1, next;
    for(int i = 1; i <= n; i++){
        if(i == 1){
            cout << first << "\t";
        }
        else if(i == 2){
            cout << second << "\t";
        }
        else{
            next = first + second;
            cout << next << "\t";
            first = second;
            second = next;
        }
    }
    return 0;
}