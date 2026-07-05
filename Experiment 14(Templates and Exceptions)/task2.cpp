/*Write a class template Pair<T1, T2> that stores two values of potentially different types. Add 
getFirst(), getSecond(), display(), and swap() that exchanges the two values. Overload 
operator< so that one Pair is considered less than another by comparing first, and only 
comparing second if the first values are equal. Then write a free function template 
largerFirst(const Pair<T1, T2> &a, const Pair<T1, T2> &b) that returns whichever Pair has 
the larger first value. Test with at least three different type combinations. */
#include <iostream>
using namespace std;
template <class T1, class T2>
class Pair{
private:
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s){
        first = f;
        second = s;
    }
    T1 getFirst(){
        return first;
    }
    T2 getSecond(){
        return second;
    }
    void display(){
        cout << "(" << first << ", " << second << ")" << endl;
    }
    void swapValues(){
        T1 tempFirst = first;
        T2 tempSecond = second;
        first = tempFirst;  
        second = tempSecond;
    }
    bool operator<(Pair<T1, T2> &p){
        if (first < p.first)
            return true;
        else if (first == p.first && second < p.second)
            return true;
        else
            return false;
    }
};
template <class T1, class T2>
Pair<T1, T2> largerFirst(Pair<T1, T2> a, Pair<T1, T2> b){
    if (a.getFirst() > b.getFirst())
        return a;
    else
        return b;
}
int main(){
    Pair<int, int> p1(10, 20);
    Pair<int, int> p2(15, 5);

    cout << "Pair 1: ";
    p1.display();
    cout << "Pair 2: ";
    p2.display();

    cout << "Larger first (int,int): ";
    largerFirst(p1, p2).display();

    cout << endl;
    Pair<int, double> p3(5, 2.5);
    Pair<int, double> p4(5, 9.9);

    cout << "Pair 3: ";
    p3.display();
    cout << "Pair 4: ";
    p4.display();

    cout << "Larger first (int,double): ";
    largerFirst(p3, p4).display();
    cout << endl;

    Pair<char, int> p5('a', 10);
    Pair<char, int> p6('z', 1);

    cout << "Pair 5: ";
    p5.display();
    cout << "Pair 6: ";
    p6.display();

    cout << "Larger first (char,int): ";
    largerFirst(p5, p6).display();
    cout << endl;

    return 0;
}