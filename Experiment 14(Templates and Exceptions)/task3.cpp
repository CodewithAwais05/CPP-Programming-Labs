/*Add exception handling to the Stack<T> class. Define two custom exceptions: 
StackOverflowException and StackUnderflowException, both derived from std::exception. 
push() throws StackOverflowException when the stack is full; pop() throws 
StackUnderflowException when empty. Write a test that deliberately triggers both exceptions.*/
#include <iostream>
#include <exception>
using namespace std;
class StackOverflowException : public exception{
public:
    const char* what() const noexcept override{
        return "Stack Overflow! Stack is full.";
    }
};
class StackUnderflowException : public exception{
public:
    const char* what() const noexcept override{
        return "Stack Underflow! Stack is empty.";
    }
};
template <class T>
class Stack{
private:
    T arr[3];
    int top;
public:
    Stack(){
        top = -1;
    }
    void push(T value){
        if (top >= 2){
            throw StackOverflowException();
        }
        top++;
        arr[top] = value;
        cout << "Pushed: " << value << endl;
    }
    T pop(){
        if (top < 0){
            throw StackUnderflowException();
        }
        T value = arr[top];
        top--;

        cout << "Popped: " << value << endl;
        return value;
    }
};
int main(){
    Stack<int> s;
    cout << "---- Testing Stack Overflow ----\n";
    try{
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
    }
    catch (StackOverflowException &e){
        cout << "Exception: " << e.what() << endl;
    }

    cout << "\n---- Testing Stack Underflow ----\n";

    try{
        s.pop();
        s.pop();
        s.pop();
        s.pop();
    }
    catch (StackUnderflowException &e){
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}