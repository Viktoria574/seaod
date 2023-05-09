#include <iostream>
#include <string>
#include <sstream>
#include<cstring>

using namespace std;

struct Chars {
    char data;
    Chars* next;
};

void setList(Chars*& L, int n) {
    Chars* temp, * el = NULL;
    for (int i = 0; i < n; i++) {
        temp = new Chars;
        cin >> temp->data;
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

string CheckWord(Chars* first, Chars* last) {
    string a(1, first->data);
    if (first->next != last->next) {
        return a + CheckWord(first->next, last);
    }
    else {
        return a;
    }
}

int Last(string str) {
    string rev;
    for (int i = str.size() - 1; i >= 0; i--) {
        rev = rev.append(1, str[i]);
    }
    if (rev==str){
        return 2;
    }
}

bool VariousWords(Chars* temp) {
    string str;
    Chars* nexti = temp->next;
    while (temp->next != NULL) {
        while (nexti != NULL) {
            str=CheckWord(temp, nexti);
            if(Last(str)==2){
                return true;
            }
            nexti = nexti->next;
        }
        temp = temp->next;
        nexti = temp->next;
    }
    return false;
}

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    int length;
    cout<<"—колько букв в слове?:"<<endl;
    cin>>length;
    Chars* Kit = NULL;
    Chars* temp = Kit;
    cout<<"¬ведите буквы:"<<endl;
    setList(temp, length);
    if(VariousWords(temp)){
        cout<<"ѕалиндром есть в строке!";
    }
    else{
        cout<<"ѕалиндрома нет в строке";
    }
}