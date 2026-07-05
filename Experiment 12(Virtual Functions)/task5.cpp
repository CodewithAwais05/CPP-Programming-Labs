/*Write a class hierarchy for a zoo simulation. Base class: Animal (name, age, virtual 
makeSound(), virtual move()). Derived: Lion, Eagle, Dolphin, each overriding both methods. 
Implement a ZooManager class that maintains a dynamic array of Animal pointers and 
provides: addAnimal(Animal*), removeAnimal(int index), and runSimulation() that calls both 
methods on every animal. */
#include <iostream>
#include <string>
using namespace std;
class Animal {
protected:
    string name;
    int age;
public:
    Animal(string n, int a) {
        name = n;
        age = a;
    }
    virtual void makeSound() = 0;
    virtual void move() = 0;
    virtual ~Animal() {}
};
class Lion : public Animal {
public:
    Lion(string n, int a) : Animal(n, a) {}
    void makeSound() override {
        cout << name << " (Lion): Roar!" << endl;
    }
    void move() override {
        cout << name << " runs across the land." << endl;
    }
};
class Eagle : public Animal {
public:
    Eagle(string n, int a) : Animal(n, a) {}
    void makeSound() override {
        cout << name << " (Eagle): Screech!" << endl;
    }
    void move() override {
        cout << name << " flies high in the sky." << endl;
    }
};
class Dolphin : public Animal {
public:
    Dolphin(string n, int a) : Animal(n, a) {}
    void makeSound() override {
        cout << name << " (Dolphin): Click Click!" << endl;
    }
    void move() override {
        cout << name << " swims through the water." << endl;
    }
};
class ZooManager {
private:
    Animal** animals;
    int capacity;
    int count;
public:
    ZooManager(int size = 10) {
        capacity = size;
        count = 0;
        animals = new Animal*[capacity];
    }
    void addAnimal(Animal* a) {
        if (count < capacity) {
            animals[count++] = a;
            cout << "Animal added successfully.\n";
        } else {
            cout << "Zoo is full!\n";
        }
    }
    void removeAnimal(int index) {
        if (index < 0 || index >= count) {
            cout << "Invalid index.\n";
            return;
        }
        delete animals[index];
        for (int i = index; i < count - 1; i++) {
            animals[i] = animals[i + 1];
        }
        count--;
        cout << "Animal removed successfully.\n";
    }
    void runSimulation() {
        cout << "\n===== Zoo Simulation =====\n\n";
        for (int i = 0; i < count; i++) {
            animals[i]->makeSound();
            animals[i]->move();
            cout << endl;
        }
    }
    ~ZooManager() {
        for (int i = 0; i < count; i++)
            delete animals[i];
        delete[] animals;
    }
};
int main() {
    ZooManager zoo;

    zoo.addAnimal(new Lion("Simba", 5));
    zoo.addAnimal(new Eagle("Sky", 3));
    zoo.addAnimal(new Dolphin("Flipper", 7));

    zoo.runSimulation();
    cout << "\nRemoving animal at index 1...\n\n";
    zoo.removeAnimal(1);
    zoo.runSimulation();

    return 0;
}