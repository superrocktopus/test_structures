#ifndef INDEX_H
#define INDEX_H
#include "dstring.h"
#include "Vector.h"
#include <stdlib.h>
#include <fstream>
#include "entry.h"

//index object is a vector entry objects
class Indexer
{
private:
    Vector<entry> idx;
public:
    Indexer();
    Indexer(const Indexer& in);
    void fill_index(char* input);
    void add_entry(entry ent);
    int check_index(dString wrd);
    void print_index(char *output);
    bool Bubble_sort();
    ~Indexer();
};
#endif // INDEX_H
