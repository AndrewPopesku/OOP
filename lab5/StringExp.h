#ifndef StringExp_h
#define StringExp_h
#include "String.h"

class StringExp : public String
{
    int size;

public:
    // constructors and destructor
    StringExp();
    StringExp(char *);
    StringExp(String);
    StringExp(const StringExp &);
    ~StringExp();
    
    // getters and setters
    Char *getHead() { return head; }
    void setHead(Char *p) { head = p; }
    Char *getTail() { return tail; }
    void setTail(Char *p) { tail = p; }

    // new operators
    char& operator[](int);

    // overrided methods
    void  input();
    void  removeFromPoz(int poz, int n);
    void  pasteStrInPoz(String str, int poz);
    int   length();

    // new methods
    bool  startsWith(String str);
    bool  endsWith(String str);
    bool  isDigit();    
    void  capitilize(); // converts the first character to upper case
    void  casefold(); // converts all characters to lower case
    char* toPChar();
    void  replace(String oldStr, String newStr);
    void  replace(char* oldStr, char* newStr);
};

#endif