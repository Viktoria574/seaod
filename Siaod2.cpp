#include <iostream>
#include<ctime>
#include <string>

using namespace std;

struct MyNode {//структура узла
    int data;
    MyNode* next;//указатель на следующий элемент в списке
};

void setList(MyNode*& L, int n) {//функция заполнения списка данными
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

void getList(MyNode*& L) {//вывод списка
    MyNode* temp = L;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int searchMax(MyNode*& L) {//функция нахождения максимального элемента списка
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

string findDouble(MyNode*& L){//функция проверки на одинаковые элементы
    MyNode* temp = L,* compare;
    while(temp!=NULL){
        compare=temp->next;
        while (compare!=NULL){
            if (temp->data==compare->data){
                return "Два одинаковых элемента присутствуют";
            }
            else{
                compare=compare->next;
            }
        }
        temp=temp->next;
    }
    return "Одинаковых элементов не найдено";
}

int deleteNodes(MyNode*& L, int value, int n) {//функция удаления максимального элемента из списка
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
    cout<<"Список без максимального элемента:"<<endl;
    return n;
}

void addition(MyNode*& L, int value){//добавление элемента перед четной позицией
    int m;
    MyNode* temp= L,* newValue;
    for (int i=1; i<=value; i++){
        if (i%2==0){
            newValue = new MyNode;
            cout<<"Введите дополнительные элементы для списка"<<endl;
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
    cout << "Введите количество узлов списка: " << endl;
    cin >> n;
    MyNode* myList = NULL;
    cout << "Введите элементы списка списка: " << endl;
    setList(myList, n);
    cout<<findDouble(myList)<<endl;//проверка на одинаковые элементы
    maxValue = searchMax(myList);
    n=deleteNodes(myList, maxValue, n);//удаление максимального элемента
    getList(myList);
    addition(myList, n);//добавление элемента перед четными указателями
    cout<<"Новый список:";
    getList(myList);
    // peremena(myList);
    // getList(myList);
};