#include<iostream>
using namespace std;
int main(){
   int n;
   n=5;
   char q='a';
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
     cout<<q<<"\t";
    q++;
   }
   cout<<"\n";
}
 return 0;
}