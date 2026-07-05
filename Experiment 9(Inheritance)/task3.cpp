/*Implement a three-level Vehicle -> Car -> ElectricCar hierarchy where each level adds at 
least two data members and passes all relevant data up through constructor initializer lists. 
Add a method compare(ElectricCar &other) that returns which car has a longer battery range.*/
#include <iostream>
#include <string>
using namespace std;
class Vehicle {
protected:
    string brand;
    string model;
public:
    Vehicle(string b, string m) : brand(b), model(m) {}
    void display() const {
        cout << "Brand : " << brand << endl;
        cout << "Model : " << model << endl;
    }
};
class Car : public Vehicle {
protected:
    int year;
    double price;
public:
    Car(string b, string m, int y, double p) : Vehicle(b, m), year(y), price(p) {}
    void display() const {
        Vehicle::display();
        cout << "Year  : " << year << endl;
        cout << "Price : $" << price << endl;
    }
};
class ElectricCar : public Car {
private:
    double batteryRange;
    double batteryCapacity;
public:
    ElectricCar(string b, string m, int y, double p, double range, double capacity) : Car(b, m, y, p), batteryRange(range), batteryCapacity(capacity) {}
    
    void display() const {
        Car::display();
        cout << "Battery Range    : " << batteryRange << " km" << endl;
        cout << "Battery Capacity : " << batteryCapacity << " kWh" << endl;
    }
    string compare(ElectricCar &other) {
        if (batteryRange > other.batteryRange)
            return brand + " " + model + " has a longer battery range.";
        else if (batteryRange < other.batteryRange)
            return other.brand + " " + other.model + " has a longer battery range.";
        else
            return "Both electric cars have the same battery range.";
    }
};
int main() {
    ElectricCar car1("Tesla", "Model 3", 2024, 45000, 550, 75);
    ElectricCar car2("Hyundai", "Ioniq 5", 2024, 42000, 480, 72);

    cout << "Car 1 Details\n";
    cout << "-------------\n";
    car1.display();
    cout << "\nCar 2 Details\n";
    cout << "-------------\n";
    car2.display();
    cout << "\nComparison Result:\n";
    cout << car1.compare(car2) << endl;

    return 0;
}