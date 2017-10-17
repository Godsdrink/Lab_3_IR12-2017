#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    double h = 0.05; // крок h
    double d = 0.001; // похибка
    double a = 0.5, b = 0.9; //інтервал
    double x = a, y; // змінні
    double sum; // сумма
    double fact; //факторіал
    double prev_y;
    double z;// попередній "y"
    do
    {
        int n = 1;
        double sum = 0;
        double fact = 0 ;
        double prev_y = 1;
        ;
        do
        {
            y = (2 * n - 1) / ((2 * n) * (2 * n + 1));
            prev_y *= y;
            sum = sum + prev_y;
            n++;
        }
        while (y > d);
        x = x + h;
        sum = sum + x;
        printf("sum is : %lf\n %lf\n\n", sum, x);
    }while (x < b);
    system("pause");
}



