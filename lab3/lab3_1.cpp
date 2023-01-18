using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define STRING_SIZE 100

struct Point
{
    double x;
    double y;
};

struct Line
{
    double coef;
    double height;

    double x;
};

struct LineSegment
{
    Point first;
    Point second;
};

void init(LineSegment &ls, Point start, Point end)
{
    ls.first = start;
    ls.second = end;
}

void init(LineSegment &ls, double first_x, double first_y, double second_x, double second_y)
{
    Point first, second;
    first.x = first_x, first.y = first_y, second.x = second_x, second.y = second_y;

    init(ls, first, second);
}

void input(LineSegment &ls)
{
    double x1, y1, x2, y2;
    cout << "Enter point coordinates for line segment:" << endl;
    
    cout << "x1 = ";
    cin >> x1;
    cout << "y1 = ";
    cin >> y1;
    cout << "x2 = ";
    cin >> x2;
    cout << "y2 = ";
    cin >> y2;

    init(ls, x1, y1, x2, y2);
}

char* ToPChar(LineSegment &ls)
{
    char *result = new char[sizeof(char) * STRING_SIZE];
    sprintf(result, "1 point - (%.3lf, %.3lf)\n2 point - (%.3lf, %.3lf)", ls.first.x, ls.first.y, ls.second.x, ls.second.y);

    return result;
}

void output(LineSegment ls)
{
    cout << "\n#LineSegment#" << endl;
    cout << ToPChar(ls) << endl;
}

double length(LineSegment &ls)
{
    return sqrtf((ls.first.x - ls.second.x) * (ls.first.x - ls.second.x) 
           + (ls.first.y - ls.second.y) * (ls.first.y - ls.second.y));
}

Line toLine(LineSegment ob)
{
    Line line;
    line.x = 0;

    if (ob.first.x == ob.second.x)
        line.x = ob.first.x;

    line.coef = (ob.second.y - ob.first.y) / (ob.second.x - ob.first.x);
    line.height = - line.coef * ob.first.x + ob.first.y;

    return line;
}

bool isLineSegmentsOnOneLine(LineSegment ob1, LineSegment ob2)
{
    Line first_line = toLine(ob1);
    Line second_line = toLine(ob2);

    if (first_line.x && second_line.x && first_line.x == second_line.x)
        return true;

    return (first_line.height == second_line.height && first_line.coef == second_line.coef);
}

double angleBetweenTwoLines(LineSegment ob1, LineSegment ob2)
{
    Line first_line = toLine(ob1);
    Line second_line = toLine(ob2);

    double tan_angle;

    if (isLineSegmentsOnOneLine(ob1, ob2) || (first_line.x && second_line.x))
        return 0;

    if (first_line.x)
        tan_angle = (ob2.second.x - ob2.first.x) / (ob2.second.y - ob2.first.y);
    else if (second_line.x)
        tan_angle = (ob1.second.x - ob1.first.x) / (ob1.second.y - ob1.first.y);
    else
        tan_angle = (first_line.coef - second_line.coef) 
                     / (1 + first_line.coef * second_line.coef);

    return abs(atan(tan_angle) * 180 / M_PI);
}

bool isIntersects(LineSegment ls1, LineSegment ls2)
{
    if (ls1.first.x > ls1.second.x)
    {
        Point tmp = ls1.first;
        ls1.first = ls1.second;
        ls1.second = tmp;
    }

    if (ls2.first.x > ls2.second.x)
    {
        Point tmp = ls2.first;
        ls2.first = ls2.second;
        ls2.second = tmp;
    }

    if (ls1.first.x > ls2.second.x || ls1.second.x < ls2.first.x)
        return false;
        
    Line l2 = toLine(ls2);

    if ((ls1.first.x * l2.coef + l2.height) < ls1.first.y || (ls1.second.x * l2.coef + l2.height) > ls1.second.y)
        return false;

    return true;
}


int main()
{
    LineSegment lineSg1, lineSg2;
    input(lineSg1);
    input(lineSg2);

    cout << "Length(first line segment)   : " << length(lineSg1) << endl;
    cout << "Length(second line segment)  : " << length(lineSg2) << endl;
    cout << "Angle between lines          : " << angleBetweenTwoLines(lineSg1, lineSg2) << "\370" << endl;
    cout << "Are line segments intersect  : " << isIntersects(lineSg1, lineSg2) << endl;
    cout << "Are line segments on one line: " << isLineSegmentsOnOneLine(lineSg1, lineSg2);

    return 0;
}