#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_SIZE 100

typedef struct
{
    int first;
    char *second;
} FloatNum;

int check(char *str)
{
    for (int i = 0; i < str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    
    return 1;
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


void input(FloatNum* obj)
{
    char *str = (char *) malloc(sizeof(char) * STRING_SIZE);

    printf("\nEnter integer part of a number: ");
    scanf("%i", &obj->first);
    
    printf("Enter fractional part of a number: ");
    scanf("%s", str);

    while (!check(str))
    {
        printf("\n\nYou entered wrong values! Please try again...");

        printf("\nEnter integer part of a number: ");
        scanf("%i", &obj->first);
        
        printf("Enter fractional part of a number: ");
        scanf("%s", str);

    }

    obj->second = str;
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

FloatNum multiply(FloatNum obj, double num)
{
    double result = convertToDouble(obj) * num;
    return convertToFloatNum(result);
}

void output(FloatNum obj)
{
    printf("\nFloat number -> %i.%s", obj.first, obj.second);
}

int main()
{
    FloatNum ob1, ob2;
    double num;

    input(&ob1);
    output(ob1);

    printf("\nMultiply by ");
    scanf("%lf", &num);
    printf("\nResult of multiplication: ");
    ob2 = multiply(ob1, num);
    output(ob2);

    return 0;
}