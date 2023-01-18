#include "StringExp.h"
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 250

StringExp::StringExp() : String()
{
    size = 0;
}

StringExp::StringExp(char *ch) : String(ch)
{
    size = strlen(ch);
}

StringExp::StringExp(String obj) : String(obj)
{
    size = obj.length();
}

StringExp::StringExp(const StringExp &obj) : String(obj)
{
    size = obj.size;
}

StringExp::~StringExp()
{
}

char &StringExp::operator[](int i)
{
    if (i >= length() || i < 0)
    {
        cerr << "Index is out of range.";
        return head->value;
    }

    Char *curr = head;
    while (--i >= 0)
        curr = curr->next;

    return curr->value;
}

void StringExp::input()
{
    String::input();
    size = String::length();
}

void StringExp::removeFromPoz(int poz, int n)
{
    String::removeFromPoz(poz, n);
    size -= n;
}

void StringExp::pasteStrInPoz(String obj, int poz)
{
    String::pasteStrInPoz(obj, poz);
    size += obj.length();
}

int StringExp::length() { return size; }

bool StringExp::startsWith(String obj)
{
    return (firstOccurence(obj) == 0);
}

bool StringExp::endsWith(String obj)
{
    if (length() < obj.length())
    {
        cerr << "\nGiven string is larger than (this) one\n";
        return false;
    }

    StringExp mainObj(*this), objToCheck(obj);

    for (int i = mainObj.length() - 1, j = objToCheck.length() - 1; j >= 0 && i >= 0; i--, j--)
        if (mainObj[i] != objToCheck[j])
            return false;

    return true;
}

void StringExp::capitilize()
{
    if (head->value >= 'a' && head->value <= 'z')
        head->value -= 32;
}

void StringExp::casefold()
{
    StringExp str(*this);
    for (int i = 0; i < length(); i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';

    *this = str;
}

char* StringExp::toPChar()
{
    StringExp str(*this);
    char *result = (char*) malloc(sizeof(char) * MAX_SIZE);
    int i;
    for (i = 0; i < length(); i++)
        result[i] = str[i];

    result[i] = '\0';
    return result;
}

bool StringExp::isDigit()
{
    StringExp str(*this);
    for (int i = 0; i < length(); i++)
        if (str[i] < '0' || str[i] > '9')
            return false;

    return true;
}

void StringExp::replace(String oldStr, String newStr)
{
    int n = this->firstOccurence(oldStr);
    if (n == -1)
    {
        cerr << "\nThere is no such substring in the string: replace function\n";
        return;
    }

    removeFromPoz(n, oldStr.length());
    pasteStrInPoz(newStr, n);
}

void StringExp::replace(char *oldStr, char *newStr)
{
    StringExp old(oldStr), newOb(newStr);
    replace(old, newOb);
}

