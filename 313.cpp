#include <iostream>

using namespace std;

class MyClass{
    public:
    int size;
        MyClass(){
            cout<<"Default constructor"<<endl;
        }
        MyClass(int s){
            cout<<"Constructor set"<<endl;
            size=s;
            array= new int[size];
        }
        MyClass (const MyClass& ob){
            cout<<"Copy constructor"<<endl;
            this->array=new int[ob.size];
            for (int i=0; i<ob.size; i++){
                this->array[i]=ob.array[i];
             }
        }
        void setValue(int i){
            cin>>array[i];
        }
        void sum(){
            for (int i=0; i<(this->array[i]); i+2){
                array[i]=array[i]+array[i+1];
            }
        }
        void proz(){
            for (int i=0; i<(this->array[i]); i+2){
                array[i]=array[i]*array[i+1];
            }
        }
        int allSum(){
            int sumi=0;
            for (int i=0; i<(this->array[i]); i+2){
                sumi+=(this->array[i]);
            }
            return sumi;
        }
        ~MyClass(){
            cout<<"Destructor";
            if (array!=nullptr){
                delete []array;
            }
        }
    private:
        int* array;
};

int main(){
    int s;
    cin>>s;
    if (s>2 and s%2==0){
        cout<<s<<endl;
        MyClass ob(s);
    }
    else{
        cout<<s<<"?"<<endl;
    }
}