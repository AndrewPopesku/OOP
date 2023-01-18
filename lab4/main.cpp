#include "String.cpp"
#include <string.h>
using namespace std;

void main_first()
{
    char s[15] = "Hello";
    String obj = String(s);
    obj.output();

    String obj2;
    obj2.input();
    String obj3 = obj2;

    obj2.output();
    obj3.output();

    return;
}

void main_second()
{
    char str[100] = "abcdefghijklmop", _str[59] = "human";
    String str1(str), str2(_str);
    
    str1.pasteStrInPoz(str2, 3);
    // str1.removeFromPoz(3, 6);
    str1.output();

    // return;
}

void main_third()
{
    String obj;
    String obj2;
    obj.input();
    obj2.input();

    String obj3 = obj + obj2;
    cout << "\nobj1 + obj2 = " << obj3;

    cout << "Is obj1 == obj2: " << (obj == obj2) << endl;
    cout << "Is obj1 != obj2: " << (obj != obj2) << endl;
    cout << "Is obj1  > obj2: " << (obj > obj2)  << endl;
    cout << "Is obj1  < obj2: " << (obj < obj2)  << endl;
    cout << "Is obj1 >= obj2: " << (obj >= obj2) << endl;
    cout << "Is obj1 <= obj2: " << (obj <= obj2) << endl;

    return;
}

int main()
{
    // main_first();
    main_second();
    // main_third();

    return 0;
}