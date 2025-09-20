#include<iostream>
#include<vector>
using namespace std;
void power(int x,int n){
    int p=n;
    int pow=1;
    while(p>0){
        if(p%2==1){
pow*=x;
        }
        x*=x;
        p>>=1;
    }
    cout<<pow;
    
}
int main(){
    int x,n;
    cout<<"enter x and n"<<endl;
    cin>>x>>n;
    power(x,n);
    return 0;
}