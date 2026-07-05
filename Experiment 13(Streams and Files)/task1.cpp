/*Write a program that reads five student records (name, ID, GPA) from the user, rejecting and 
re-prompting for any GPA outside the 0.0-4.0 range. If two students share the same name, 
append a numeric suffix (for example "Ali_2") to the second one before storing it. Sort the 
five records by GPA in descending order, write them to a text file in that order, then read the 
file back and display all records in a formatted table with column headers and each student's 
rank (1st, 2nd, ...). */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
struct Student{
    string name;
    int id;
    float gpa;
};
int main(){
    Student s[5];
    for (int i = 0; i < 5; i++){
        cout << "\nEnter details of Student " << i + 1 << endl;
        cout << "Name: ";
        cin >> s[i].name;
        int count = 1;
        string originalName = s[i].name;
        for (int j = 0; j < i; j++){
            if (s[j].name == originalName){
                count++;
            }
        }
        if (count > 1){
            s[i].name = originalName + "_" + to_string(count);
        }
        cout << "ID: ";
        cin >> s[i].id;
        do{
            cout << "GPA (0.0 - 4.0): ";
            cin >> s[i].gpa;

            if (s[i].gpa < 0.0 || s[i].gpa > 4.0){
                cout << "Invalid GPA! Enter again.\n";
            }

        } while (s[i].gpa < 0.0 || s[i].gpa > 4.0);
    }
    for (int i = 0; i < 4; i++){
        for (int j = i + 1; j < 5; j++){
            if (s[j].gpa > s[i].gpa){
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    ofstream fout("students.txt");
    for (int i = 0; i < 5; i++){
        fout << s[i].name << " "
             << s[i].id << " "
             << s[i].gpa << endl;
    }
    fout.close();
    ifstream fin("students.txt");

    Student temp;
    cout << "\n-------------------------------\n";
    cout << left << setw(8) << "Rank" << setw(15) << "Name" << setw(10) << "ID" << setw(5) << "GPA" << endl;
    cout << "-------------------------------\n";
    int rank = 1;

    while (fin >> temp.name >> temp.id >> temp.gpa){
        cout << left << setw(8) << rank
             << setw(15) << temp.name
             << setw(10) << temp.id
             << setw(5) << temp.gpa << endl;

        rank++;
    }
    fin.close();

    return 0;
}