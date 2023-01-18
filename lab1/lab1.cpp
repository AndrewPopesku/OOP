using namespace std;

#include <iostream>
#include <string.h>
#define STRING_SIZE 100

struct FloatNum
{
    int first;
    string second;

    void input();
    void output();
    FloatNum multiply(double num);
};

bool check(string);
double power(int, int);
double convertToDouble(FloatNum);
FloatNum convertToFloatNum(double);

void FloatNum::input()
{
    string str;
    printf("\nEnter integer part of a number: ");
    cin >> first;

    printf("Enter fractional part of a number: ");
    cin >> str;

    while (!check(str))
    {
        printf("\n\nYou entered wrong values! Please try again...");

        printf("\nEnter integer part of a number: ");
        cin >> first;
        
        printf("Enter fractional part of a number: ");
        cin >> str;
    }

    second = str;
}

FloatNum FloatNum::multiply(double num)
{
    double result = convertToDouble(*this) * num;
    return convertToFloatNum(result);
}

void FloatNum::output()
{
    cout << "\nFloat number -> " << first << '.' << second;
}

bool check(string str)
{
    for (int i = 0; i < str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    
    return true;
}

double power(int base, int pow)
{
    int res = 1;
    for (int i = 0; i < pow; i++)
        res *= base;

    return res;
}

double convertToDouble(FloatNum obj)
{
    int x = 0;
    int count = 0;
    int isZeroInFront = (obj.second[0] == '0');
    for (int i = 0; obj.second[i] != '\0'; i++)
    {
        if (isZeroInFront)
            isZeroInFront = (obj.second[i + 1] == '0');
        else
            x = x * 10 + (obj.second[i] - '0');
        
        count++;
    } 

    return obj.first + x / power(10, count);
}

FloatNum convertToFloatNum(double num)
{
    FloatNum FNum;
    FNum.first = (int)num;

    char *str = (char *)malloc(sizeof(char) * STRING_SIZE);
    sprintf(str, "%lf", num);
    FNum.second = strchr(str, '.') + 1;

    return FNum;
}



int main()
{
    FloatNum ob1, ob2;
    double num;

    ob1.input();
    ob1.output();

    cout << "\nMultiply by ";
    cin >> num;
    cout << "\nResult of multiplication: ";
    ob2 = ob1.multiply(num);
    ob2.output();

    return 0;
}