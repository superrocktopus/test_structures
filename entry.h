#ifndef ENTRY_H
#define ENTRY_H
#include "dstring.h"
#include "Vector.h"
#include <stdlib.h>
#include <fstream>

//each object contains index entry and page numbers the entry is listed on
class entry
{
friend class index;
private:
    dString word;
    Vector<int> pages;
public:
    entry();
    entry(dString wrd, int pg);
    entry(const entry& ent);
//additional page a word appears on
    void add_page(int pg);
    dString getWord();
    int access_page(int pos);
    int getEntrySize();
    ~entry();
};
#endif // ENTRY_H
