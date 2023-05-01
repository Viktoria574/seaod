#include <iostream>
#include <stack>
#include <string>
#include <math.h>

using namespace std;

struct Numbers {//атд
   float data;
   Numbers* next;
};

void setNum(Numbers*& N, float chislo){//заполнение списка
   Numbers* temp=N, * oop;
   oop = new Numbers;
   if (N!=NULL){
      oop->data=temp->data;
      temp->data=chislo;
      oop->next=temp->next;
      temp->next=oop;
   }
   else{
      oop->data=chislo;
      oop->next = NULL;
      N = oop;
   }
};

void pod(Numbers*& N, char znak){//реализация действий над элементами
   Numbers* temp=N, * nextValue=temp->next;
   switch((int)(znak)){
      case (int)('+'):
         temp->data=temp->data+nextValue->data;
         break;
      case (int)('-'):
         temp->data=nextValue->data-temp->data;
         break;
      case (int)('*'):
         temp->data=temp->data*nextValue->data;
         break;
      case (int)('/'):
         temp->data=nextValue->data/temp->data;
         break;
      case (int)('^'):
         temp->data=pow(nextValue->data, temp->data);
         break;
   }
   temp->next=nextValue->next;
   delete nextValue->next;
}

void print(Numbers*& N){//вывод первого элемента в списке
   Numbers* temp=N;
   cout<<temp->data;
}

void opening(string postfix, string opera, Numbers*& Num){//функция для разлечения операций и операндов
   while (postfix[0]!=NULL){
      if (opera.find(postfix[0])!=-1){
         pod(Num, postfix[0]);
      }
      else{
         setNum(Num, float((int)(postfix[0])-48));
      } 
      postfix.erase(0, 1);
   }
}

int main(){
   string postfix, opera="+-*/^";
   system("chcp 1251");
   setlocale(LC_ALL, "Russian");
   Numbers* Num = NULL;
   cout<<"Введите постфиксное выражение:"<<endl;
   cin>>postfix;
   opening(postfix, opera, Num);
   cout<<"Ответ:";
   print(Num);
}