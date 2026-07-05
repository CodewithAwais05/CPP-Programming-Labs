/*Write a generic function template void readValues(T *arr, int n, istream &is) that reads n 
values of type T from any input stream (cin or an ifstream). Wrap it in a try-catch that catches 
bad_alloc and ios_base::failure. Demonstrate reading integers from a file and strings from cin. */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
template <class T>
void readValues(T *arr, int n, istream &is){
    for (int i = 0; i < n; i++){
        is >> arr[i];
    }
}
int main(){
    int n = 5;
    try{
        int *intArr = new int[n];

        ifstream fin("numbers.txt");
        if (!fin){
            throw ios_base::failure("File not found!");
        }
        readValues(intArr, n, fin);
        cout << "Integers from file:\n";
        for (int i = 0; i < n; i++){
            cout << intArr[i] << " ";
        }
        cout << endl;
        fin.close();
        delete[] intArr;
    }
    catch (bad_alloc &e){
        cout << "Memory allocation failed: " << e.what() << endl;
    }
    catch (ios_base::failure &e){
        cout << "IO Error: " << e.what() << endl;
    }
    cout << "\n-----------------------------\n";
    try{
        int m = 3;
        string *strArr = new string[m];
        cout << "Enter 3 words:\n";

        readValues(strArr, m, cin);
        cout << "You entered:\n";
        for (int i = 0; i < m; i++){
            cout << strArr[i] << " ";
        }
        cout << endl;
        delete[] strArr;
    }
    catch (bad_alloc &e){
        cout << "Memory allocation failed: " << e.what() << endl;
    }
    catch (ios_base::failure &e){
        cout << "IO Error: " << e.what() << endl;
    }

    return 0;
}