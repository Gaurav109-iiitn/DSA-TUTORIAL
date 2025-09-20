#include<iostream>
#include<vector>
using namespace std;
vector <int> f1(vector <int> v){
    vector <int> b(v.size());
    int total=1;
    for(int i=0;i<v.size();i++){
        total*=v[i];
    }

    for(int j=0;j<v.size();j++){
        b[j]=total/v[j];
    }
return b;
}
void pr(vector <int> b){
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";
    }
}
vector <int> f2(vector <int> v){
    int n=v.size();
    vector <int> ans(n);
    ans[0]=1;
    for(int i=1;i<n;i++){
        ans[i]=ans[i-1]*v[i-1];
    }
    return ans;
}
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    cout<<"enter details"<<endl;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector <int> b=f1(v);
    pr(b);
    cout<<"\n";
    vector <int> c=f2(v);
    pr(c);
    return 0;
}
