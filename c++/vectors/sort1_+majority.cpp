#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void pr(vector<int> v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}
vector <int> majority(vector <int> u){
    int n=u.size();
    vector <int> ans;
    sort(u.begin(),u.end());
    int mxfq=0;
    int freq=1;
    int maj=u[0];
    for(int i=1;i<n;i++){
        if(u[i]==u[i-1]){
            freq++;
        }
        else{
            if(freq>mxfq){
                mxfq=freq;
                maj=u[i-1];
            }
            freq=1;
        }
    }
    if(freq>mxfq){
        mxfq=freq;
        maj=u[n-1];
    }

    ans.push_back(mxfq);
    ans.push_back(maj);
    return ans;
}
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    vector<int> v(n);
    cout<<"enter elements";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> c=majority(v);
    pr(c);
    return 0;
}