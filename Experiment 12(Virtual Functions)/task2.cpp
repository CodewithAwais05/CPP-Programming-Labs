/*Demonstrate the virtual destructor problem. Write a base class NoVirtDtor with a non-virtual 
destructor and a data member int* arr dynamically allocated in the constructor. Derive 
NVChild. Delete through a base pointer and observe that the derived destructor never runs 
and memory is leaked. Then add virtual to the destructor and verify both run. */
#include <iostream>
using namespace std;
class NoVirtDtor{
protected:
    int *arr;
public:
    NoVirtDtor(){
        arr = new int[5];
        cout << "Base Constructor\n";
    }
    // ~NoVirtDtor(){
    //     delete[] arr;
    //     cout << "Base Destructor\n";
    // }
    virtual ~NoVirtDtor(){
        delete[] arr;
        cout << "Base Destructor\n";
    }
};
class NVChild : public NoVirtDtor{
private:
    int *data;
public:
    NVChild(){
        data = new int[10];
        cout << "Derived Constructor\n";
    }
    ~NVChild(){
        delete[] data;
        cout << "Derived Destructor\n";
    }
};
int main(){
    NoVirtDtor *ptr = new NVChild();
    delete ptr;
    return 0;
}