/*Write a class DynamicArray that allocates an int array on the heap in its constructor (size 
given as parameter) and deallocates it in the destructor. Provide: setElement(index, value), 
getElement(index), resize(newSize) that copies existing data, and display(). Access all arrays 
through a pointer object. */
#include <iostream>
using namespace std;
class DynamicArray{
private:
    int *arr;
    int size;
public:
    DynamicArray(int s){
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++){
            arr[i] = 0;
        }
    }
    ~DynamicArray(){
        delete[] arr;
        cout << "Memory deallocated." << endl;
    }
    void setElement(int index, int value){
        if (index >= 0 && index < size){
            arr[index] = value;
        }
        else{
            cout << "Invalid Index!" << endl;
        }
    }
    int getElement(int index){
        if (index >= 0 && index < size){
            return arr[index];
        }
        else{
            cout << "Invalid Index!" << endl;
            return -1;
        }
    }
    void resize(int newSize){
        int *newArr = new int[newSize];
        int limit = (size < newSize) ? size : newSize;

        for (int i = 0; i < limit; i++){
            newArr[i] = arr[i];
        }
        for (int i = limit; i < newSize; i++){
            newArr[i] = 0;
        }
        delete[] arr;

        arr = newArr;
        size = newSize;
    }
    void display(){
        cout << "Array Elements: ";

        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    DynamicArray *ptr = new DynamicArray(5);

    ptr->setElement(0, 10);
    ptr->setElement(1, 20);
    ptr->setElement(2, 30);
    ptr->setElement(3, 40);
    ptr->setElement(4, 50);

    cout << "Original Array:" << endl;
    ptr->display();

    cout << "Element at index 2: " << ptr->getElement(2) << endl;

    ptr->resize(8);
    cout << "\nAfter Resizing:" << endl;
    ptr->display();

    ptr->setElement(5, 60);
    ptr->setElement(6, 70);
    ptr->setElement(7, 80);

    cout << "\nAfter Adding New Elements:" << endl;
    ptr->display();

    delete ptr;

    return 0;
}