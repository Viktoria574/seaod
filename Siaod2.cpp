#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

struct MyNode {
    int data;
    MyNode* next;//СѓРєР°Р·Р°С‚РµР»СЊ РЅР° СЃР»РµРґСѓС‰РёР№ СЌР»РµРјРµРЅС‚
};

void setList(MyNode*& L, int n) {
    MyNode* temp, * el = NULL;
    for (int i = 0; i < n; i++) {
        temp = new MyNode;
        temp->data = 1 + (rand() % 9);
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
    return maxi;
}

void deleteNodes(MyNode*& L, int value) {
    MyNode* temp = L, * nextNode = temp->next;
    while (nextNode != NULL) {
        if (temp->data == value) {
            delete temp;
            temp = nextNode;
            nextNode = nextNode->next;
            L = temp;
        }
        if (nextNode->data == value) {
            temp->next = nextNode->next;
            delete nextNode;
        }
        temp = temp->next;
        nextNode = temp->next;
    }
}

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    srand((unsigned) time(NULL));
    int n, maxValue;
    cout << "Введите количество узлов списка: " << endl;
    cin >> n;
    MyNode* myList = NULL;
    setList(myList, n);
    getList(myList);
    maxValue = searchMax(myList);
    cout << "Максимальное значение списка: " << maxValue << endl;
    deleteNodes(myList, maxValue);
    getList(myList);
};