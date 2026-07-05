/*Implement the diamond problem. Write classes: Printable (with virtual void print()), 
Serializable (with virtual void save()), and Document that inherits from both using virtual 
base classes. Add a PDF class and a Spreadsheet class derived from Document. Each class 
adds its own data and overrides both print() and save(). */
#include <iostream>
#include <string>
using namespace std;
class File {
protected:
    string fileName;
public:
    File(string name = "Untitled") {
        fileName = name;
    }
    virtual void print() = 0;
    virtual void save() = 0;
    virtual ~File() {}
};
class Printable : virtual public File {
public:
    Printable(string name = "Untitled") : File(name) {}
    virtual void print() override = 0;
};
class Serializable : virtual public File {
public:
    Serializable(string name = "Untitled") : File(name) {}
    virtual void save() override = 0;
};
class Document : public Printable, public Serializable {
protected:
    int pages;
public:
    Document(string name = "Untitled", int p = 0) : File(name), Printable(name), Serializable(name){
        pages = p;
    }
    void print() override {
        cout << "Printing Document: " << fileName << " (" << pages << " pages)" << endl;
    }
    void save() override {
        cout << "Saving Document: " << fileName << endl;
    }
};
class PDF : public Document {
private:
    bool passwordProtected;
public:
    PDF(string name, int p, bool protect)
        : File(name), Document(name, p) {
        passwordProtected = protect;
    }
    void print() override {
        cout << "Printing PDF File: " << fileName << "\nPages: " << pages << "\nPassword Protected:"
             << (passwordProtected ? "Yes" : "No") << endl;
    }
    void save() override {
        cout << "Saving PDF File: " << fileName
             << " as .pdf" << endl;
    }
};
class Spreadsheet : public Document {
private:
    int sheets;
public:
    Spreadsheet(string name, int p, int s)
        : File(name), Document(name, p) {
        sheets = s;
    }
    void print() override {
        cout << "Printing Spreadsheet: " << fileName << "\nPages: " << pages
             << "\nWorksheets: " << sheets << endl;
    }
    void save() override {
        cout << "Saving Spreadsheet: " << fileName
             << " as .xlsx" << endl;
    }
};
int main() {
    PDF pdf("OOP_Notes", 120, true);
    Spreadsheet excel("Marks_Record", 15, 5);

    cout << "===== PDF =====" << endl;
    pdf.print();
    pdf.save();
    cout << "\n===== Spreadsheet =====" << endl;
    excel.print();
    excel.save();
    return 0;
}