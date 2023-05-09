#include <iostream>
 
 using namespace std;

 int main(){
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    int n, counter=1, number=1, saveN;
    cout<<"������� ������ �������:"<<endl;
    cin>>n;
    saveN=n;
    int **massive = new int*[n];
    for (int k=0; k<n; k++){
        massive[k]=new int [k+1];
    }
    while (number<saveN*saveN+1){
        if (counter==1){
            for (int i=saveN-n; i<n; i++){
                massive[saveN-n][i]=number;
                number+=1;
            }
            n-=1;
        }
        else if (counter==2){
            for (int i=saveN-n; i<n+1; i++){
                massive[i][n]=number;
                number+=1;
            }
        }
        else if (counter==3){
            for (int i=saveN-n; i<n+1; i++){
                massive[n][saveN-1-i]=number;
                number+=1;
            }
        }
        else{
            for (int i=saveN-n; i<n; i++){
                massive[saveN-1-i][saveN-n-1]=number;
                number+=1;
                counter=0;
            }
        }
        counter+=1;
        cout<<"�������:"<<endl;
        for(int i=0;i<saveN; i++){
            for (int j=0; j<saveN; j++){
                cout<<massive[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    cout<<"�������:"<<endl;
    for(int i=0;i<saveN; i++){
        for (int j=0; j<saveN; j++){
            cout<<massive[i][j]<<" ";
        }
        cout<<endl;
    }
 }