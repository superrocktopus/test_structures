#include "catch.hpp"
#include "Vector.h"
#include "dstring.h"


TEST_CASE("Vectors can be sized and resized"){

    Vector <int> testVec(5);

    REQUIRE(testVec.getMax() == 5);
    REQUIRE(testVec.getSize() == 0);

    for(int i=0; i<5; i++){
        testVec.push_back(i+5);
    }

    REQUIRE(testVec.getMax() == 5);
    REQUIRE(testVec.getSize() == 5);
    REQUIRE(testVec[0] == 5);
    REQUIRE(testVec[4] == 9);

    for(int i=0;i<10;i++){
        if(i%2 == 0){
            testVec.push_back(9);
        }
        else{
            testVec.push_back(8);
        }
    }

    SECTION("Check Resized Vector"){

    REQUIRE(testVec.getMax() == 15);
    REQUIRE(testVec.getSize() == 15);
    REQUIRE(testVec[0] == 5);
    REQUIRE(testVec[2] == 7);
    REQUIRE(testVec[5] == 0);
    REQUIRE(testVec[9] == 9);
    }

    testVec.insert_Vector(15, 5);
    testVec.swap_entries(2,8);

    SECTION("Check Vector Functions"){

    REQUIRE(testVec[5] == 15);
    REQUIRE(testVec[2] == 7);
    REQUIRE(testVec[8] == 7);
    }
}

TEST_CASE("Strings can be Initialized and Compared","dString"){
    dString s[10];
    s[0] = "Henry";
    s[1] = "teststring";
    s[2] = "Data Structures";
    s[3] = "XK%@#31()**&";
    s[4] = "0021";
    s[5] = "TESTSTRING";
    s[6] = "/0";
    s[7] = "";
    s[8] = "[class]";
    s[9] = "Data";
    dString name = s[0];

    REQUIRE(s[0].length() == 5);
    REQUIRE(s[2].length() == 15);
    REQUIRE(s[3].length() == 12);

    SECTION("String Compare"){

    REQUIRE(s[2] + s[0] == "Data StructuresHenry");
    REQUIRE(s[0] == s[0]);
    REQUIRE(s[2] < s[0]);
    REQUIRE(s[4] < s[2]);
    REQUIRE(s[3] > s[4]);
    //REQUIRE(s[4].convert_page() == 012345);
    //REQUIRE(s[3].convert_page() == 31);
    char buff[10] = "012345";
    //cout<<atoi(buff)<<endl;
    //cout<<s[4].convert_page()<<endl;
    s[8].proper_case();
    cout<<s[8]<<endl;
    }

    SECTION("Breaking Up Strings"){

    s[5].lower_case();
    s[8].proper_case();

    REQUIRE(s[5] == "teststring");
    REQUIRE(s[8] == "Class");
    REQUIRE(name == s[0]);
    /*REQUIRE(s[2].substring(0,4) == "Data ");
    REQUIRE(s[1].substring(0,3) == "test");
    REQUIRE(s[5].substring(2,2) == "\0");
    REQUIRE(s[4][3] == '4');
    REQUIRE(s[0] + s[5].substring(0,3) == "HenryTEST");*/
    }

    SECTION("Accessing Individual Letters"){
    REQUIRE(s[8][1] == 'l');
    REQUIRE(s[5][3] == 'T');
    REQUIRE(s[9][2] == 't');
    REQUIRE(s[3][3] == '@');
    }
}
