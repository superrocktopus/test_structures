#ifndef DSTRING_H
#define DSTRING_H
#include <cstring>
#include<iostream>
#include <stdlib.h>

using namespace std;

class dString
{
private:
    int size;
    char* letters;
public:
    dString();
    dString(const dString& str);
    dString(const char* str);
    dString& operator =(const dString& str);
    dString& operator =(const char* str);
    dString operator +(const dString& str);
    bool operator ==(const char* str);
    bool operator ==(const dString& str);
    bool operator >(const dString& str);
    bool operator <(const dString& str);
    char& operator[] (const int pos);
    char* c_str(dString);
    dString substring(int start, int end);

    // sets "StRING" to "string"
    void lower_case();
    // sets "string" to "String"
    dString proper_case();
    //check for page numbers in input file
    bool is_page();
    //check if word belongs in index
    bool is_index();
    //converts string to int if encounters <...>
    int convert_page();

    friend std::ostream& operator<< (std::ostream &ofs, const dString&);
    int length();
    ~dString();
};

#endif // DSTRING_H
