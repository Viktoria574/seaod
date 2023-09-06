#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

struct table{
    int  speciality;//Р С”Р В»РЎР‹РЎвЂЎ
    string university;
};

void leaner_search(vector<table>massive, int key){
    int i=0, ci=0;
    string answer="Объект не найден";
    auto start = chrono::high_resolution_clock::now();
    for(i==0; i<massive.size(); i++){
        if (massive[i].speciality==key){
            answer=massive[i].university;
            break;
        }
        ci+=1;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration <double, micro> elapsed = end - start;
    cout<<"Время работы программы"<<elapsed.count()<<endl;
    cout<<answer<<endl;
    cout<<ci;
}

int main(){
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    int number, counter=0, key;
    string word;
    table x;
    vector <table> massive;
    cout<<"Сколько чисел в массиве?"<<endl;
    cin>>counter;
    while(counter>0){
        counter-=1;
        cin>>number>>word;
        x.speciality=number;
        x.university=word;
        massive.push_back(x);
    }

    cout<<"Что нужно искать?"<<endl;
    cin>>key;
    leaner_search(massive, key);
};