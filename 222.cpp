#include <iostream>

using namespace std;

class MyClass{
    public:
        int openingValue;
        MyClass(int i_data){
            openingValue=i_data;
            closeValue=3*i_data;
        };

        void add(){
            openingValue+=4;
            closeValue++;
        }

        MyClass* sicret(MyClass* myOb){
            myOb->addNew();
            return myOb;
        }

        void getValue(){
            cout<<"Value of the available property "<<openingValue;
            cout<<"; Value of a hidden property "<<closeValue;
        }
        
    private:
        int closeValue;

        void addNew(){
            openingValue+=7;
            closeValue+=5;
        }

};

int main(){
    int i_data;
    cin>>i_data;
    MyClass *pmyObject= new MyClass(i_data);
    pmyObject->getValue();
    cout<<endl;
    pmyObject->add();
    pmyObject->getValue();
    cout<<endl;
    cin>>i_data;
    if (i_data>pmyObject->openingValue){
        pmyObject->openingValue*=i_data;
    }
    pmyObject->getValue();
    cout<<endl;
    pmyObject=pmyObject->sicret(pmyObject);
    pmyObject->getValue();
};