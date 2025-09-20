#include<iostream>
using namespace std;
#define size 100

class stack{
    int stk[size];
    int tos;
    public:
    void init();
    void push(int i);
    int pop();
};

void stack::init(){
    tos=0;
}

void stack::push(int i){
    if(tos==size){
        cout<<"stack is full\n";
        return;
    }
    stk[tos]=i;
    tos++;
}

int stack::pop(){
    if(tos==0){
        cout<<"stack is underflow\n";
    }
    tos--;
    return stk[tos];
}

int main(){
    stack stack1,stack2;
    stack1.init();
    stack2.init();
    stack1.push(2);
    stack2.push(3);
    stack1.push(5);
    stack2.push(7);
    stack1.push(9);
    stack2.push(6);
    cout<<stack1.pop();
    cout<<stack1.pop();
    cout<<stack1.pop();
    cout<<"\n";
    cout<<stack2.pop();
    cout<<stack2.pop();
    cout<<stack2.pop();
    return 0;
}