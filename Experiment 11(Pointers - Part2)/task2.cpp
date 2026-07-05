/*Extend the Builder class from the this pointer section. Add a copy constructor, an overloaded 
= operator, and a method bool equals(const Builder &other) const that compares all fields. 
Create two Builder objects, copy one to the other, then compare them. */
#include <iostream>
#include <string>
using namespace std;
class Builder{
private:
    string name;
    int age;
public:
    Builder(string name = "", int age = 0){
        this->name = name;
        this->age = age;
    }
    Builder(const Builder &other){
        name = other.name;
        age = other.age;
    }
    Builder& operator=(const Builder &other){
        if (this != &other){
            name = other.name;
            age = other.age;
        }
        return *this;
    }
    Builder& setName(string name){
        this->name = name;
        return *this;
    }
    Builder& setAge(int age){
        this->age = age;
        return *this;
    }
    bool equals(const Builder &other) const{
        return (name == other.name && age == other.age);
    }
    void display() const{
        cout << "Name: " << name << endl;
        cout << "Age : " << age << endl;
    }
};
int main(){
    Builder b1;
    b1.setName("Awais").setAge(21);

    Builder b2(b1);

    cout << "Object 1:\n";
    b1.display();

    cout << "\nObject 2 (Copied using Copy Constructor):\n";
    b2.display();

    Builder b3;
    b3 = b1;

    cout << "\nObject 3 (Copied using Assignment Operator):\n";
    b3.display();

    if (b1.equals(b2)){
        cout << "\nb1 and b2 are equal." << endl;
    }
    else{
        cout << "\nb1 and b2 are not equal." << endl;
    }

    if (b1.equals(b3)){
        cout << "b1 and b3 are equal." << endl;
    }
    else{
        cout << "b1 and b3 are not equal." << endl;
    }

    return 0;
}