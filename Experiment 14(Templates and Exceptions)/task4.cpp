/*Write a class template Array<T, int SIZE> with a bounds-checked access method T& at(int 
index) that throws OutOfRangeException if index < 0 or index >= SIZE. Add operator[] 
(unchecked) and a sort() method.*/
#include <iostream>
#include <exception>
using namespace std;
class OutOfRangeException : public exception{
public:
    const char* what() const noexcept override{
        return "Error: Index out of range!";
    }
};
template <class T, int SIZE>
class Array{
private:
    T arr[SIZE];
public:
    Array(){
        for (int i = 0; i < SIZE; i++){
            arr[i] = T();
        }
    }
    T& at(int index){
        if (index < 0 || index >= SIZE){
            throw OutOfRangeException();
        }
        return arr[index];
    }
    T& operator[](int index){
        return arr[index];
    }
    void sort(){
        for (int i = 0; i < SIZE - 1; i++){
            for (int j = 0; j < SIZE - i - 1; j++){
                if (arr[j] > arr[j + 1]){
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    void display(){
        for (int i = 0; i < SIZE; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    Array<int, 5> a;
    a[0] = 50;
    a[1] = 10;
    a[2] = 30;
    a[3] = 20;
    a[4] = 40;

    cout << "Original Array: ";
    a.display();

    a.sort();

    cout << "Sorted Array: ";
    a.display();

    try{
        cout << "Accessing index 2: " << a.at(2) << endl;
        cout << "Accessing index 10: " << a.at(10) << endl; // ❌ error
    }
    catch (OutOfRangeException &e){
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}