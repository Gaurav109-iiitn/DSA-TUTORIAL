#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int k=0;k<i;k++){
            cout<<" ";
        }
        for(int j=n-i;j>0;j--){
            cout<<i+1;
        }
        cout<<"\n";
    }
return 0;
}