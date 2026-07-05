/*Write a Temperature class with a private double celsius. Add: a default constructor (sets to 0), 
a parameterized constructor, and const methods getCelsius(), toFahrenheit(), and toKelvin(). 
Create an array of five Temperature objects, read values from the user, then print all three 
scales for each.*/
#include<iostream>
using namespace std;
class Temperature{
private:
    double celsius;
public:
    Temperature(){
        celsius = 0;
    }
    Temperature(double c){
        celsius = c;
    }
    double getCelsius() const{
        return celsius;
    }
    double toFahrenheit() const{
        return (celsius * 9.0 / 5.0) + 32;
    }
    double toKelvin() const{
        return celsius + 273.15;
    }
};
int main(){
    Temperature temp[5];
    double value;
    cout << "Enter 5 temperatures in Celsius:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Temperature " << i + 1 << ": ";
        cin >> value;
        temp[i] = Temperature(value);
    }

    cout << "\n------------------------Temperature Conversions:------------------------\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "\nTemperature " << i + 1 << endl;
        cout << "Celsius    : " << temp[i].getCelsius() << " C" << endl;
        cout << "Fahrenheit : " << temp[i].toFahrenheit() << " F" << endl;
        cout << "Kelvin     : " << temp[i].toKelvin() << " K" << endl;
    }

    return 0;
}