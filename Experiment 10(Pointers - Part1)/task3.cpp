/*Write a function void sortAscending(int *arr, int n) using pointer notation exclusively 
(*(arr+i) instead of arr[i]). Test it on eight user-entered integers. Then write a second function 
to binary-search the sorted array.*/
#include <iostream>
using namespace std;
void sortAscending(int *arr, int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (*(arr + j) > *(arr + j + 1)){
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}
int binarySearch(int *arr, int n, int key){
    int low = 0, high = n - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (*(arr + mid) == key){
            return mid;
        }
        else if (*(arr + mid) < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[8];
    cout << "Enter 8 integers:\n";
    for (int i = 0; i < 8; i++){
        cin >> *(arr + i);
    }
    sortAscending(arr, 8);
    cout << "\nSorted Array:\n";
    for (int i = 0; i < 8; i++){
        cout << *(arr + i) << " ";
    }
    int key;
    cout << "\n\nEnter number to search: ";
    cin >> key;
    int result = binarySearch(arr, 8, key);
    if (result != -1){
        cout << "Element found at index " << result << endl;
    }
    else{
        cout << "Element not found" << endl;
    }
    
    return 0;
}