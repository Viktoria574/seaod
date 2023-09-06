#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

struct table{
    int  speciality;//РєР»СЋС‡
    string university;
};

//Предусловие:
//На вход подается массив переменных с типом table massive 
//и целочисленный параметр key, который задается в основной функции
void LINEAR_SEARCH_SENTINEL(vector<table>massive, int key){
    table x;
    string answer="Объект найден";
    int i=0, ci=0;
    x.speciality=key;
    massive.push_back(x);
    cout<<massive.size()<<endl;
    auto start = chrono::high_resolution_clock::now();
    while (x.speciality!=massive[i].speciality){
        if (i==massive.size()-2){
            answer="Объект не найен";
            ci+=1;
        }
        i++;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration <double, micro> elapsed = end - start;
    cout<<"Время"<<elapsed.count()<<endl;
    cout<<"Объект найден";
    cout<<"Ci "<<ci;
}
//Постусловие

int main(){
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    int number, counter=0, key;
    string word;
    table x;
    vector <table> massive;
    cout<<"Введите количество специальностей"<<endl;
    cin>>counter;
    while(counter>0){
        counter-=1;
        cin>>number>>word;
        x.speciality=number;
        x.university=word;
        massive.push_back(x);
    }
    //cout<<sizeof(x);
    cout<<"Какую специальность найти?"<<endl;
    cin>>key;
    LINEAR_SEARCH_SENTINEL(massive, key);
};