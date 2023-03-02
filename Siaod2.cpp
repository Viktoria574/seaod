#include <iostream>
#include<cstdlib>
#include<ctime>
#include <string>

using namespace std;

struct MyNode {
    int data;
    MyNode* next;
};

void setList(MyNode*& L, int n) {
    MyNode* temp, * el = NULL;
    for (int i = 0; i < n; i++) {
        temp = new MyNode;
        // temp->data = 1 + (rand() % 9);
        cin>>temp->data;
        temp->next = NULL;
        if (i == 0) {
            L = temp;
        }
        else {
            el->next = temp;
        }
        el = temp;
    }
}

void getList(MyNode*& L) {
    MyNode* temp = L;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int searchMax(MyNode*& L) {
    MyNode* temp = L;
    int maxi = temp->data;
    while (temp != NULL) {
        if (maxi < temp->data) {
            maxi = temp->data;
        }
        temp = temp->next;
    }
    cout << "������������ �������� ������: " << maxi << endl;
    return maxi;
}

string findDouble(MyNode*& L){
    MyNode* temp = L,* compare;
    while(temp!=NULL){
        compare=temp->next;
        while (compare!=NULL){
            if (temp->data==compare->data){
                return "��� ���������� �������� ������������";
            }
            else{
                compare=compare->next;
            }
        }
        temp=temp->next;
    }
    return "���������� ��������� �� �������";
}

void deleteNodes(MyNode*& L, int value) {
    MyNode* temp = L;
    while (temp->next !=NULL ) {
        MyNode * nextNode = temp->next;
        if (temp->data==value){
            delete temp;
            temp->data= nextNode->data;
            temp->next=nextNode->next;
            delete nextNode->next;
        }
        else if(temp!=0 and nextNode->data==value){
            temp->next=nextNode->next;
            delete nextNode->next;
        }
        else{
            temp=temp->next;
        }
    }
    cout<<"������ ��� ������������� ��������:"<<endl;
}

void addition(MyNode*& L, int value){
    int m;
    MyNode* temp= L,* newValue;
    for (int i=1; i<=value; i++){
        if (i%2==0){
            newValue = new MyNode;
            m=20 + (rand() % 9);
            newValue->data=temp->data;
            temp->data=m;
            newValue->next=temp->next;
            temp->next=newValue;
            temp=newValue->next;
        }
        else{
            temp=temp->next;
        }
    }
}

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    srand((unsigned) time(NULL));
    int n, maxValue;
    cout << "������� ���������� ����� ������: " << endl;
    cin >> n;
    MyNode* myList = NULL;
    setList(myList, n);
    getList(myList);
    // cout<<findDouble(myList)<<endl;//�������� �� ���������� ��������
    maxValue = searchMax(myList);
    deleteNodes(myList, maxValue);//�������� ������������� ��������
    // addition(myList, n);//���������� �������� ����� ������� �����������
    getList(myList);
};