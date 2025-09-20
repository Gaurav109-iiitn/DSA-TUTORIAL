#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void container(vector <int> v){
int n;
n=v.size();
int vol=v[0];
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
    int m=min(v[i],v[j]);
int curr=m*(j-i);
if(vol<curr){
    vol=curr;
}
}
}
cout<<vol;
}
void con(vector <int> v){
    int k=0;
    int i=0,j=v.size()-1;
    while(i<=j){
        int wd=j-i;
        int curr=min(v[i],v[j])*wd;
        k=max(k,curr);
        if(v[i]>v[j]){
            j--;
        }
        else
        i++;
    }
    cout<<k;
}
void con1(vector<int> v) {
    int k = 0;  // Max area
    int i = 0, j = v.size() - 1;
    
    while (i < j) {
        int width = j - i;
        int height = min(v[i], v[j]);
        int curr = height * width;
        k = max(k, curr);
        
        // Move the pointer pointing to the shorter line
        if (v[i] < v[j]) {
            i++;
        } else {
            j--;
        }
    }
    cout << k << endl;
}

int main(){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    vector <int> v(n);
    cout<<"enter values";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    container(v);
    cout<<"\n";
    con(v);
    cout<<endl;
    con1(v);
    return 0;
}