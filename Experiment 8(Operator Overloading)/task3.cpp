/*Create a Matrix2x2 class that stores a 2x2 integer matrix. Overload + for matrix addition, * 
for matrix multiplication, == for equality, and << for output. Demonstrate all operations. */
#include <iostream>
using namespace std;
class Matrix2x2{
private:
    int mat[2][2];
public:
    Matrix2x2(){
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                mat[i][j] = 0;
            }
        }
    }
    void set(int i, int j, int value){
        mat[i][j] = value;
    }
    Matrix2x2 operator+(Matrix2x2 m){
        Matrix2x2 temp;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                temp.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return temp;
    }
    Matrix2x2 operator*(Matrix2x2 m){
        Matrix2x2 temp;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                temp.mat[i][j] = 0;
                for (int k = 0; k < 2; k++){
                    temp.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return temp;
    }
    bool operator==(Matrix2x2 m){
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                if (mat[i][j] != m.mat[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    friend ostream& operator<<(ostream& out, Matrix2x2 m);
};
ostream& operator<<(ostream& out, Matrix2x2 m){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            out << m.mat[i][j] << " ";
        }
        out << endl;
    }
    return out;
}
int main(){
    Matrix2x2 A, B, C;
    A.set(0,0,1); A.set(0,1,2);
    A.set(1,0,3); A.set(1,1,4);

    B.set(0,0,1); B.set(0,1,2);
    B.set(1,0,3); B.set(1,1,4);

    cout << "Matrix A:\n" << A;
    cout << "Matrix B:\n" << B;

    C = A + B;
    cout << "\n--------------------------------\n";
    cout << "A + B:\n" << C;
    
    C = A * B;
    cout << "\n--------------------------------\n";
    cout << "A * B:\n" << C;
    
    cout << "\n--------------------------------\n";
    if (A == B)
        cout << "A and B are equal\n";
    else
        cout << "A and B are not equal\n";

    return 0;
}