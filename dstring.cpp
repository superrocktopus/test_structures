#include "dstring.h"

dString::dString(){
   size = 0;
   letters = new char[size + 1];
   letters [size] = '\0';
}

dString::dString(const dString& str){
    this->size = str.size;
    letters = new char[size];
    strcpy(letters,str.letters);
}
//set dString using text
dString::dString(const char* str){
    this->size= strlen(str);
    letters = new char[size+1];
    strcpy(letters,str);
}

dString& dString::operator =(const dString& str){
    delete[] letters;
    this->size=str.size;
    letters = new char[size];
    strcpy(letters,str.letters);
    return *this;
}
//convert dString into char*
dString& dString::operator =(const char* str){
    delete[] letters;
    this->size = strlen(str);
    letters = new char[size+1];
    strcpy(letters,str);
    letters[size] = '\0';
    return *this;
}

dString dString::operator +(const dString& str){
    dString sum;
    sum = strcat(letters,str.letters);
    return sum;
}

//compare char* to dString
bool dString::operator ==(const char* charzard){
    if(strcmp(letters,charzard) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool dString::operator ==(const dString& str){
    if(strcmp(letters,str.letters) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool dString::operator <(const dString& str){
    if(strcmp(letters,str.letters) < 0){
        return true;
    }
    else{
        return false;
    }
}

bool dString::operator >(const dString& str){
    if(strcmp(letters,str.letters) > 0){
        return true;
    }
    else{
        return false;
    }
}

char& dString::operator[] (const int pos){
    if(pos<0)
    {
        cout<<"out of bounds negative" << letters <<endl;
        return letters[0];
    }
    if(pos > size)
    {
       cout<<"out of bounds positive" << letters <<endl;
       return letters[size-1];
    }
    return letters[pos];
}

dString dString::substring(int start,int end){

    dString substr;
    if(letters[start]=='\0')
    {
        //check if substring is too small
        cout<<"invalid: substring has zero length"<<endl;
        return substr;
    }
    for(int i=0; i<end - start; i++)
    {
        if(letters[start + i] == '\0')
        {
            return substr;
        }
        substr[i] = letters[start + i];
    }

        return substr;
}

void dString :: lower_case(){
    for(int i=0; i<size; i++){
        if(letters[i] > 64 && letters[i] < 91){
            letters[i] += 32;
        }
    }
}

dString dString ::proper_case(){

    dString str;
    str.size = this->size;
    for(int i=0;i<size;i++){
        int j=0;
        if(letters[i] > 64 && letters[i] < 91 ||
                letters[i] > 96 && letters[i] < 123 || letters[i] == 32){
            str.letters[j] = 100;
            j++;
        }
   }

    if(letters[0] > 96 && letters[0] < 123){
        letters[0] -= 32;
    }
    for(int i=1;i<size;i++){
        if(letters[i] > 64 && letters[i] < 91){
            letters[i] += 32;
        }
    }
    str.letters[6] = 123;
       return str;
}

bool dString::is_page(){
    for(int i=0;i<size;i++){
        if(letters[i] == 60 || letters[i] == 62){
            return true;
        }
    }
    return false;
}

bool dString::is_index(){
    for(int i=0;i<size;i++){
        if(letters[i] == 91 || letters[i] == 93){
            return true;
        }
    }
    return false;
}

int dString::convert_page(){
    dString num = letters;

    for(int i=0;i<size;i++){
        int j=0;
        if(letters[i] > 47 && letters[i] < 58 ){
            num.letters[j] = letters[i];
            j++;
        }
    }
    return atoi(num.letters);
}

ostream& operator <<(ostream &ofs, const dString& str){
        ofs << str.letters;
    return ofs;
}

int dString::length(){
    return size;
}

char* dString:: c_str(dString){
    return letters;
}

dString::~dString(){
    delete[] letters;
}

