#ifndef String_h
#define String_h
#include <stdio.h>
#include <iostream>
using namespace std;

class String
{
protected:
    struct Char
    {
        char value;
        Char *next = nullptr;
    };
    Char *head;
    Char *tail;
    void insert(char);
    void clearStringList();

public:
    
    String();
    String(char *);
    String(const String &);
    ~String();

    String &operator=(const String &);
    friend String operator+(const String &, const String &);
    friend bool operator==(String, String);
    friend bool operator!=(String,String);
    friend bool operator<(String,String);
    friend bool operator>(String,String);
    friend bool operator<=(String,String);
    friend bool operator>=(String,String);
    friend ostream &operator<<(ostream &, String &);

    void input();
    void output();
    void copyFromStr(char *);
    void removeFromPoz(int poz, int n);
    void pasteStrInPoz(String obj, int poz);
    int  length();
    int  firstOccurence(String);
};

#endif