#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    for(int i=2;i*i<n;i++){
        if(n%i==0){
            cout<<"not prime";
            return 0;
        }
    }
    cout<<"prime";
    return 0;
}