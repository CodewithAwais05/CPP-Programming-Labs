/*Create an abstract class Shape with pure virtual double area() and double perimeter(). Add a 
non-virtual void print() const that prints both values. Derive Circle, Rectangle, and Triangle. 
Create an array of Shape pointers on the heap, assign one of each type, call print() on each 
through the pointer, then delete all. */
#include <iostream>
#include <cmath>
using namespace std;
class Shape{
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    void print(){
        cout << "Area      : " << area() << endl;
        cout << "Perimeter : " << perimeter() << endl;
        cout << "----------------------" << endl;
    }
    virtual ~Shape() {}
};
class Circle : public Shape{
private:
    double radius;
public:
    Circle(double r){
        radius = r;
    }
    double area(){
        return 3.1416 * radius * radius;
    }
    double perimeter(){
        return 2 * 3.1416 * radius;
    }
};
class Rectangle : public Shape{
private:
    double length, width;
public:
    Rectangle(double l, double w){
        length = l;
        width = w;
    }
    double area(){
        return length * width;
    }
    double perimeter(){
        return 2 * (length + width);
    }
};
class Triangle : public Shape{
private:
    double a, b, c;
public:
    Triangle(double x, double y, double z){
        a = x;
        b = y;
        c = z;
    }
    double area(){
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double perimeter(){
        return a + b + c;
    }
};
int main(){
    Shape *shapes[3];

    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(6, 4);
    shapes[2] = new Triangle(3, 4, 5);

    cout << "Shape Details\n\n";
    for (int i = 0; i < 3; i++){
        shapes[i]->print();
    }
    for (int i = 0; i < 3; i++){
        delete shapes[i];
    }

    return 0;
}