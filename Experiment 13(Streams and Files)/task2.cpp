/*Write a program that reads any text file line by line and reports: the total number of lines, the 
total number of words, the total number of characters (including spaces), and the longest line 
and its line number. */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ifstream fin("input.txt");
    if (!fin){
        cout << "File could not be opened!" << endl;
        return 1;
    }
    string line;
    int totalLines = 0;
    int totalWords = 0;
    int totalCharacters = 0;

    string longestLine = "";
    int longestLineNumber = 0;
    while (getline(fin, line)){
        totalLines++;
        totalCharacters += line.length();

        int words = 0;
        bool inWord = false;
        for (int i = 0; i < line.length(); i++){
            if (line[i] != ' ' && !inWord){
                words++;
                inWord = true;
            }
            else if (line[i] == ' '){
                inWord = false;
            }
        }
        totalWords += words;

        if (line.length() > longestLine.length()){
            longestLine = line;
            longestLineNumber = totalLines;
        }
    }
    fin.close();

    cout << "Total Lines      : " << totalLines << endl;
    cout << "Total Words      : " << totalWords << endl;
    cout << "Total Characters : " << totalCharacters << endl;
    cout << "Longest Line No. : " << longestLineNumber << endl;
    cout << "Longest Line     : " << longestLine << endl;

    return 0;
}