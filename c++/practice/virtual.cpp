#include<iostream>
using namespace std;

class base{
    int x;
    public:
    base(int i){
        x=i;
    }
    virtual void func(){
        cout<<"using base version of function"<<endl;
       cout<<"x"<<endl;
    }
};

class derived1:public base{
    int x;
    public:
    derived1(int i){ x=i;}
    
}