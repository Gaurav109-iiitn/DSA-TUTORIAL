#include<iostream>
using namespace std;
class deci{
    public:
    deci(int n);
};
deci::deci(int n){
int i=1,j=n,binary=0;
for(j=n;j>0;j=j/2){
    binary+=(j%2)*i;
i*=10;
// n=n/2;
}
cout<<"binary number :"<<binary;
}
int main(){
    deci deci(8);
    return 0;
}