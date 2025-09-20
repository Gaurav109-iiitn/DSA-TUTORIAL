#include<iostream>
using namespace std;
int main(){
    int p;
    cout<<"enter n";
    cin>>p;
    for(int i=0;i<p;i++){
for(int j=0;j<i;j++){
    cout<<" "<<"\t";
}
for(int l=p-i;l>0;l--){
    cout<<"*\t";
}
cout<<"\n";
    }
return 0;
}