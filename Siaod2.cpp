#include <iostream>

using namespace std;

struct MyNode{
    int data;
    MyNode *next;//указатель на следущий элемент
};

void setList(MyNode* &L, int n){
    MyNode *temp, *el=NULL;
    for (int i=0; i<n; i++){
        temp= new MyNode;
        temp->data=1 + (rand() % 9);
        temp->next=NULL;
        if(i==0){
            L=temp;
        }
        else{
            el->next=temp;
        }
        el=temp;
    }
}

void getList(MyNode* &L){
    MyNode *temp=L;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    MyNode *myList=NULL;
    setList(myList, 10);
    getList(myList);
};