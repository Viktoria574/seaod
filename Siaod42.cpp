#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Chars {
   char data;
   Chars* next;
};

void setList(Chars*& L, int n) {
    Chars* temp, * el = NULL;
    for (int i = 0; i < n; i++) {
        temp = new Chars;
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

void getList(Chars*& L) {
    Chars* temp = L;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

string CheckWord(Chars* first, Chars* last){
    string a(1, first->data);
    if (first->next!=last->next){
        return a+CheckWord(first->next, last);
    }
    else{
        return a;
    }
}


int main(){
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    int length;
    cout<<"¬ведиет длину списка:"<<endl;
    cin>>length;
    Chars* Kit = NULL;
    Chars* temp = Kit;
    setList(temp, length);
    cout<<CheckWord(temp, (temp->next)->next);
}