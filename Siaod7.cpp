#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

struct table{
    int  speciality;//ключ
    string university;
};

//�����������:
//�� ���� �������� ������ ���������� � ����� table massive 
//� ������������� �������� key, ������� �������� � �������� �������
void LINEAR_SEARCH_SENTINEL(vector<table>massive, int key){
    table x;
    string answer="������ ������";
    int i=0, ci=0;
    x.speciality=key;
    massive.push_back(x);
    cout<<massive.size()<<endl;
    auto start = chrono::high_resolution_clock::now();
    while (x.speciality!=massive[i].speciality){
        if (i==massive.size()-2){
            answer="������ �� �����";
            ci+=1;
        }
        i++;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration <double, micro> elapsed = end - start;
    cout<<"�����"<<elapsed.count()<<endl;
    cout<<"������ ������";
    cout<<"Ci "<<ci;
}
//�����������

int main(){
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    int number, counter=0, key;
    string word;
    table x;
    vector <table> massive;
    cout<<"������� ���������� ��������������"<<endl;
    cin>>counter;
    while(counter>0){
        counter-=1;
        cin>>number>>word;
        x.speciality=number;
        x.university=word;
        massive.push_back(x);
    }
    //cout<<sizeof(x);
    cout<<"����� ������������� �����?"<<endl;
    cin>>key;
    LINEAR_SEARCH_SENTINEL(massive, key);
};