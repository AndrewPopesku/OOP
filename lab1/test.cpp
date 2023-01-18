using namespace std;

#include <iostream>
#include <string.h>
#define STRING_SIZE 100

struct FloatNum
{
    int first;
    string second;

    // void input();
    // void output();
    // FloatNum multiply(double num);
};

int main()
{
    FloatNum ob1, ob2;
    double num;
    
    ob1.first = 1;
    ob1.second = "006";

    cout << ob1.first << '.' << ob1.second;
    // cout << "Hi" << 123;

    // ob1.input();
    // ob2.output();

    // printf("\nMultiply by ");
    // scanf("%lf", &num);
    // printf("\nResult of multiplication: ");
    // ob2 = ob1.multiply(num);
    // ob2.output();

    return 0;
}