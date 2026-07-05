/*Create a structure named Book with three members: title (string), author (string), and price 
(double). Write a function that prints a formatted book record. Create an array of three books, 
read data for each from the user, then display all three.*/
#include<iostream>
using namespace std;
struct Book{
    string title;
    string author;
    double price;
};
void print_book(Book b){
    cout << "\n============Books Records============\n";
    cout << "Book Name:  " << b.title << endl;
    cout << "Book Author:  " << b.author << endl;
    cout << "Book Price:  " << b.price << endl;
}
int main(){
    Book b[3] = {
        {"OOP", "BJarsone", 1200.5},
        {"English", "Prof. Shahid", 1800},
        {"Urdu", "Prof. Sajid", 5000}
    };
    for(int i = 0; i < 3; i++){
        print_book(b[i]);
    }

}