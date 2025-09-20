#include<iostream>
using namespace std;
class e{
    int x;
    void read(){
        cout<<x<<endl;
    }
    public:
     e(int i){
       x=i; 
    }
    void update();
};
void e::update(){
    read();
}
int main(){
    e s1(8);
s1.update();
return 0;
}