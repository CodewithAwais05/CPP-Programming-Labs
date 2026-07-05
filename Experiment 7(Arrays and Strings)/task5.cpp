/*Extend the Stack class from the theory section to work with double values instead of int 
values (demonstrating that the design generalises). Add a method to print all current elements 
from top to bottom without removing them. */
#include <iostream>
using namespace std;
class Stack{
private:
    double arr[100];
    int top;
public:
    Stack(){
        top = -1;
    }
    void push(double value){
        if (top >= 99){
            cout << "Stack Overflow!\n";
        }
        else{
            top++;
            arr[top] = value;
        }
    }
    void pop(){
        if (top == -1){
            cout << "Stack Underflow!\n";
        }
        else{
            top--;
        }
    }
    double peek(){
        if (top == -1){
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }
    void display(){
        if (top == -1){
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements (top to bottom):\n";
        for (int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    Stack s;

    s.push(10.5);
    s.push(20.75);
    s.push(30.25);
    s.push(40.9);

    s.display();
    cout << "\nTop element: " << s.peek() << endl;
    s.pop();
    cout << "\nAfter pop:\n";
    s.display();

    return 0;
}