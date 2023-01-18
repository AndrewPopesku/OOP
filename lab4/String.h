#ifndef String_h
#define String_h
#include <stdio.h>
#include <iostream>
using namespace std;

class String
{
    struct Char
    {
        char value;
        Char *next = nullptr;
    };
    Char *head;
    Char *tail;
    void insert(char);

public:
    
    String();
    String(char *);
    String(const String &);
    ~String();

    String &operator=(const String &);
    friend String operator+(const String &, const String &);
    friend bool operator==(String, String );
    friend bool operator!=(String,String );
    friend bool operator<(String,String);
    friend bool operator>(String,String);
    friend bool operator<=(String,String);
    friend bool operator>=(String,String);
    friend ostream &operator<<(ostream &, String &);

    void input();
    void output();
    void copyFromStr(char *);
    void removeFromPoz(int, int);
    void pasteStrInPoz(String, int);
    int  length();
    int  firstOccurence(String);
};

#endif