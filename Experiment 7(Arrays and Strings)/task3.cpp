/*Write a program that reads a sentence (up to 10 words) from the user into an array of C++ 
string objects. Without using any library sort or container beyond a plain array, sort the words 
alphabetically using your own comparison loop, then remove any duplicate words (case
insensitive) while preserving the sorted order, and print the final deduplicated, sorted word list 
together with a count of how many duplicates were removed. */
#include <iostream>
#include <string>
using namespace std;
int main(){
    string words[10];
    int n;
    cout << "How many words do you want to enter (max 10)? ";
    cin >> n;
    cout << "Enter the words:\n";
    for (int i = 0; i < n; i++){
        cin >> words[i];
    }
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (words[j] > words[j + 1]){
                string temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
    string unique[10];
    int uniqueCount = 0;
    int duplicateCount = 0;
    for (int i = 0; i < n; i++){
        bool found = false;
        for (int j = 0; j < uniqueCount; j++){
            if (words[i] == unique[j]){
                found = true;
                duplicateCount++;
                break;
            }
        }
        if (!found){
            unique[uniqueCount] = words[i];
            uniqueCount++;
        }
    }
    cout << "\nSorted Unique Words:\n";
    for (int i = 0; i < uniqueCount; i++){
        cout << unique[i] << " ";
    }
    cout << "\nDuplicates Removed: " << duplicateCount << endl;

    return 0;
}