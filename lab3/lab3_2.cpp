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

class TLineSegment
{
private:
    LineSegment ls;

public:
    void setStruct(LineSegment lineSegment) { ls = lineSegment; }
    LineSegment getStruct() { return ls; }

    void init(Point, Point);
    void init(double, double, double, double);
    void input();
    void output();
    char* ToPChar();
};

void TLineSegment::init(Point start, Point end)
{
    LineSegment obj;
    obj.first = start;
    obj.second = end;
    setStruct(obj);
}

void TLineSegment::init(double first_x, double first_y, double second_x, double second_y)
{
    Point first, second;
    first.x = first_x, first.y = first_y, second.x = second_x, second.y = second_y;

    init(first, second);
}

void TLineSegment::input()
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

    init(x1, y1, x2, y2);
}

void TLineSegment::output()
{
    cout << "\n#LineSegment#" << endl;
    cout << ToPChar() << endl;
}

char* TLineSegment::ToPChar()
{
    char *result = new char[sizeof(char) * STRING_SIZE];
    sprintf(result, "1 point - (%.3lf, %.3lf)\n2 point - (%.3lf, %.3lf)", ls.first.x, ls.first.y, ls.second.x, ls.second.y);

    return result;
}

double length(TLineSegment &ls)
{
    return sqrtf((ls.getStruct().first.x - ls.getStruct().second.x) * (ls.getStruct().first.x - ls.getStruct().second.x) 
           + (ls.getStruct().first.y - ls.getStruct().second.y) * (ls.getStruct().first.y - ls.getStruct().second.y));
}

Line toLine(TLineSegment ob)
{
    Line line;
    line.x = 0;

    if (ob.getStruct().first.x == ob.getStruct().second.x)
        line.x = ob.getStruct().first.x;
    
    line.coef = (ob.getStruct().second.y - ob.getStruct().first.y) / (ob.getStruct().second.x - ob.getStruct().first.x);
    line.height = - line.coef * ob.getStruct().first.x + ob.getStruct().first.y;

    return line;
}

bool isLineSegmentsOnOneLine(TLineSegment ob1, TLineSegment ob2)
{
    Line first_line = toLine(ob1);
    Line second_line = toLine(ob2);

    if (first_line.x && second_line.x && first_line.x == second_line.x)
        return true;

    return (first_line.height == second_line.height && first_line.coef == second_line.coef);
}

double angleBetweenTwoLines(TLineSegment ob1, TLineSegment ob2)
{
    Line first_line = toLine(ob1);
    Line second_line = toLine(ob2);

    double tan_angle;

    if (isLineSegmentsOnOneLine(ob1, ob2) || (first_line.x && second_line.x))
        return 0;

    if (first_line.x)
        tan_angle = (ob2.getStruct().second.x - ob2.getStruct().first.x) / (ob2.getStruct().second.y - ob2.getStruct().first.y);
    else if (second_line.x)
        tan_angle = (ob1.getStruct().second.x - ob1.getStruct().first.x) / (ob1.getStruct().second.y - ob1.getStruct().first.y);
    else
        tan_angle = (first_line.coef - second_line.coef)
                     / (1 + first_line.coef * second_line.coef);

    return abs(atan(tan_angle) * 180 / M_PI);
}

bool isIntersects(TLineSegment ls1, TLineSegment ls2)
{
    if (ls1.getStruct().first.x > ls1.getStruct().second.x)
    {
        Point tmp = ls1.getStruct().first;
        ls1.getStruct().first = ls1.getStruct().second;
        ls1.getStruct().second = tmp;
    }

    if (ls2.getStruct().first.x > ls2.getStruct().second.x)
    {
        Point tmp = ls2.getStruct().first;
        ls2.getStruct().first = ls2.getStruct().second;
        ls2.getStruct().second = tmp;
    }

    if (ls1.getStruct().first.x > ls2.getStruct().second.x || ls1.getStruct().second.x < ls2.getStruct().first.x)
        return false;

    Line l2 = toLine(ls2);

    if ((ls1.getStruct().first.x * l2.coef + l2.height) < ls1.getStruct().first.y
        || (ls1.getStruct().second.x * l2.coef + l2.height) > ls1.getStruct().second.y)
        return false;

    return true;
}


int main()
{
    TLineSegment lineSg1, lineSg2;
    lineSg1.input();
    lineSg2.input();

    cout << "Length(first line segment)   : " << length(lineSg1) << endl;
    cout << "Length(second line segment)  : " << length(lineSg2) << endl;
    cout << "Angle between lines          : " << angleBetweenTwoLines(lineSg1, lineSg2) << "\370" << endl;
    cout << "Are line segments intersect  : " << isIntersects(lineSg1, lineSg2) << endl;
    cout << "Are line segments on one line: " << isLineSegmentsOnOneLine(lineSg1, lineSg2);

    return 0;
}