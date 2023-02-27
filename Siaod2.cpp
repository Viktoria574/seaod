#include <iostream>

using namespace std;

struct MyNode{
    int data;
    MyNode *next;//указатель на следущий элемент
};

void setList(MyNode *L, int n){
    MyNode *temp, *el=NULL;
    for (int i=0; i<n; i++){
        temp->data=1 + (rand() % 9);
        temp->next=NULL;
        el=temp;
        if(i==0){
            L=temp;
        }
        else{
            el->next=temp;
        }
        el=temp;
    }
}



int main(){
    MyNode *L;
    setList(L, 10);
};