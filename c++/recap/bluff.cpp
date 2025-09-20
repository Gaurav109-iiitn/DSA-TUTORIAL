#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int x;
    cout<<"enter x"<<endl;
    cin>>x;
    if(x%2!=0){
        cout<<"not a even number"<<endl;
    }
    else{
        cout<<"even number"<<endl;
        for(int i=0;i<x;i++){
          
          if(x==pow(2,i))
          {
            cout<<i;
            break;
          }  
        }

    }
    return 0;
}