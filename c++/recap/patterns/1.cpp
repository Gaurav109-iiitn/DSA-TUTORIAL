#include<iostream>
using namespace std;
int main(){
int n;
cout<<"enter n";
cin>>n;
for(int i=0;i<n;i++){
    char o='A';
    for(int j=0;j<n;j++){
cout<<o<<"\t";
o++;
    }
    cout<<"\n";
}
return 0;
}