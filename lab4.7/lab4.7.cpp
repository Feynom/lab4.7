#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x, xp, xk, dx, eps, a = 0, r = 0, s = 0;
    int n = 0;

    cout << "Введіть значення 'хp':"; cin >> xp;
    cout << "Введіть значення 'хk':"; cin >> xk;
    cout << "Введіть значення 'dx':"; cin >> dx;
    cout << "Введіть значення 'eps':"; cin >> eps;

    cout << fixed;
    cout << "------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << setw(5) << "|";
    cout << setw(9) << "arctg(x)" << setw(2) << "|";
    cout << setw(5) << "n" << setw(5) << "|";
    cout << setw(5) << "S" << setw(5) << "|" << endl;
    cout << "------------------------------------------" << endl;

    double pi = 4 * atan(1.0);
    x = xp;  
    while (x <= xk)
    {
        n = 0;
        a = -x;
        s = a;
            do
            {
                n++;
                r = (-x*x*(2*n-1))/(2*n+1);
                a *= r;
                s += a;
            } while (abs(a) >= eps);

            cout << "|" << setw(7) << setprecision(3) << x << setw(3);
            cout << "|" << setw(8) << setprecision(3) << atan(x) << setw(3);
            cout << "|" << setw(5) << setprecision(3) << n << setw(5);
            cout << "|" << setw(8) << setprecision(3) << s + pi/2. << setw(2) << "|";
            cout << endl;
            cout << "------------------------------------------" << endl;

            x += dx;
    }

    return 0;
}
