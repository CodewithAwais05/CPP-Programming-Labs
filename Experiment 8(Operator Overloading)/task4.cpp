/*Add prefix and postfix -- operators to the Counter class from the theory section. Implement 
operator< by comparing the underlying count, then implement operator<=, operator>, and 
operator>= by reusing operator< and operator== rather than re-implementing the comparison 
logic from scratch. Create two Counter objects, decrement one of them in a loop using both 
prefix and postfix forms, and use all four relational operators between the two objects to print 
a step-by-step comparison at each iteration. */
#include <iostream>
using namespace std;
class Counter{
private:
    int count;
public:
    Counter(int c = 0){
        count = c;
    }
    int getCount() const{
        return count;
    }
    Counter operator--(){
        --count;
        return *this;
    }
    Counter operator--(int){
        Counter temp = *this;
        count--;
        return temp;
    }
    bool operator<(Counter c){
        return count < c.count;
    }
    bool operator==(Counter c){
        return count == c.count;
    }
    bool operator<=(Counter c){
        return (*this < c) || (*this == c);
    }
    bool operator>(Counter c){
        return !(*this <= c);
    }
    bool operator>=(Counter c){
        return !(*this < c);
    }
};
int main(){
    Counter c1(5);
    Counter c2(3);

    cout << "Initial Values:\n";
    cout << "c1 = " << c1.getCount() << endl;
    cout << "c2 = " << c2.getCount() << endl;

    cout << "\nStep-by-step comparison while decrementing c1:\n\n";

    for (int i = 0; i < 5; i++){
        cout << "Iteration " << i + 1 << endl;
        cout << "c1 = " << c1.getCount() << ", c2 = " << c2.getCount() << endl;
        cout << "c1 < c2  : " << (c1 < c2) << endl;
        cout << "c1 <= c2 : " << (c1 <= c2) << endl;
        cout << "c1 > c2  : " << (c1 > c2) << endl;
        cout << "c1 >= c2 : " << (c1 >= c2) << endl;
        if (i % 2 == 0)
            --c1;
        else
            c1--;
        cout << "After decrement, c1 = " << c1.getCount() << "\n\n";
    }

    return 0;
}