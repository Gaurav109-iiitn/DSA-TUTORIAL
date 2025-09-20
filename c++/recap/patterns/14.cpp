#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    for(int i=0;i<n;i++){
    for(int j=n-i;j>0;j--){
        cout<<" ";
    }
    for(int k=1;k<=i+1;k++){
        cout<<k;
    }
    if(i>0){
    for(int l=i;l>0;l--){
        cout<<l;
    }
}
    
    cout<<"\n";
}
    return 0;
}