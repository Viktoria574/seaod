#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
 
#define SIGNAL_D( signal_f ) ( TYPE_SIGNAL ) ( & signal_f )
#define HENDLER_D( hendler_f ) ( TYPE_HANDLER ) ( & hendler_f )

//#include "cl_base.h"

class cl_base{
    string s_object_name;
    cl_base* p_head_object;
    vector <cl_base*> subordinate_objects;
    int countNames(string n);
    cl_base* searchByName(string n);
    cl_base* getRoot();
    int ready=0;
    void kill();

    public:
        //КВ4
        typedef void ( cl_base :: * TYPE_SIGNAL ) ( string & );
        typedef void ( cl_base :: * TYPE_HANDLER ) ( string );

        struct o_sh                 
        {
            TYPE_SIGNAL  p_signal;    
            cl_base    * p_cl_base;   
            TYPE_HANDLER p_hendler;
        };
        vector < o_sh * > connects;
        virtual void signal_f(string &usd);
        virtual void hendler_f(string);

        cl_base(cl_base* p_head_object, string s_object_name="Base object");
        bool chekName(string new_name);
        string getName();
        cl_base* getHead();
        void printObjects(string str);
        cl_base* getSubOb(string sName);
        cl_base* searchCurrent(string n);
        //void printOb(string str);
        void setReady(int offing, string ob_name);
        int getReady();
        cl_base* TransletPath(string str);
        bool Delete(string str);
        bool ReBuild(cl_base* newSt);
        
        //КВ4
        string CreatPath();
        void set_connect(TYPE_SIGNAL p_signal, cl_base *p_object, TYPE_HANDLER p_ob_hendler);
        void delete_connect(TYPE_SIGNAL p_signal, cl_base *p_object, TYPE_HANDLER p_ob_hendler);
        void emit_signal ( TYPE_SIGNAL p_signal, string & s_command );

        ~cl_base();
};

//КВ4

void cl_base:: signal_f(string &usd){
    cout<<endl<<"Signal from "<<this->CreatPath();
};

void cl_base:: hendler_f(string str){
    cout<<"Bye cl_base";
}

string cl_base:: CreatPath(){//создание абсолютного пути
    string answer="";
    cl_base *path=this;
    while(path!=getRoot()){
        answer=path->getName()+'/'+answer;
        path=path->getHead();
    }
    return '/'+answer;
}

void cl_base:: set_connect(TYPE_SIGNAL p_signal, cl_base *p_object, TYPE_HANDLER p_ob_hendler){//метод установки связи
    o_sh *p_value;
    for(unsigned int i=0; i<connects.size(); i++){
        if(connects[i]->p_signal==p_signal && connects[i]->p_cl_base==p_object && connects[i]->p_hendler==p_ob_hendler){
            return;
        }
    }
    p_value= new o_sh();
    
    p_value->p_signal=p_signal;
    p_value->p_cl_base=p_object;
    p_value->p_hendler=p_ob_hendler;

    connects.push_back(p_value);
}

void cl_base:: delete_connect(TYPE_SIGNAL p_signal, cl_base *p_object, TYPE_HANDLER p_ob_hendler){//метод удаление связи
    for(unsigned int i=0; i<connects.size(); i++){
        if(connects[i]->p_signal==p_signal && connects[i]->p_cl_base==p_object && connects[i]->p_hendler==p_ob_hendler){
            connects.erase(connects.begin()+i);
        }
    }
}

void cl_base :: emit_signal ( TYPE_SIGNAL p_signal, string & s_command )
{
    TYPE_HANDLER   p_handler;
    cl_base      * p_object;

    //if (this->ready!=0){
        ( this ->* p_signal ) ( s_command );  // вызов метода сигнала
    
    for ( unsigned int i = 0; i < connects.size ( ); i ++ ) // цикл по всем обработчикам
    {
            if ( connects [ i ] -> p_signal == p_signal )      // определение допустимого обработчика
            {                               
                p_handler = connects [ i ] -> p_hendler;
                p_object  = connects [ i ] -> p_cl_base;
    
                ( p_object ->* p_handler ) ( s_command );      // вызов метода обработчика
            }
        }
    //}
    //else
        //return;
}

//Конец

class cl_application: public cl_base
{
    void off_tree_objects();
    public:
    cl_application(cl_base* p_head_object);
    void build_tree_objects();
    int exec_app();
    //void ending();
};

class cl_1: public cl_base
{
    public:
        cl_1(cl_base *p_head, string s_name);
};

class cl_2: public cl_base
{
    public:
        cl_2(cl_base *p_head, string s_name);
        void signal_f(string &usd);
        void hendler_f(string);
};

class cl_3: public cl_base
{
    public:
        cl_3(cl_base *p_head, string s_name);
        void signal_f(string &usd);
        void hendler_f(string);
};

class cl_4: public cl_base
{
    public:
        cl_4(cl_base *p_head, string s_name);
};

class cl_5: public cl_base
{
    public:
        cl_5(cl_base *p_head, string s_name);
};

class cl_6: public cl_base
{
    public:
        cl_6(cl_base *p_head, string s_name);
};

cl_1::cl_1(cl_base* p_head, string s_name):cl_base(p_head, s_name){};

cl_2::cl_2(cl_base* p_head, string s_name):cl_base(p_head, s_name){};

void cl_2:: signal_f(string &usd){
    usd+=" (class: 2)";
    cl_base::signal_f(usd);
};

void cl_2:: hendler_f(string str){
    cout<<endl<<"Signal to "<<this->CreatPath()<<" Text:"<<str;
}

cl_3::cl_3(cl_base* p_head, string s_name):cl_base(p_head, s_name){};

void cl_3:: signal_f(string &usd){
    usd+=" (class: 3)";
    cl_base::signal_f(usd);
}

void cl_3:: hendler_f(string str){
    cout<<endl<<"Signal to "<<this->CreatPath()<<" Text:"<<str;
}

cl_4::cl_4(cl_base* p_head, string s_name):cl_base(p_head, s_name){};

cl_5::cl_5(cl_base* p_head, string s_name):cl_base(p_head, s_name){};

cl_6::cl_6(cl_base* p_head, string s_name):cl_base(p_head, s_name){};

cl_base::cl_base(cl_base* p_head_object, string s_object_name)
{
    this->p_head_object=p_head_object;
    this->s_object_name=s_object_name;
    if ( p_head_object )
    {
        p_head_object -> subordinate_objects.push_back ( this );
    }
}

bool cl_base::chekName(string new_name)
{
    if (p_head_object){
        for (int i=0; i<p_head_object->subordinate_objects.size();i++){
            if(p_head_object->subordinate_objects[i]->s_object_name==new_name){
            return false;
            }
        }
    }
    s_object_name=new_name;
    return true;
}

string cl_base::getName(){
    return this->s_object_name;
}

cl_base* cl_base::getHead(){
    return this->p_head_object;
}

void cl_base::printObjects(string str){
    for(int i=0; i<subordinate_objects.size();i++){
        cout<<endl<<str<<this->subordinate_objects[i]->s_object_name;
        if(this->subordinate_objects[i]->subordinate_objects.size()!=0)
            this->subordinate_objects[i]->printObjects(str+" ");
    }
}

cl_base* cl_base::getSubOb(string sName){
    for (int i=0; i<this->subordinate_objects.size(); i++){
        if (this->subordinate_objects[i]->s_object_name==sName){
        return subordinate_objects[i];
        }
    }
    return nullptr;
}

cl_base* cl_base::searchByName(string n)
{
    if(getName()==n)
        return this;
    cl_base* p_found=nullptr;
    for (int i=0; i<subordinate_objects.size(); i++){
        p_found=subordinate_objects[i]->searchByName(n);
        if (p_found!=nullptr){
            return p_found;
        }
    }
    return p_found;
}

int cl_base:: countNames(string n)
{
    int count=0;
    if (getName()==n)
        count++;
    for (int i=0; i<subordinate_objects.size(); i++)
        count+=subordinate_objects[i]->countNames(n);
    return count;
}

cl_base* cl_base::searchCurrent(string n)
{
    if(countNames(n)!=1)
        return nullptr;
    return searchByName(n);
}

//КВ3

cl_base* cl_base::getRoot(){
    cl_base* root=this;
    while(root->getHead()!=nullptr){
        root=root->getHead();
    }
    return root;
}

cl_base* cl_base:: TransletPath(string str){
    string answer="";
    if (str==("/")){
        return getRoot();
    }
    else if(str[0]==('/') && str[1]==('/')){
        cl_base* p=getRoot();
        str.erase(0,2);
        return p->searchCurrent(str);
    }
    else if(str[0]==('/') && str[1]!=('/')){
        str.erase(0,1);
        cl_base* p=getRoot();
        while(str.size()>0){
            if (str[0]=='/'){
                p=p->getSubOb(answer);
            if (p==nullptr){
                return p;
            }
            answer="";
        }
            else
                answer+=str[0];
            str.erase(0,1);
        }
        p=p->getSubOb(answer);
        return p;
    }
    else if(str==(".")){
        return this;
    }
    else if(str[0]==('.')){
        str.erase(0,1);
        return searchByName(str);
    }
    else{
        cl_base* p=this;
        while(str.size()>0){
            if (str[0]=='/'){
                p=p->getSubOb(answer);
                if (p==nullptr)
                    return p;
                answer="";
            }
            else
                answer+=str[0];
            str.erase(0,1);
        }
        p=p->getSubOb(answer);
        return p;
    }
}

bool cl_base::Delete(string str){
    cl_base* p=getSubOb(str);
    if(p==nullptr)
        return false;
    for (int i=0; i<subordinate_objects.size(); i++){
        if (p==subordinate_objects[i])
            subordinate_objects.erase(subordinate_objects.begin()+i);
    }
    delete p;
    return true;
}

bool cl_base::ReBuild(cl_base* newSt){
    cl_base* newi=this;
    cl_base* parent=newi->getHead();
    if (parent!=nullptr){
        newSt->subordinate_objects.push_back(newi);
    for (int i=0; i<parent->subordinate_objects.size(); i++){
        if (newi==parent->subordinate_objects[i])
            parent->subordinate_objects.erase(parent->subordinate_objects.begin()+i);
    }
    return true;
    }
    return false;
}

//КВ2

void cl_base::kill(){
    for(int i=0; i<subordinate_objects.size(); i++){
        subordinate_objects[i]->ready=0;
        if(this->subordinate_objects[i]->subordinate_objects.size()!=0)
            subordinate_objects[i]->kill();
    }
}

void cl_base::setReady(int offing, string ob_name){
    cl_base* p;
    p=getHead();
    if (offing!=0){
        while(p!=nullptr){
            if(!getHead()->getReady()){
                ready=0;
                return;
            }
            ob_name=p->getName();
            p=p->getHead();
        }
        ready=offing;
    }
    else{
        kill();
        ready=offing;
    }
}

int cl_base::getReady(){
    return ready;
}

cl_base::~cl_base()
{
    for (int i=0; i<subordinate_objects.size();i++)
    {
        delete subordinate_objects[i];
    }
}

cl_application::cl_application(cl_base* p_head_object): cl_base(p_head_object){};

void cl_application::build_tree_objects()
{
    string s_head_name, s_sub_name;
    int classId;
    cl_base* p_head=this;
    cl_base* p_sub=nullptr;
    cin>>s_head_name;
    this->chekName(s_head_name);
    while(true){
        cin>>s_head_name;
        if (s_head_name=="endtree")
        {
            cout<<"Object tree"<<endl;
            cout<<this->getName();
            this->printObjects(" ");
            off_tree_objects();
            return;
        }
        cin>>s_sub_name>>classId;
        p_head=TransletPath(s_head_name);
        if(p_head==nullptr){
            cout<<"Object tree"<<endl;
            cout<<this->getName();
            this->printObjects(" ");
            cout<<endl<<"The head object "<<s_head_name<<" is not found";
            exit(1);
        }
        else if (p_head->getSubOb(s_sub_name)!=nullptr){
            cout<<s_head_name<<" Dubbing the names of subordinate objects"<<endl;
        }
        else{
            switch(classId)
            {
            case 2:
            p_sub=new cl_2(p_head, s_sub_name);
            break;
            case 3:
            p_sub=new cl_3(p_head, s_sub_name);
            break;
            case 4:
            p_sub=new cl_4(p_head, s_sub_name);
            break;
            case 5:
            p_sub=new cl_5(p_head, s_sub_name);
            break;
            case 6:
            p_sub=new cl_6(p_head, s_sub_name);
            break;
            }
        }
    }
}

void cl_application:: off_tree_objects(){
    string comanda, obPut, obOut;
    cl_base *ob_head=this;
    cl_base *ob_sub=this;
    while(true){
        cin>>comanda;
        if (comanda=="END"){
            return;
        }
        cin>>obPut>>obOut;
        ob_head=TransletPath(obPut);
        ob_sub=TransletPath(obOut);
        if (ob_head==nullptr){
            cout<<endl<<"Object "<<obPut<<" not found";
        }
        else if(ob_sub==nullptr and comanda!="EMIT"){
            cout<<endl<<"Handler object"<<obOut<<"not found";
        }
        else{
            if (comanda=="SET_CONNECT"){
                ob_head->set_connect(SIGNAL_D( signal_f ), ob_sub, HENDLER_D( hendler_f ));
            }
            else if (comanda=="EMIT"){
                 ob_head->emit_signal ( SIGNAL_D( signal_f ), obOut);
            }
        }
    }
}
int cl_application::exec_app(){
cout<<endl<<"Current object hierarchy tree"<<endl;
cout<<this->getName();
this->printObjects(" ");
return 0;
}

int main()
{
    cl_application ob_cl_application(nullptr);
    ob_cl_application.build_tree_objects();
    return ob_cl_application.exec_app();
}