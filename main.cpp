#include <iostream>

using namespace std;

int main() {
    // Змінні
    const int cols = 5, rows = 5; // кількість рядків, стовпців
    int m[rows][cols] = {
            {22, 41, 45, -45, -49},
            {5, 1, 3, -2, 0},
            {34, 97, 48, 72, -1},
            {-3, -7, 5, 92, 20},
            {0, -3, -57, 9, 1} // оголошення матриці
    },
            min_val, min_idx, new_val, c, r, i; // оголошення змінних

    // Сортування стовпців методом вибору
    for (  c = 0; c < cols; c++) {
        for (r = 0; r < rows; r++) {
            min_val = 999999;
            min_idx = r;

            for (i = r; i < rows; i++) {
                if ( m[i][c] < min_val ) {
                    min_val = m[i][c];
                    min_idx = i;
                    new_val = 0;
                }
            }
            new_val = m[min_idx][c];
            m[min_idx][c] = m[r][c];
            m[r][c] = new_val;
        }
    }

    // Виведення матриці
    cout << "vidsortovana matritsia:" << endl;
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            cout << m[r][c] << ",";
        }
        cout << "\n";
    }

    // Рахуємо добутки порядково
    cout << "dobutki poriadkovo nad dopomijnoiu diagonaliu:" << endl;
    int sum = 0;
    for (r = 0; r < rows - 1; r++) {
         int mul = m[r][0];

        for (c = 1; c < cols-r-1; c++) {
            mul = mul * m[r][c];
        }
        sum = mul + sum;
        cout << "Dobutok " << (r+1) <<  "go riadku = " << mul << "\n";

    }
    //Сума добутків
    cout << endl;
     cout << "Summa dobutkiv: " << sum << endl;

    system ("pause");
    return 0;
}
