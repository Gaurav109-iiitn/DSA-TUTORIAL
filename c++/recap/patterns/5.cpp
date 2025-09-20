#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    for(int i=n;i>0;i--){
        for(int j=i;j<=n;j++){
            cout<<"*\t";
        }
cout<<"\n";
    }
    return 0;
}