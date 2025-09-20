#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int k=i+1;k>0;k--){
            cout<<k;
        }
        cout<<"\n";
    }
    return 0;
}