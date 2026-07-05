/*Create a four-class hierarchy: Shape (base), Circle, Rectangle, and Triangle (each derived 
from Shape). Shape has a protected string colour. Circle adds double radius; Rectangle adds 
double length and width; Triangle adds three side lengths and computes its area with Heron's 
formula. Each derived class overrides a method double area() const. Create an array of at least 
five shapes of mixed types, then sort the array by area in descending order using your own 
sorting loop (no library sort) before printing the sorted list with each shape's colour and area. */
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
class Shape {
protected:
    string colour;
public:
    Shape(string c) {
        colour = c;
    }
    virtual double area() const = 0;
    string getColour() const {
        return colour;
    }
    virtual ~Shape() {}
};
class Circle : public Shape {
private:
    double radius;
public:
    Circle(string c, double r) : Shape(c) {
        radius = r;
    }
    double area() const override {
        return 3.14159 * radius * radius;
    }
};
class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(string c, double l, double w) : Shape(c) {
        length = l;
        width = w;
    }
    double area() const override {
        return length * width;
    }
};
class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(string col, double s1, double s2, double s3) : Shape(col) {
        a = s1;
        b = s2;
        c = s3;
    }
    double area() const override {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};
int main() {
    Shape* shapes[5];

    shapes[0] = new Circle("Red", 5);
    shapes[1] = new Rectangle("Blue", 8, 4);
    shapes[2] = new Triangle("Green", 3, 4, 5);
    shapes[3] = new Circle("Yellow", 3);
    shapes[4] = new Rectangle("Black", 6, 7);

    int n = 5;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (shapes[j]->area() < shapes[j + 1]->area()) {
                Shape* temp = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = temp;
            }
        }
    }

    cout << "Shapes Sorted by Area in descending order\n";
    cout << "----------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << "Colour: " << shapes[i]->getColour() << "\t\t" << " Area: " << shapes[i]->area() << endl;
    }
    for (int i = 0; i < n; i++) {
        delete shapes[i];
    }

    return 0;
}