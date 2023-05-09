#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

void createMas(int* massive, int n){//заполняем рандомными числами
    for (int i=0; i<n; i++){
        massive[i]=rand()%100;
        //cin>>massive[i];
    }
}

void revers(int arr[], int size)
{
    for (int i = 0,j=size-1; i < (size/2); i++,j--)
    {
        int x = arr[i];
        arr[i] = arr[j];
        arr[j] = x;
    }
}

void Bubble(int* massive, int n){//���������� ������� �������
    int key, i, m, mi=0, ci=0;
    //auto start = chrono::high_resolution_clock::now();//������ ����� �������
    for (int j=1; j<n; j++){
        key=massive[j];
        mi+=1;
        for(i=j-1; i>=0 && massive[i]>key; i--){
            massive[i+1]=massive[i];
            ci+=1;
        }
        massive[i+1]=key;
    }
    //auto end = chrono::high_resolution_clock::now();//����� ����� �������
    //chrono::duration <double, micro> elapsed = end - start;
    //cout << "����� ����������: " << elapsed.count() << " � �������������" << endl;
    //cout<<ci<<"+"<<mi<<endl;
}

int main(){
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    int n;
    cout<<"������� ����� � �������?"<<endl;
    cin>>n;
    int massive[n];
    createMas(massive, n);
    //Bubble(massive, n);
    //revers(massive, n);
    Bubble(massive, n);
    cout<<"��������������� ������:"<<endl;
    for(int j=0; j<n; j++){
        cout<<massive[j]<<"  ";
    }
}