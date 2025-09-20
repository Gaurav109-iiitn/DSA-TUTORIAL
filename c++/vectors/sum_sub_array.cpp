#include<iostream>
#include<vector>
using namespace std;
int main(){
int n;
cout<<"enter n";
cin>>n;
vector <int> v(n);
int maxsum=0;
for(int i=0;i<n;i++){
    cout<<"enter data"<<i+1<<endl;
    cin>>v[i];
}

for(int i=0;i<n;i++){
    int currsum=0;
    for(int k=i;k<n;k++){
    currsum+=v[k];
    maxsum=max(currsum,maxsum);
    }
}
cout<<maxsum<<endl;
    return 0;
}