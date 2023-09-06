#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

struct table{
    int  speciality;//Р В РЎвЂќР В Р’В»Р РЋР вЂ№Р РЋРІР‚РЋ
    string university;
};

void Chose(vector<table> massive, int m) {//
    int mini, mi = 0, ci = 0, count=1, n;
    for (int j = m - 1; j > 0; j--) {
        n=j+1;
        count=1;
        while (count != 0) {
            count = 0;
            for (int i = 0; i < (n - 1) / 2 + (n - 1) % 2; i++) {
                ci += 1;
                if (massive[i].speciality < massive[2 * i + 1].speciality) {
                    swap(massive[i], massive[2 * i + 1]);
                    count++;
                    mi += 1;
                }
                if (2 * i + 2 < n and massive[i].speciality < massive[2 * i + 2].speciality) {
                    swap(massive[i], massive[2 * i + 2]);
                    count++;
                    mi += 1;
                }
            }
        }
        swap(massive[0], massive[j]);
        mi += 1;
    }
}

void BINARY_SEARCH(vector<table>massive, int key){
    int left=1, right=massive.size(), flag=0, d, ci=0;
    auto start = chrono::high_resolution_clock::now();
    while(left<=right and flag==0){
        d=(left+right)/2;
        if (massive[d].speciality==key){
            flag=1;
            ci+=1;
        }
        else{
            if (key>massive[d].speciality)
                left=d+1;
            else
                right=d-1;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration <double, micro> elapsed = end - start;
    //cout<<"Время"<<elapsed.count()<<endl;
    if(flag==1)
        cout<<"Объект найден"<<endl;
    else
        cout<<"Объект не найден"<<endl;
    cout<<"Ci "<<ci;
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

    cout<<"Что искать?"<<endl;
    cin>>key;
    Chose(massive, massive.size());
    BINARY_SEARCH(massive, key);
};