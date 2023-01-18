#include "String.h"
#include <string.h>

String::String()
{
    head = nullptr;
    tail = nullptr;
}

String::~String()
{
    Char *curr = head;
    while(curr != NULL)
    {
    Char *next = curr->next;
        delete curr;
        curr = next;
    }
    head = NULL;
}

String::String(char *str)
{
    this->copyFromStr(str);
}

String::String(const String &obj)
{
    if (obj.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
        return;
    }

    Char *tmp = obj.head;
    head = new Char;
    head->value = tmp->value;
    head->next = nullptr;
    tail = head;

    tmp = tmp->next;
    while (tmp != nullptr)
    {
        tail->next = new Char;
        tail = tail->next;
        tail->value = tmp->value;
        tail->next = nullptr;
        tmp = tmp->next;
    }
}

void String::insert(char val)
{
    Char *new_node = new Char;
    new_node->value = val;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        tail = head;
    }
    else
    {
        tail->next = new_node;
        tail = tail->next;
    }
}

void String::copyFromStr(char *str)
{
    Char *new_node = new Char;
    new_node->value = str[0];
    new_node->next = NULL;
    head = new_node;
    tail = head;

    for (int i = 1; str[i] != '\0'; i++)
        insert(str[i]);
}

void String::input()
{
    if (head != nullptr)
    {
        tail = head;

        while (tail != nullptr)
        {
            tail = tail->next;
            delete head;
            head = tail;
        }
    }

    char *str = new char;
    cout << "Enter your text here: ";
    cin.getline(str, sizeof(str));

    Char *new_node = new Char;
    new_node->value = str[0];
    new_node->next = NULL;
    head = new_node;
    tail = head;

    for (int i = 1; str[i] != '\0'; i++)
        insert(str[i]);

    delete str;
}

void String::output()
{
    cout << endl
         << "The output of String object: ";
    Char *temp = head;
    while (temp != NULL)
    {
        cout << temp->value;
        temp = temp->next;
    }
    cout << endl;
}

int String::length()
{
    int size = 0;
    Char *curr = head;
    while (curr != nullptr)
    {
        size++;
        curr = curr->next;
    }

    return size;
}

void String::removeFromPoz(int poz, int n)
{
    if (poz > length() - 1 || poz < 0)
        return;

    Char *start = head;

    while (--poz)
        start = start->next;

    Char *tmp = start->next;
    while (n && start->next != nullptr)
    {
        start->next = start->next->next;
        n--;
    }

    tail = start;
    if (tail->next != nullptr)
        while (tail->next != nullptr)
            tail = tail->next;

    Char *proc_tmp = tmp;
    while (proc_tmp != start->next)
    {
        proc_tmp = proc_tmp->next;
        delete tmp;
        tmp = proc_tmp;
    }
}

void String::pasteStrInPoz(String obj, int poz)
{
    if (poz >= length())
        return;

    Char* curr = head;
    while (--poz)
        curr = curr->next;

    Char* tmp = curr->next;

    Char* samp = obj.head;
    while (samp != nullptr)
    {
        Char *ch = new Char;
        ch->value = samp->value;
        curr->next = ch;
        samp = samp->next;
        curr = curr->next;
    }

    curr->next = tmp;
    if (curr->next == nullptr)
        tail = curr;
}

int String::firstOccurence(String obj)
{
    if (obj.head == nullptr)
        return -1;

    int poz = 0;
    Char *curr = head;
    while (curr->value != obj.head->value)
    {
        curr = curr->next;
        poz++;
        if (curr == nullptr)
            return -1;
    }

    int count = obj.length();
    while (count)
    {
        if (curr->value != obj.head->value)
            return -1;

        curr = curr->next;
        obj.head = obj.head->next;
        count--;
    }

    return poz;
}

String &String::operator=(const String &obj)
{
    if (this == &obj)
        return *this;

    tail = head;
    while (tail != nullptr)
    {
        tail = tail->next;
        delete head;
        head = tail;
    }

    if (obj.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
        return *this;
    }

    Char *tmp = obj.head;
    head = new Char;
    head->value = tmp->value;
    head->next = nullptr;
    tail = head;

    tmp = tmp->next;
    while (tmp != nullptr)
    {
        tail->next = new Char;
        tail = tail->next;
        tail->value = tmp->value;
        tail->next = nullptr;
        tmp = tmp->next;
    }

    return *this;
}

String operator+(const String &obj1, const String &obj2)
{
    String result = obj1;

    String::Char *current = obj2.head;
    while (current != nullptr)
    {
        result.insert(current->value);
        current = current->next;
    }

    return result;
}

bool operator==(String obj1, String obj2)
{
    if (obj1.length() != obj2.length())
        return false;

    String::Char *tmp1 = obj1.head, *tmp2 = obj2.head;
    while (tmp1 != nullptr)
    {
        if (tmp1->value != tmp2->value)
            return false;

        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    return true;
}

bool operator!=(String obj1, String obj2)
{
    return !(obj1 == obj2);
}

bool operator>(String obj1, String obj2)
{
    if (obj1 == obj2)
        return false;

    String::Char *tmp1 = obj1.head, *tmp2 = obj2.head;
    while (tmp1->value == tmp2->value && tmp1->next != nullptr && tmp2->next != nullptr)
        tmp1 = tmp1->next, tmp2 = tmp2->next;

    if (tmp1->value == tmp2->value)
        return obj1.length() > obj2.length();

    return !(tmp1->value > tmp2->value);
}

bool operator<(String obj1, String obj2)
{
    return !(obj1 > obj2) && (obj1 != obj2);
}

bool operator>=(String obj1, String obj2)
{
    return (obj1 > obj2) || (obj1 == obj2);
}

bool operator<=(String obj1, String obj2)
{
    return (obj1 < obj2) || (obj1 == obj2);
}

ostream &operator<<(ostream &os, String &str)
{
    str.output();
}