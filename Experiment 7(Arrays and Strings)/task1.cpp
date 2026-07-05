/*Write a program that reads 10 integers into an array. Without using any library sort, find and 
print the maximum, minimum, and average. Also print the array sorted in ascending order 
using bubble sort. */
#include<iostream>
using namespace std;
int main(){
    int arr[10];
    cout << "Enter 10 integers:  ";
    for(int i = 0; i < 10; i++){
        cin >> arr[i];
    }
    int max = arr[0];
    int min = arr[0];
    int sum = 0;
    for(int i = 0; i < 10; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
        sum += arr[i];
    }
    double avg = sum/10.0;
    cout << "Maximum element:  " << max << endl;
    cout << "Minimum element:  " << min << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "\n----------Sorted Array----------\n";
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " " ;
    }
}