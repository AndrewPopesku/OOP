#include "TPohidna.h"

TPohidna::TPohidna() : TPolinom()
{
    derMaxPower = 0;
    color = RED;
}

TPohidna::TPohidna(TPolinom poly) : TPohidna()
{
    maxPower = poly.getPower();
    double *nums = poly.getCoefs();
    for (int i = 0; i <= maxPower; i++)
        coef[i] = nums[i];

    derMaxPower = maxPower - 1;
    for (int i = maxPower; i >= 0; i--)
        derCoefs[i - 1] = i * coef[i];
}

double TPohidna::derInPoint(double x)
{
    double res = 0;
    for (int i = maxPower - 1; i >= 0; i--)
        res += derCoefs[i] * pow(x, i);

    return res;
}

void TPohidna::output()
{
    cout << endl << "The output of polinom derivative: ";
    for (int i = maxPower - 1; i >= 0; i--)
    {
        if (i != 0)
            cout << showpos << derCoefs[i] << noshowpos << "x^" << i;
        else
            cout << showpos << derCoefs[i] << noshowpos;
    }
}

void TPohidna::equation(double start, double end, double step)
{
    cout << "\nTabulation of function derivative:\n";
    cout << "+---------+---------+" << endl;
    cout << "|    x    |  f'(x)  |" << endl;
    cout << "+=========+=========+" << endl;
    for (double i = start; i <= end; i = i + step)
    {
        printf("|%9.2lf|%9.2lf|\n", double(i), derInPoint(i));
        cout << "+---------+---------+" << endl;
    }
}

void TPohidna::draw(double start, double end)
{
    double e = 0.00001;
    for (double x = start; x + e <= end; x += e)
    {
        setcolor(color);
        line(WIDTH / 2 + (x * 30), HEIGHT / 2 - (derInPoint(x) * 30), WIDTH / 2 + (x * 30) + e, HEIGHT / 2 - (derInPoint(x + e) * 30));
    }
}