#include <iostream>

using namespace std;

class MyClass{
    public:
        MyClass(int size){
            if (size<=4){
                cout<<size<<"?";
            }
            else{
                array= new int(size);
                for (int i=0; i<size; i++){
                    array[i]=size;
                }
            }
        }
        ~MyClass(){
            if (array!=nullptr){
                delete []array;
            }
        }

        void add(int* temp){
            array=temp;
        }

        void getAr(){
            get();
        }
        
        int* open(){
            return array;
        }
    
    private:
        int *array;
        void get(){
            for (int i=1; i<(this->array[i]); i++){
                cout<<"  "<<this->array[i];
	        }
        }
};

int main(){
    int size;
    cin>>size;
    MyClass ob1(size);
    cin>>size;
    MyClass ob2(size);
    int *temp =ob1.open();
    ob1=ob2;
    ob1.add(temp);
    ob1.getAr();
    cout<<endl;
    ob2.getAr();
}