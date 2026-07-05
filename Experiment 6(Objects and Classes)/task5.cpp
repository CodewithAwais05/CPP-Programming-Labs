/*Write a Student class with name (string), rollNo (int), and an array of 5 subject marks. Add a 
constructor, a method to compute average marks, and a method to display all details. 
Demonstrate the copy constructor by copying one student to another, modifying the copy, and 
printing both to confirm they are independent.*/
#include <iostream>
#include <string>
using namespace std;
class Student{
private:
    string name;
    int rollNo;
    int marks[5];
public:
    Student(string n, int r, int m[]){
        name = n;
        rollNo = r;
        for (int i = 0; i < 5; i++){
            marks[i] = m[i];
        }
    }
    Student(const Student &s){
        name = s.name;
        rollNo = s.rollNo;
        for (int i = 0; i < 5; i++){
            marks[i] = s.marks[i];
        }
    }
    void setName(string n){
        name = n;
    }
    void setRollNo(int r){
        rollNo = r;
    }
    void setMarks(int m[]){
        for (int i = 0; i < 5; i++){
            marks[i] = m[i];
        }
    }
    double average() const{
        int sum = 0;

        for (int i = 0; i < 5; i++){
            sum += marks[i];
        }
        return sum / 5.0;
    }
    void display() const{
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;

        cout << "Marks: ";
        for (int i = 0; i < 5; i++){
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Average Marks: " << average() << endl;
    }
};
int main(){
    int marks1[5] = {85, 90, 78, 88, 92};

    Student s1("Awais", 101, marks1);
    Student s2 = s1;
    int marks2[5] = {70, 75, 80, 85, 90};
    s2.setName("Ali");
    s2.setRollNo(102);
    s2.setMarks(marks2);
    cout << "Original Student:\n";
    s1.display();
    cout << "\nAfter modification:\n";
    s2.display();

    return 0;
}