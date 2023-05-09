#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

float Fact(int i){
    if (i>0){
        return i*Fact(i-1);
    }
    else{
        return 1;
    }
}

float TelorItemCos(float x, int n){
    if (n==0){
        return 1;
    }
    else{
        return -TelorItemCos(x, n-1)*pow(x, 2)/((2*n-1)*(2*n));
    }
}

float FunCos(float x, float e){
    float item, result=0;
    int n=0;
    item=TelorItemCos(x, n);
    while (abs(item)>e and not(isnan(result))){
        result+=item;
        n+=1;
        item=TelorItemCos(x, n);
    }
    return result+item;
}

int main(){
    float x, e, ost=0;
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    cout<<"¬ведите точность e:"<<endl;
    cin>>e;
    cout<<"¬ведите x:"<<endl;
    cin>>x;
    ost=x/(2*M_PI);
    if (ost!=0){
        x=x-trunc(ost)*2*M_PI;
    }
    cout<<"cos(x)="<<FunCos(x, e);
}