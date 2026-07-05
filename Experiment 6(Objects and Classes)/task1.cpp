/*Design a Rectangle class with private members length and width. Add a parameterized 
constructor, and public const methods area() and perimeter(). Create five rectangles with 
different dimensions and display a table showing length, width, area, and perimeter for each.*/
#include <iostream>
#include <iomanip>
using namespace std;
class Rectangle{
    private:
      double length;
      double width;
    public:
        Rectangle(double l, double w){
            length = l;
            width = w;
        }
         double area() const{
            return length * width;
        }
        double perimeter() const{
            return 2 * (length + width);
        }
         double getLength() const {
           return length; 
        }
         double getWidth() const {
           return width; 
        }
};
int main()
{
    Rectangle r1(4, 5);
    Rectangle r2(2.5, 3);
    Rectangle r3(6, 7);
    Rectangle r4(10, 2);
    Rectangle r5(8, 4.5);

    Rectangle arr[5] = {r1, r2, r3, r4, r5};

    cout << "Length\tWidth\tArea\t\tPerimeter\n";
    for (int i = 0; i < 5; i++){
        cout << arr[i].getLength() << "\t" << arr[i].getWidth() << "\t" << arr[i].area() << "\t\t" << arr[i].perimeter() << endl;
    }
    return 0;
}