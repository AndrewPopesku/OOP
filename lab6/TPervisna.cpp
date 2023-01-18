#include "TPervisna.h"

TPervisna::TPervisna() : TPolinom()
{
    color = GREEN;
}

TPervisna::TPervisna(TPolinom poly) : TPervisna()
{
    maxPower = poly.getPower() + 1;
    double* nums = poly.getCoefs();
    for (int i = 0; i <= maxPower - 1; i++)
        coef[i] = nums[i] / (i + 1);
}

double TPervisna::F_x(double x)
{
    double res = 0;
    for (int i = maxPower; i > 0; i--)
        res += coef[i - 1] * (pow(x, i));

    return res;
}

void TPervisna::output()
{
    cout << endl << "The output of polinom integral: ";
    for (int i = maxPower; i > 0; i--)
        cout << showpos << setprecision(2) << coef[i - 1] << noshowpos << "x^" << i;
    cout << "+C";
}

void TPervisna::equation(double start, double end, double step)
{
    cout << "\nTabulation of function integral:\n";
    cout << "+---------+---------+" << endl;
    cout << "|    x    |  f'(x)  |" << endl;
    cout << "+=========+=========+" << endl;
    for (double i = start; i <= end; i = i + step)
    {
        printf("|%9.2lf|%9.2lf|\n", double(i), F_x(i));
        cout << "+---------+---------+" << endl;
    }
}

void TPervisna::draw(double start, double end)
{
    double e = 0.0001;
    for (double x = start; x + e <= end; x += e)
    {
        setcolor(color);
        line(WIDTH / 2 + (x * 30), HEIGHT / 2 - (F_x(x) * 30), WIDTH / 2 + (x * 30) + e, HEIGHT / 2 - (F_x(x + e) * 30));
    }
}