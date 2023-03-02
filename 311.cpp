#include <iostream>

using namespace std;

class MyClass{
    public:
        int* array;
        MyClass(int size){
            if (size<=4){
                array=NULL;
            }
            else{
                array= new int(size);
                for(int i=0; i<size; i++){
                    array[i]=size;
                }
            }
        }

        void getArr(){
            for (int i=0; i<(this->array[i]); i++){
                cout<<array[i]<<" ";
            }
            
        }
        ~MyClass(){
            if (array!=nullptr){
                delete[]array;
            }
        }
};

int main(){
    MyClass mi(5);
    mi.getArr();
};