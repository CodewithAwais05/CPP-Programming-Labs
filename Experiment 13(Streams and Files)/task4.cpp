/*Add the overloaded << and >> operators to the Student class from Lab 6. Write 10 Student 
objects to a file using the << operator. Read them back using >> and display them. Confirm 
the input and output use the same format. */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student{
private:
    int id;
    string name;
    float gpa;
public:
    friend istream& operator>>(istream &in, Student &s){
        in >> s.id >> s.name >> s.gpa;
        return in;
    }
    friend ostream& operator<<(ostream &out, Student &s){
        out << s.id << " " << s.name << " " << s.gpa;
        return out;
    }
};
int main(){
    Student s[10];
    cout << "Enter details of 10 students:\n";
    for (int i = 0; i < 10; i++){
        cout << "\nStudent " << i + 1 << endl;
        cout << "Enter ID Name GPA: ";
        cin >> s[i];
    }

    ofstream fout("students.txt");
    for (int i = 0; i < 10; i++){
        fout << s[i] << endl;
    }
    fout.close();

    ifstream fin("students.txt");
    Student temp;
    cout << "\nStudents Read From File:\n";
    cout << "-------------------------\n";
    while (fin >> temp){
        cout << temp << endl;
    }
    fin.close();

    return 0;
}