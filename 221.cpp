#include <iostream>

using namespace std;

class MyClass{
    public:
        int openingValue;
        MyClass(int i_data){
            openingValue=i_data;
            closeValue=2*i_data;
        };

        void add(){
            openingValue++;
            closeValue+=4;
        }

        MyClass sicret(MyClass myOb){
            myOb.addNew();
            return myOb;
        }

        void getCloseValue(){
            cout<<"Value of the available property "<<openingValue<<endl;
            cout<<"Value of a hidden property "<<closeValue<<endl;
        }
        
        
    private:
        int closeValue;

        void addNew(){
            openingValue+=5;
            closeValue+=7;
        }

};

int main(){
    int i_data;
    cin>>i_data;
    MyClass myObject(i_data);
    myObject.getCloseValue();
    myObject.add();
    myObject.getCloseValue();
    cin>>i_data;
    myObject.openingValue=myObject.openingValue*i_data;
    myObject.getCloseValue();
    myObject=myObject.sicret(myObject);
    myObject.getCloseValue();
};