/*Write a function template T minimum(T a, T b, T c) that returns the smallest of three values. 
Test it with int, double, and char. Also write sort3(T &a, T &b, T &c) that sorts the three 
values in ascending order. */
#include <iostream>
using namespace std;
template <class T>
T minimum(T a, T b, T c){
    if (a <= b && a <= c){
        return a;
    }
    else if (b <= a && b <= c){
        return b;
    }
    else{
        return c;
    }
}
template <class T>
void sort3(T &a, T &b, T &c){
    T temp;
    if (a > b){
        temp = a;
        a = b;
        b = temp;
    }
    if (a > c){
        temp = a;
        a = c;
        c = temp;
    }
    if (b > c){
        temp = b;
        b = c;
        c = temp;
    }
}
int main(){
    int i1 = 30, i2 = 10, i3 = 20;

    cout << "Int minimum: " << minimum(i1, i2, i3) << endl;
    sort3(i1, i2, i3);
    cout << "Sorted ints: " << i1 << " " << i2 << " " << i3 << endl;
    cout << endl;

    double d1 = 5.5, d2 = 2.2, d3 = 9.1;
    cout << "Double minimum: " << minimum(d1, d2, d3) << endl;
    sort3(d1, d2, d3);
    cout << "Sorted doubles: " << d1 << " " << d2 << " " << d3 << endl;
    cout << endl;

    char c1 = 'z', c2 = 'a', c3 = 'm';
    cout << "Char minimum: " << minimum(c1, c2, c3) << endl;
    sort3(c1, c2, c3);
    cout << "Sorted chars: " << c1 << " " << c2 << " " << c3 << endl;

    return 0;
}