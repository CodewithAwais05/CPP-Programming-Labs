/*Write a program that reads an integer n and prints a full n x n multiplication table, formatted 
with setw(4) for each cell so that columns align properly.*/

#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int num;
    cout << "Enter any number:  ";
    cin >> num;
    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= num; j++){
            cout << setw(4) << i*j;
        }
        cout << endl;
    }
}