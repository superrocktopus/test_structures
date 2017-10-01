#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

using namespace std;


template <class T>
class Vector{
private:
    int size;
    int max;
    T* data;

    void resize_Vector(){
        int newMax = (max) *2;
        T* temp = new T[newMax];
        for(int i=0;i<max;i++)
        {
            temp[i] = data[i];
        }
        this->max = newMax;
        delete [] data;
        data = temp;
    }

public:
    Vector(){
        max = 10;
        data = new T[max];
        size = 0;
    }

    Vector(int maximum){
        max = maximum;
        data = new T[max];
        size = 0;
    }

    Vector(const Vector& vec){
        size = vec.size;
        max = vec.max;
        data = new T[max];
        for(int i=0;i<max;i++)
        {
            data[i] = vec.data[i];
        }
    }

    Vector& operator=(const Vector& vec){
        size = vec.size;
        max = vec.max;
        data = new T[max];
        for(int i=0;i<size;i++)
        {
            data[i] = vec.data[i];
        }
        return *this;
    }

    ~Vector(){
       delete[] data;
    }
//returns number of items in vector
    int getSize(){
        return size;
    }
//returns maximum size
    int getMax(){
        return max;
    }
//add indiviudal element to end
    void push_back(T obj){
        if(size<max)
        {
            data[size] = obj;
            size++;
        }
        else
        {
            resize_Vector();
            data[size] = obj;
            size++;
        }
    }

    void insert_Vector(const T& obj, int pos){
             data[pos] = obj;
             if(pos > max || pos<0){

             }
    }

    void swap_entries(int a, int b){
        T temp = data[a];
        data[a] = data[b];
        data[b] = temp;
    }

    T& operator [] (int pos){
        if(0>pos || pos>=max)
        {
            //cout<<" inserting outside array:"<< data[max]<<endl;
            return data[1];
        }
        else{
        return data[pos];
        }
    }
//doesn't work if vector contains objects
    T& getItem(const int pos) const{
        return data[pos];
    }

    friend std::ostream& operator<<(std::ostream& os, const T& obj)
    {
        for(int i=0;i<getSize();i++)
        {
            //os << data[i];
        }
        return os;
    }
};

#endif // VECTOR_H
