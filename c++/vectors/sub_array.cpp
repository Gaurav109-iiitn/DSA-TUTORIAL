#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
vector <int> v(n);
for(int i=0;i<n;i++){
    cout<<"enter data"<<i+1<<endl;
    cin>>v[i];
}
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
       for(int k=i;k<j;k++){
        cout<<v[k];
       } 
       cout<<" ";
    }
    cout<<endl;
}
    return 0;
}