#include <iostream>
 
 using namespace std;

 int main(){
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    int n, counter=1, number=1, saveN;
    cout<<"Введите размер матрицы:"<<endl;
    cin>>n;
    saveN=n;
    int massive[n][n];
    while (number!=saveN*saveN+1){
        if (counter==1){
            for (int i=0; i<n; i++){
            massive[saveN-n][i]=number;
            number+=1;
            n-=1;
            //cout<<massive[i][n]<<" "<<number<<endl;
            }
        }
        else if (counter==2){
            for (int i=saveN-n; i<n; i++){
                massive[i][n]=number;
                number+=1;
            }
        }
        else if (counter==3){
            for (int i=saveN-n; i<n; i++){
                massive[n][n-i]=number;
                number+=1;
            }
        }
        else{
            for (int i=saveN-n-1; i<n; i++){
            massive[n-i][n]=number;
            number+=1;
            counter=0;
            }
        }
        counter+=1;
        cout<<"Матрица:"<<endl;
        for(int i=0;i<saveN; i++){
            for (int j=0; j<saveN; j++){
                cout<<massive[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    cout<<"Матрица:"<<endl;
    for(int i=0;i<saveN; i++){
        for (int j=0; j<saveN; j++){
            cout<<massive[i][j]<<" ";
        }
        cout<<endl;
    }
 }