#include "String.cpp"
#include "StringExp.cpp"
#include <string.h>
using namespace std;

void first_main()
{
    StringExp str1, str2;
    str1.input();
    str2.input();

    cout << "\nDeleting 3 characters from 2 position";
    str1.removeFromPoz(2, 3);
    str1.output();

    cout << "\nPasting second string in first from 3 position";
    str1.pasteStrInPoz(str2, 3);
    str1.output();

    cout << str1.length();
}

void second_main()
{
    StringExp str1, str2;
    str1.input();
    
    // outputing object values using indexer operator
    for (int i = 0; i < str1.length(); i++)
        cout << str1[i];
}

void third_main()
{
    StringExp str1, str2, str3;
    str1.input();
    str2.input();
    str3.input();

    cout << "\nDoes first (StringExp) obj starts with second one: " << str1.startsWith(str2) << endl;
    cout << "Does first (StringExp) obj ends with second one  : " << str1.endsWith(str2) << endl;
    cout << "Is third (StringExp) obj number                  : " << str3.isDigit() << endl;
    
    cout << "\nCapitilizing first (StringExp) obj:";
    str1.capitilize();
    cout << str1;

    cout << "\nConverting all characters from first (StringExp) obj in small register:";
    str1.casefold();
    cout << str1;

    cout << "\nReturning simple string value from first object: " << str1.toPChar() << endl;

    cout << "\nReplacing word 'friend' with 'world':";
    char s1[MAX_SIZE] = "friend", s2[MAX_SIZE] = "world";
    str1.replace(s1, s2);
    cout << str1;
}

int main()
{
    // first_main();
    // second_main();
    third_main();
    return 0;
}