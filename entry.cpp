#include "entry.h"

entry::entry(){

}

entry::entry(dString wrd, int pg){
    word = wrd;
    pages.push_back(pg);
}

entry::entry(const entry& ent){
    this->word = ent.word;
    this->pages = ent.pages;
}

void entry:: add_page(int pg){
    pages.push_back(pg);
}

dString entry:: getWord(){
    return word;
}

int entry::access_page(int pos){
    return pages[pos];
}

int entry::getEntrySize(){
    return pages.getSize();
}

entry:: ~entry(){

}

