/* Write a program that reads 10 integers and prints the count of positive values, negative values, 
and zeros. Also print the largest and smallest values entered. */

#include<iostream>
using namespace std;
int main(){
    int num;
    int pos = 0, neg = 0, zero = 0;
    int large, small;
    for(int i = 0; i < 10; i++){
        cout << "Enter " << i+1 << " Number:  ";
        cin >> num;
        if(i == 0){
            large = small = num;
        }
        if(num > 0){
            pos++;
        }
        else if(num < 0){
            neg++;
        }
        else {
            zero++;
        }

        if(num > large){
            large = num;
        }

        if(num < small){
            small = num;
        }
    }
    cout << "Smallest:  " << small << "\nLargest:  " << large << endl;
    cout << "Positive:  " << pos << "\tNegative:  " << neg << "\tZero:  " << zero << endl;

}