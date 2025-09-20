#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int k=n-i;k>0;k--){
            cout<<"*\t";
        }
        cout<<"\n";
    }
    return 0;
}