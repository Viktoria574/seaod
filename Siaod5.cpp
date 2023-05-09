#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

void createMas(int* massive, int n){//��������� ���������� �������
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

void Bubble(int* massive, int n){//���������� ���������
    int m, mi=0, ci=0;
    //auto start = chrono::high_resolution_clock::now();//������ �������� �������
    for(int j=0; j<n-1; j++){
        for (int i=0; i<n-j-1; i++){
            mi+=1;
            if (massive[i]>massive[i+1]){
                m=massive[i];
                massive[i]=massive[i+1];
                massive[i+1]=m;
                ci+=1;
            }
        }
    }
    //auto end = chrono::high_resolution_clock::now();//����� �������� ������� 
    //chrono::duration <double, micro> elapsed = end - start;
    //cout << "����� ����������: " << elapsed.count() << " �����������" << endl;
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