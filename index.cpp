#include "index.h"

Indexer::Indexer(){

}

Indexer::Indexer(const Indexer &in){
    this->idx=in.idx;
}

void Indexer::fill_index(char* input){
    ifstream inputFile(input,std::ifstream::in);
    if(inputFile.is_open()){
        cout<<"input is open"<< input <<endl;

        char buffer[80];
        int pgbuff = -1;

        //build entry object
        while(!inputFile.eof()){
            inputFile>> buffer;
            dString dbuff = buffer;

            //check if reading in word or page number
            if(dbuff.is_page() == true){
                //add page to entry object
                pgbuff = dbuff.convert_page();
            }
            else{

                //check if word belongs in index
                if(dbuff.is_index() == true){

                    //homoginize entries
                    dbuff.proper_case();

                    //check for repeated words
                    int repeat = check_index(dbuff);
                    if(repeat != -1){

                        //add page number to repeated entry
                        idx[repeat].add_page(pgbuff);
                    }
                    else{

                        //set word to entry object and add entry to index
                        entry ent(dbuff,pgbuff);
                        add_entry(ent);
                    }
                }
            }
        }
    }
    else{

        cout<<"input file failed to open"<<endl;
    }
    inputFile.close();
}

void Indexer::print_index(char* output){
    ofstream outputFile; //(output,std::ifstream::out);
    outputFile.open("output.txt");
    if(outputFile.is_open()){
        cout<<"output is open"<<endl;

        for(int i=0;i<idx.getSize();i++){
            outputFile << idx[i].getWord();

            for(int j=0;j<idx[i].getEntrySize();j++){
                outputFile << idx[i].access_page(j)<<endl;
            }
            outputFile << "...." <<endl;
        }
    }
    else{

        cout<<"output failed to open"<<endl;
    }

}

void Indexer::add_entry(entry ent){
    idx.push_back(ent);
}

int Indexer::check_index(dString wrd){
    for(int i=0;i<idx.getSize();i++){

        if(wrd == idx[i].getWord()){
            return i;
        }
    }
    return -1;
}

bool Indexer::Bubble_sort(){
    bool complete = false;
    //as the ends are sorted, the loop shrinks to avoid redundancy
    for(int x=0; x<idx.getSize()/2 +1;x++){

        complete = true;
        for(int i=0+x;i<idx.getSize()-1-x;i++){
            //compare by size
            if(idx[i].getWord() > idx[i+1].getWord())
            {
               idx.swap_entries(i, i+1);
               complete = false;
            }
        }
        //from end to beginning
        for(int j=idx.getSize();j>0;j--){
            //compare length
            if(idx[j].getWord() < idx[j-1].getWord())
            {
                idx.swap_entries(j, j-1);
                complete = false;
            }
        }
    }
    return complete;
}

Indexer::~Indexer(){
}
