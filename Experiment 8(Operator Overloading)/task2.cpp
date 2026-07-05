/*Extend the Fraction class from the theory section to support addition, subtraction, 
multiplication, and division. Each operation should reduce the result to lowest terms using the 
GCD. Overload << for output. Test with at least six fraction pairs. */
#include <iostream>
using namespace std;
class Fraction{
private:
    int num;
    int den;
    int gcd(int a, int b){
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    void reduce(){
        int g = gcd(num, den);
        num = num / g;
        den = den / g;
        if (den < 0){
            num = -num;
            den = -den;
        }
    }
public:
    Fraction(int n = 0, int d = 1){
        num = n;
        den = d;
        reduce();
    }
    Fraction operator+(Fraction f){
        Fraction temp;
        temp.num = num * f.den + f.num * den;
        temp.den = den * f.den;
        temp.reduce();
        return temp;
    }
    Fraction operator-(Fraction f){
        Fraction temp;
        temp.num = num * f.den - f.num * den;
        temp.den = den * f.den;
        temp.reduce();
        return temp;
    }
    Fraction operator*(Fraction f){
        Fraction temp;
        temp.num = num * f.num;
        temp.den = den * f.den;
        temp.reduce();
        return temp;
    }
    Fraction operator/(Fraction f){
        Fraction temp;
        temp.num = num * f.den;
        temp.den = den * f.num;
        temp.reduce();
        return temp;
    }
    friend ostream& operator<<(ostream& out, Fraction f);
};
ostream& operator<<(ostream& out, Fraction f){
    out << f.num << "/" << f.den;
    return out;
}
int main(){
    Fraction f1(1, 2), f2(1, 3);
    Fraction f3(2, 5), f4(3, 7);
    Fraction f5(5, 6), f6(2, 9);

    cout << "----------Test 1:----------\n";
    cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
    cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;
    cout << f1 << " * " << f2 << " = " << (f1 * f2) << endl;
    cout << f1 << " / " << f2 << " = " << (f1 / f2) << endl;

    cout << "\n----------Test 2:----------\n";
    cout << f3 << " + " << f4 << " = " << (f3 + f4) << endl;
    cout << f3 << " - " << f4 << " = " << (f3 - f4) << endl;
    cout << f3 << " * " << f4 << " = " << (f3 * f4) << endl;
    cout << f3 << " / " << f4 << " = " << (f3 / f4) << endl;

    cout << "\n----------Test 3:----------\n";
    cout << f5 << " + " << f6 << " = " << (f5 + f6) << endl;
    cout << f5 << " - " << f6 << " = " << (f5 - f6) << endl;
    cout << f5 << " * " << f6 << " = " << (f5 * f6) << endl;
    cout << f5 << " / " << f6 << " = " << (f5 / f6) << endl;

    return 0;
}