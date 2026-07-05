/*Write three overloaded functions all named printInfo. The first accepts an int and prints 
"Integer: <value>". The second accepts a double and prints "Double: <value>". The third 
accepts a string and prints "String: <value>". Call each version from main().*/
#include<iostream>
using namespace std;
void printInfo(int num){
    cout << "Integer:  " << num << endl;
}
void printInfo(double num){
    cout << "Double:  " << num << endl;
}
void printInfo(string n){
    cout << "String:  " << n << endl;
}
int main(){
    printInfo(6);
    printInfo(7654.346);
    printInfo("Awais");
    return 0;
}