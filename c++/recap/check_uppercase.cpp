#include<iostream>
using namespace std;
int main(){
    char p;
    cout<<"enter charcter";
    cin>>p;
    if(p<='z'&& p>='a')
    {
        cout<<"lower case";
    }
    else if(p<='Z'&& p>='A'){
        cout<<"upper case";
    }
    else{
        cout<<"not an alphabet";
    }
    return 0;
}