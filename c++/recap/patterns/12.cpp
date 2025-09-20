#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    int sum=1;
    for(int i=0;i<n;i++){ 
        for(int j=0;j<=i;j++){
            cout<<sum<<"\t";
            sum++;
        }
        cout<<"\n";
    }
}
