/*Write a log file manager class. It opens a file in append mode (ios::app) and provides: void 
log(string message) that writes a timestamped line, void clear() that truncates the file, and int 
countEntries() that reads the file and counts lines. */
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
class LogFileManager{
private:
    string fileName;
public:
    LogFileManager(string name){
        fileName = name;
    }
    void log(string message){
        ofstream fout(fileName, ios::app);
        time_t now = time(0);
        fout << ctime(&now) << message << endl;
        fout.close();
    }
    void clear(){
        ofstream fout(fileName, ios::trunc);
        fout.close();
        cout << "Log file cleared successfully." << endl;
    }
    int countEntries(){
        ifstream fin(fileName);
        string line;
        int count = 0;
        while (getline(fin, line)){
            count++;
        }
        fin.close();
        return count;
    }
};
int main(){
    LogFileManager log("log.txt");

    log.log("Program Started");
    log.log("User Logged In");
    log.log("Program Ended");

    cout << "Total Entries: " << log.countEntries() << endl;
    log.clear();
    cout << "Entries After Clear: " << log.countEntries() << endl;

    return 0;
}