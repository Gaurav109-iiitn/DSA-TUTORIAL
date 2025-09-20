#include<iostream>
#include<vector>
using namespace std;
// vector <int> 
void pair1(vector <int> v,int n,int target){
    for(int i=0;i<n;i++){
        vector <int> b;
        for(int j=i+1;j<n-1;j++){
if(target==v[i]+v[j]){
    cout<<i<<" "<<j<<" "<<endl;
}
        }
    }
}
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cout<<"enter data"<<endl;
        cin>>v[i];
    }
    int target;
    cout<<"enter target"<<endl;
    cin>>target;
    // vector <int>
    pair1(v,n,target);
    
    return 0;
}