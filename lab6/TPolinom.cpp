#include "TPolinom.h"

TPolinom::TPolinom()
{
    maxPower = 0;
    color = YELLOW;
}

TPolinom::TPolinom(double *nums)
{
    maxPower = sizeof(nums) / sizeof(nums[0]) - 1;
    for (int i = 0; i <= maxPower; i++)
        coef[i] = nums[i];
}

void TPolinom::input()
{
    cout << "Enter max power of polinom -> ";
    cin >> maxPower;
    for (int i = maxPower; i >= 0; i--)
    {
        double num;
        cout << "x^" << i << " = ";
        cin >> num;
        coef[i] = num;
    }
}

void TPolinom::output()
{
    cout << endl << "The output of polinom: ";
    for (int i = maxPower; i >= 0; i--)
    {
        if (i != 0)
            cout << showpos << coef[i] << noshowpos << "x^" << i;
        else
            cout << showpos << coef[i] << noshowpos;
    }
}

double TPolinom::f_x(double x)
{
    double res = 0;
    for (int i = maxPower; i >= 0; i--)
        res += coef[i] * pow(x, i);

    return res;
}

void TPolinom::equation(double start, double end, double step)
{
    cout << "\nTabulation:\n";
    cout << "+---------+---------+" << endl;
    cout << "|    x    |   f(x)  |" << endl;
    cout << "+=========+=========+" << endl;
    for (double i = start; i <= end; i = i + step)
    {
        printf("|%9.2lf|%9.2lf|\n", double(i), f_x(i));
        cout << "+---------+---------+" << endl;
    }
}

void TPolinom::draw(double start, double end)
{
    double e = 0.01;
    for (double x = start; x + e <= end; x += e)
    {
        setcolor(color);
        line(WIDTH / 2 + (x * 30), HEIGHT / 2 - (f_x(x) * 30), WIDTH / 2 + (x * 30) + e, HEIGHT / 2 - (f_x(x + e) * 30));
    }
}