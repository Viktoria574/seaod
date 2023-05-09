#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

class cl_base{
    string s_object_name;
    cl_base* p_head_object;
    vector <cl_base*> subordinate_objects;
    int countNames(string n);
    cl_base* searchByName(string n);
    cl_base* getRoot();
    int ready=0;
    void kill();

    //КВ4
    #define SIGNAL_D( signal_f ) ( TYPE_SIGNAL ) ( & signal_f )
    #define HENDLER_D( hendler_f ) ( TYPE_HANDLER ) ( & hendler_f )

    typedef void ( cl_base :: * TYPE_SIGNAL ) ( string & );
    typedef void ( cl_base :: * TYPE_HANDLER ) ( string );
    struct o_sh                 
    {
        TYPE_SIGNAL  p_signal;    
        cl_base    * p_cl_base;   
        TYPE_HANDLER p_hendler;
    };
    vector < o_sh * > connects;

    public:
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
        string CreatPath(cl_base* path);
        void set_connect(TYPE_SIGNAL p_signal, cl_base *p_object, TYPE_HANDLER p_ob_hendler);
        void delete_connect(TYPE_SIGNAL p_signal, cl_base *p_object, TYPE_HANDLER p_ob_hendler);
        void emit_signal ( TYPE_SIGNAL p_signal, string & s_command );

        ~cl_base();
};