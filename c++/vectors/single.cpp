#include<iostream>
#include<vector>
using namespace std;
int single(vector<int> &v){
    int ans=0;
    for(int i : v){
     ans^=i;
    }
    return ans;
}
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cout<<"enter element "<<i+1<<endl;
        cin>>v[i];
    }
int ans=single(v);
cout<<"the single element is "<<ans<<endl;
return 0;
}