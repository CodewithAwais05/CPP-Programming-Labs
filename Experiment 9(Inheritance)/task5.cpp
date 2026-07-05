/*Write a base class Animal with protected string name and a virtual void makeSound() function. Derive Dog, Cat, and Bird, each overriding makeSound(). Create an array of three 
Animal pointers, assign one of each derived type, and call makeSound() through the pointer. 
Explain the output you observe. */
#include <iostream>
#include <string>
using namespace std;
class Animal {
protected:
    string name;
public:
    Animal(string n) : name(n) {}
    virtual void makeSound() {
        cout << name << " makes a sound." << endl;
    }
    virtual ~Animal() {}
};
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    void makeSound() override {
        cout << name << " says: Woof! Woof!" << endl;
    }
};
class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
    void makeSound() override {
        cout << name << " says: Meow! Meow!" << endl;
    }
};
class Bird : public Animal {
public:
    Bird(string n) : Animal(n) {}
    void makeSound() override {
        cout << name << " says: Chirp! Chirp!" << endl;
    }
};
int main() {
    Animal* animals[3];
    animals[0] = new Dog("Buddy");
    animals[1] = new Cat("Kitty");
    animals[2] = new Bird("Tweety");

    cout << "Animal Sounds:\n";
    for (int i = 0; i < 3; i++) {
        animals[i]->makeSound();
    }
    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }

    return 0;
}