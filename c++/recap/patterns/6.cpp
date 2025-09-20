#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int k=n-i-1;k>0;k--){
            cout<<" "<<"\t";
        }
        for(int o=n-1-i;o<n;o++){
            cout<<"*"<<"\t";
        }
        cout<<"\n";
    }
    return 0;
    }