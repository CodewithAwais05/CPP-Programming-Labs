/*Extend the MyString class from the theory section. Add operator+ for string concatenation 
(returns a new MyString). Add operator== for comparison. Add operator[] for character 
access by index. Test all three. */
#include <iostream>
#include <cstring>
using namespace std;
class MyString{
private:
    char str[100];
public:
    MyString(const char s[] = ""){
        strcpy(str, s);
    }
    MyString operator+(MyString s){
        MyString temp;
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }
    bool operator==(MyString s){
        return strcmp(str, s.str) == 0;
    }
    char& operator[](int index){
        return str[index];
    }
    void display(){
        cout << str << endl;
    }
};
int main(){
    MyString s1("Hello");
    MyString s2("World");

    cout << "String 1: ";
    s1.display();

    cout << "String 2: ";
    s2.display();

    MyString s3 = s1 + s2;
    cout << "\nAfter Concatenation (s1 + s2): ";
    s3.display();

    if (s1 == s2)
        cout << "\ns1 and s2 are equal\n";
    else
        cout << "\ns1 and s2 are NOT equal\n";

    cout << "\nCharacter access:\n";
    cout << "s1[1] = " << s1[1] << endl;
    cout << "s2[2] = " << s2[2] << endl;

    s1[0] = 'h';
    cout << "\nAfter modifying s1[0] = 'h': ";
    s1.display();

    return 0;
}