using namespace std;
#include <iostream>
#include <math.h>
#include <algorithm>

struct Circle
{
    double x;
    double y;
    double r;

    void input();
};

double distanceCentres(Circle ob1, Circle ob2)
{ return sqrt((ob1.x - ob2.x) * (ob1.x - ob2.x) + (ob1.y - ob2.y) * (ob1.y - ob2.y)); }

double operator*(Circle ob1, Circle ob2)
{
    double d = distanceCentres(ob1, ob2);

    if (d < ob1.r + ob2.r)
    {
        double first = ob1.r * ob1.r,
               second = ob2.r * ob2.r;

        double x = (first - second + d * d) / (2 * d);
        double z = x * x;
        double y = sqrt(first - z);

        if (d <= abs(ob1.r - ob2.r))
            return M_PI * min(first, second);

        return first * asin(y / ob1.r) + second * asin(y / ob2.r) - y * (x + sqrt(z + second - first));
    }
    return 0;
}

double operator+(Circle ob1, Circle ob2)
{
    double unionArea = M_PI * (ob1.r * ob1.r + ob2.r * ob2.r);

    if (distanceCentres(ob1, ob2) < ob1.r + ob2.r)
        unionArea -= ob1 * ob2;

    return unionArea;
}

double operator-(Circle ob1, Circle ob2)
{
    double res = M_PI * ob1.r * ob1.r;

    if (distanceCentres(ob1, ob2) < ob1.r + ob2.r)
        res -= ob1 * ob2;

    return res;
}

void Circle::input()
{
    cout << "\nEnter value of centre point in circle:\n";

    cout << "x = ";
    cin >> x;

    cout << "y = ";
    cin >> y;

    cout << "Enter radius of circle: ";
    cin >> r;
}

void outputResults(Circle ob1, Circle ob2)
{
    cout << "\n#Results of calculations#";
    cout << "\nDistance between centres             : " << distanceCentres(ob1, ob2);
    cout << "\nUnion area        (circle1 + circle2): " << ob1 + ob2;
    cout << "\nIntersection area (circle1 * circle2): " << ob1 * ob2;
    cout << "\nDifference area   (circle1 - circle2): " << ob1 - ob2;
    cout << "\nDifference area   (circle2 - circle1): " << ob2 - ob1;
}

int main()
{
    Circle ob1, ob2;
    ob1.input();
    ob2.input();

    outputResults(ob1, ob2);
    return 0;
}