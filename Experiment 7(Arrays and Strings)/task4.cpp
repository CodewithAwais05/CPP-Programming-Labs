/*Create a class named WordList that stores up to 20 strings in a private array. Add: a method 
add(string word), a method display() that prints all words, a method search(string word) that 
returns the index or -1 if not found, and a method remove(string word) that removes a word 
by shifting elements.*/
#include <iostream>
#include <string>
using namespace std;
class WordList{
private:
    string words[20];
    int count;
public:
    WordList(){
        count = 0;
    }
    void add(string word){
        if (count < 20){
            words[count] = word;
            count++;
        }
        else{
            cout << "List is full!\n";
        }
    }
    void display(){
        cout << "Words in list:\n";
        for (int i = 0; i < count; i++){
            cout << words[i] << " ";
        }
        cout << endl;
    }
    int search(string word){
        for (int i = 0; i < count; i++){
            if (words[i] == word){
                return i;
            }
        }
        return -1;
    }
    void remove(string word){
        int index = search(word);
        if (index == -1){
            cout << "Word not found!\n";
            return;
        }
        for (int i = index; i < count - 1; i++){
            words[i] = words[i + 1];
        }
        count--;
        cout << "Word removed successfully!\n";
    }
};
int main(){
    WordList list;
    list.add("apple");
    list.add("banana");
    list.add("mango");
    list.add("orange");

    list.display();

    string word;
    cout << "\nEnter word to search: ";
    cin >> word;

    int index = list.search(word);
    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not found\n";

    cout << "\nEnter word to remove: ";
    cin >> word;

    list.remove(word);
    list.display();

    return 0;
}