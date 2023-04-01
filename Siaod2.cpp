#include <iostream>
#include<ctime>
#include <string>

using namespace std;

struct MyNode {//��������� ����
    int data;
    MyNode* next;//��������� �� ��������� ������� � ������
};

void setList(MyNode*& L, int n) {//������� ���������� ������ �������
    MyNode* temp, * el = NULL;
    for (int i = 0; i < n; i++) {
        temp = new MyNode;
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

void getList(MyNode*& L) {//����� ������
    MyNode* temp = L;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int searchMax(MyNode*& L) {//������� ���������� ������������� �������� ������
    MyNode* temp = L;
    int maxi = temp->data;
    while (temp != NULL) {
        if (maxi < temp->data) {
            maxi = temp->data;
        }
        temp = temp->next;
    }
    return maxi;
}

string findDouble(MyNode*& L){//������� �������� �� ���������� ��������
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

int deleteNodes(MyNode*& L, int value, int n) {//������� �������� ������������� �������� �� ������
    MyNode* temp = L;
    while (temp->next !=NULL ) {
        MyNode * nextNode = temp->next;
        if (temp->data==value){
            delete temp;
            temp->data= nextNode->data;
            temp->next=nextNode->next;
            delete nextNode->next;
            n-=1;
        }
        else if(temp!=0 and nextNode->data==value){
            temp->next=nextNode->next;
            delete nextNode->next;
            n-=1;
        }
        else{
            temp=temp->next;
        }
    }
    cout<<"������ ��� ������������� ��������:"<<endl;
    return n;
}

void addition(MyNode*& L, int value){//���������� �������� ����� ������ ��������
    int m;
    MyNode* temp= L,* newValue;
    for (int i=1; i<=value; i++){
        if (i%2==0){
            newValue = new MyNode;
            cout<<"������� �������������� �������� ��� ������"<<endl;
            cin>>m;
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

// void peremena(MyNode*& L){
//     MyNode* temp= L,* predValue=nullptr;
//     while (temp->next!=NULL){
//         predValue=temp;
//         temp=temp->next;
//     }
//     predValue->next=NULL;
//     temp->next=L;
//     L=temp;
// }

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    int n, maxValue;
    cout << "������� ���������� ����� ������: " << endl;
    cin >> n;
    MyNode* myList = NULL;
    cout << "������� �������� ������ ������: " << endl;
    setList(myList, n);
    cout<<findDouble(myList)<<endl;//�������� �� ���������� ��������
    maxValue = searchMax(myList);
    n=deleteNodes(myList, maxValue, n);//�������� ������������� ��������
    getList(myList);
    addition(myList, n);//���������� �������� ����� ������� �����������
    cout<<"����� ������:";
    getList(myList);
    // peremena(myList);
    // getList(myList);
};