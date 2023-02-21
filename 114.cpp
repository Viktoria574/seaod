#include <iostream>

using namespace std;

int main(){
    int n, counter=0;
    cin>>n;
    if (n==0){
        counter+=1;
    }
    while (n>0){
        counter+=1;
        n=n/10;
    }
    cout<<"Number of digits: "<<counter;
}