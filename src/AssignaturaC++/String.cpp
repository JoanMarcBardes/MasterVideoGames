#include "String.h"
using namespace std;

String::String()
    : str{ nullptr }
{
    str = new char[1];
    str[0] = '\0';
}

String::String(const char* c)
{
    if (c == nullptr) {
        str = new char[1];
        str[0] = '\0';
    }

    else {
        int i = 0;
        while (c[i] != '\0')
        {
            ++i;
        }
        str = new char[i + 1]; //Advertencia	C26451	Desbordamiento aritmético : el operador "+" se usa en un valor de 4 bytes y, a continuación, el resultado se convierte a un valor de 8 bytes.Convierta el valor al tipo más amplio antes de llamar al operador "+" para evitar el desbordamiento(io.2).

        int j = 0;
        while (c[j] != '\0')
        {
            str[j] = c[j];
            ++j;
        }
        str[j] = '\0';
    }
}

String::String(const String& s)
{
    str = s.str;
}

String::String(String&& s)
{
    str = s.str;
    s.str = nullptr;
}

String::~String()
{ 
    //delete str;
}

void String::operator=(const String& s) 
{
    int l = s.lenght() + 1;
    str = new char[l];
    int i = 0;
    while (s.str[i] != '\0')
    {
        str[i] = s.str[i];
        ++i;
    }
    str[i] = '\0'; //Advertencia	C6386	Saturación de búfer al escribir en 'str':  el tamaño de escritura son 'l*1' bytes, pero se pueden escribir '2' bytes.
}

bool String::operator==(const String& s)
{
    bool b = true;
    int i = 0;
    while (s.str[i] != '\0')
    {
        if (str[i] != s.str[i]) return false;
        ++i;
    }
    return b;
}

String String::operator+(const String& s)
{
    int l = lenght() + s.lenght() + 1;
    char* c = new char[l];
    int i = 0;
    while (str[i] != '\0')
    {
        c[i] = str[i];
        ++i;
    }
    int j = 0;
    while (s.str[j] != '\0')
    {
        c[i] = s.str[j];
        ++i;
        ++j;
    }
    c[i] = '\0';
    return String(c);
}


int String::lenght() const
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void String::clear()
{
    delete str;
    str = new char[1];
    str[0] = '\0';
}

String String::GetMeAString() const
{
    return String("another string");
}