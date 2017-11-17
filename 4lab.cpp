#include <iostream>
#include <iomanip>

using namespace std;

class Matrix {

    //закриті змінні-члени класу
private:
    double array[5][5];
    int row = 5;
    int column = 5;
public:
    //відкриті функції-члени класу
    void WriteMatrix();

    void ReadMatrix();

    void BubbleSort();

    void Swap(int fromPosition, int toPosition, int columnWhereToSwap);

    void ArithmeticMean();
};

//реалізація функції вводу масиву
void Matrix::WriteMatrix() {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++) {
            cout << "[" << i << "][" << j << "] = ";
            cin >> array[i][j];
        }
}

// реалізація функції виведення масиву
void Matrix::ReadMatrix() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            cout << setw(7) << array[i][j] << "    ";
        cout << endl;
    }
}

// реалізація функції сортування методом обміну
void Matrix::BubbleSort() {
    for (int c = 0; c < column; c++) {
        for (int i = 0; i < row - 1; i++) {
            for (int r = 0; r < row - 1 - i; r++) {
                if (array[r][c] > array[r + 1][c]) {

                    Swap(r, r + 1, c);

                }
            }

        }
    }
}

// реалізація функції обміну місцями двох елементів масиву
void Matrix::Swap(int fromPosition, int toPosition, int columnWhereToSwap) {
    double buffer = array[fromPosition][columnWhereToSwap];
    array[fromPosition][columnWhereToSwap] = array[toPosition][columnWhereToSwap];
    array[toPosition][columnWhereToSwap] = buffer;
}

// реалізація функції середнього арифметчного та розрахунок добутків
void Matrix::ArithmeticMean() {
    double dobutok;
    for (int r = 0; r < row; r++) {
        double sum = 0;

        for (int c = 0; c < column; c++) {
            sum += array[r][c];
        }
        double serArithmetic = sum / column;

        cout << "ArithmeticMean : " << "[" << r + 1 << "]" << serArithmetic << endl;

        if (r == 0) {
            dobutok = serArithmetic;
        } else {
            dobutok *= serArithmetic;
        }

    }
    cout << endl;
    cout << "dobutok serednih znachenij : " << dobutok << endl;

}


int main() {

    Matrix A; // А - об*єкт Класу Matrix

    cout << "Write elements of array A" << endl;
    A.WriteMatrix();
    cout << "new Matrix A " << endl;
    A.ReadMatrix();
    cout << endl;
    A.BubbleSort();
    cout << "newSorted Matrix A " << endl;
    A.ReadMatrix();
    cout << endl;
    A.ArithmeticMean();

    system("pause");
    return 0;
}