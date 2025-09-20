#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int k=0;k<i;k++){
        cout<<" \t";
        }
        for(int l=i;l<n;l++){
            cout<<"*\t"<<" \t";
        }
        cout<<"\n";
    }
    return 0;
}