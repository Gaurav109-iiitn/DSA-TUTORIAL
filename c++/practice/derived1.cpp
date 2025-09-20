#include<iostream>
using namespace std;
class base {
 int a;
 public:
 void seta(int i){
 a=i;
 }
 int geta(){
    return a;
 }
    };

class derived:public base{
    int b;
    public:
    void setb(int i){
        b=i;
    }
    int getb(){
        return b;
    }
};
int main(){
    class base* b;
    class base b_ob;
    class derived d_ob; 
    b=&b_ob;
    b->seta(7);
    cout<<"base object a"<<b->geta()<<endl;
    b=&d_ob;
    b->seta(4);
    cout<<"derived object a"<<d_ob.geta()<<endl;
    d_ob.setb(5);
    cout<<"derived object b"<<d_ob.getb()<<endl;
    return 0;
}
