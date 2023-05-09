#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    int N, maxi=-100000, mini=100000, indexMin1, indexMin2, indexMax1, indexMax2, number, sumi=0, index;
    cout<<"Введите количество элементов в массиве:"<<endl;
    cin>>N;
    int *massive = new int[N];
    for (int i=0; i<N; i++){
        cout<<"Введите "<<i+1<<" элемент:"<<endl;
        cin>>number;
        massive[i]=number;
        if (number==maxi){
            indexMax2=i;
        }
        else if(number>maxi){
            maxi=number;
            indexMax1=i;
            indexMax2=i;
        }
        if(number<mini){
            mini=number;
            indexMin1=i;
            indexMin2=i;
        }
        else if(number==mini){
            indexMin2=i;
        }
    }
    for (int j=min({indexMax1, indexMin1}); j<=max({indexMax2, indexMin2}); j++){
        sumi+=massive[j];
    }
    cout<<"Сумма:"<<sumi;
}