#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int num;
    cout<<"enter number"<<endl;
    cin>>num;
    int x=num;
    int u=0;
    int n_num=0;
    while(x!=0){
        x/=10;
        u++;
    }
    cout<<u<<endl;
    int k=pow(10,u-1);
    int temp = num; 
    for(int i=u-1;i>=0;i--){
        int rem=temp%10;
        n_num+=rem*k;
        temp/=10;
        k/=10;
    }

    cout<<n_num<<endl;
    return 0;
}