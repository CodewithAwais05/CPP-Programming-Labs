/*Write two independent base classes: Printable (with a pure void print() const method that 
prints object data) and Serializable (with a void serialize(string filename) method that writes a 
description to a file). Create a class Report that inherits from both and implements both 
methods.*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Printable {
public:
    virtual void print() const = 0;
    virtual ~Printable() {}
};
class Serializable {
public:
    virtual void serialize(string filename) = 0;
    virtual ~Serializable() {}
};
class Report : public Printable, public Serializable {
private:
    string title;
    string author;
    int pages;
public:
    Report(string t, string a, int p) : title(t), author(a), pages(p) {}
    void print() const override {
        cout << "----- Report Details -----" << endl;
        cout << "Title  : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Pages  : " << pages << endl;
    }
    void serialize(string filename) override {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        file << "----- Report Details -----\n";
        file << "Title  : " << title << endl;
        file << "Author : " << author << endl;
        file << "Pages  : " << pages << endl;
        file.close();
        cout << "Report saved successfully to \"" << filename << "\"" << endl;
    }
};
int main() {
    Report r("Annual Sales Report", "Awais", 35);
    r.print();
    cout << endl;
    r.serialize("report.txt");

    return 0;
}