#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "Vector.h"
#include "dstring.h"
#include "index.h"

using namespace std;

int main(int argc, char* argv[]){
     int result = Catch::Session().run( argc, argv );
     Indexer dexer;
     dexer.fill_index("Listing.txt");
     //dexer.Bubble_sort();
     dexer.print_index("ouput.txt");
     //test index for practicing sorting
     /*Indexer testdex;
     vector <dString> arr(10);
     arr[0] = "Henry";
     arr[1] = "George";
     arr[2] = "Catherine";
     arr[3] = "Marx";
     arr[4] = "Ate";
     arr[5] = "zebra";
     arr[6] = "libra";
     arr[7] = "you";
     arr[8] = "2days";
     arr[9] = "world";
     for(int i=0;i<10;i++){
         entry entr(arr[i],10+i);
         testdex.add_entry(entr);
     }
     //testdex.Bubble_sort();
     testdex.print_index("output.txt");*/
     return ( result < 0xff ? result : 0xff );
}
//fix propercase and convert page
//Its currently hard to tell if Bubble sort works but it seems promising
//fix read in to include white space
