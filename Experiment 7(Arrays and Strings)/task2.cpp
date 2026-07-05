/*Create a Matrix class that stores a 3x3 integer matrix as a private data member. Add: a 
constructor that initializes all elements to zero, a method setElement(row, col, value), a 
method getElement(row, col), a display() method, and a transpose() method that returns a new 
Matrix object containing the transposed values. */
#include <iostream>
using namespace std;
class Matrix{
private:
    int mat[3][3];
public:
    Matrix(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                mat[i][j] = 0;
            }
        }
    }
    void setElement(int row, int col, int value){
        if (row >= 0 && row < 3 && col >= 0 && col < 3){
            mat[row][col] = value;
        }
        else{
            cout << "Invalid row or column!" << endl;
        }
    }
    int getElement(int row, int col){
        if (row >= 0 && row < 3 && col >= 0 && col < 3){
            return mat[row][col];
        }
        else{
            cout << "Invalid row or column!" << endl;
            return -1;
        }
    }
    void display(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    Matrix transpose(){
        Matrix temp;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                temp.mat[j][i] = mat[i][j];
            }
        }
        return temp;
    }
};
int main(){
    Matrix m1;
    m1.setElement(0, 0, 1);
    m1.setElement(0, 1, 2);
    m1.setElement(0, 2, 3);

    m1.setElement(1, 0, 4);
    m1.setElement(1, 1, 5);
    m1.setElement(1, 2, 6);

    m1.setElement(2, 0, 7);
    m1.setElement(2, 1, 8);
    m1.setElement(2, 2, 9);

    cout << "Original Matrix:\n";
    m1.display();

    Matrix m2 = m1.transpose();

    cout << "\nTranspose Matrix:\n";
    m2.display();

    return 0;
}