/*Create a Complex class representing a complex number (real and imaginary parts). Overload 
+, -, and * for arithmetic. Overload << and >> for stream I/O. Write a main() that reads two 
complex numbers, performs all three operations, and displays the results.*/
#include<iostream>
using namespace std;
class Complex{
    private:
        double real;
        double imaginary;
    public:
        Complex(){
            real = 0;
            imaginary = 0;
        }
        Complex operator + (Complex C){
            Complex temp;
            temp.real = real + C.real;
            temp.imaginary = imaginary + C.imaginary;
            return temp;
        }
        Complex operator - (Complex C){
            Complex temp;
            temp.real = real - C.real;
            temp.imaginary = imaginary - C.imaginary;
            return temp;
        }
        Complex operator * (Complex C){
            Complex temp;
            temp.real = (real * C.real) - (imaginary * C.imaginary);
            temp.imaginary = (real * C.imaginary) + (imaginary * C.real);
            return temp;
        }

        friend istream& operator >>(istream& in, Complex& C);
        friend ostream& operator <<(ostream& out, const Complex& C);
};
istream& operator >>(istream& in,  Complex& C){
    cout << "Enter real part:  ";
    in >> C.real;
    cout << "Enter imaginary part:  ";
    in >> C.imaginary;
    return in;
}
ostream& operator <<(ostream& out, const Complex& C){
    out << C.real;
    if (C.imaginary >= 0)
        out << " + " << C.imaginary << "i";
    else
        out << " - " << -C.imaginary << "i";
    return out;
}
int main(){
    Complex c1, c2, result;
    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "\nEnter second complex number:\n";
    cin >> c2;
    
    result = c1 + c2;
    cout << "\nAddition: " << result << endl;

    result = c1 - c2;
    cout << "Subtraction: " << result << endl;

    result = c1 * c2;
    cout << "Multiplication: " << result << endl;

    return 0;
}