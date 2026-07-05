/*Create a polymorphic payroll system. Write an abstract class Employee with pure virtual 
double computePay() const. Derive SalariedEmployee (fixed monthly pay), HourlyEmployee 
(hourly rate * hours worked), and CommissionEmployee (base salary + commission rate * 
sales). Create an array of Employee pointers and compute total payroll.*/
#include <iostream>
using namespace std;
class Employee{
public:
    virtual double computePay() const = 0;
    virtual ~Employee() {}
};
class SalariedEmployee : public Employee{
private:
    double monthlySalary;
public:
    SalariedEmployee(double salary){
        monthlySalary = salary;
    }
    double computePay() const override{
        return monthlySalary;
    }
};
class HourlyEmployee : public Employee{
private:
    double hourlyRate;
    int hoursWorked;
public:
    HourlyEmployee(double rate, int hours){
        hourlyRate = rate;
        hoursWorked = hours;
    }
    double computePay() const override{
        return hourlyRate * hoursWorked;
    }
};
class CommissionEmployee : public Employee{
private:
    double baseSalary;
    double commissionRate;
    double sales;
public:
    CommissionEmployee(double base, double rate, double sale){
        baseSalary = base;
        commissionRate = rate;
        sales = sale;
    }
    double computePay() const override{
        return baseSalary + (commissionRate * sales);
    }
};
int main(){
    Employee *employees[3];

    employees[0] = new SalariedEmployee(50000);
    employees[1] = new HourlyEmployee(300, 120);
    employees[2] = new CommissionEmployee(40000, 0.10, 300000);

    double totalPayroll = 0;
    cout << "Employee Payroll\n\n";
    for (int i = 0; i < 3; i++){
        cout << "Employee " << i + 1 << " Pay = " << employees[i]->computePay() << endl;
        totalPayroll += employees[i]->computePay();
    }

    cout << "\nTotal Payroll = " << totalPayroll << endl;
    for (int i = 0; i < 3; i++){
        delete employees[i];
    }

    return 0;
}