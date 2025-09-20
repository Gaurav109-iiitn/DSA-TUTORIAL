#include<iostream>
#include<vector>
using namespace std;
vector <int> sel(vector <int> v){
    int n=v.size();
    int max_profit=0;
    int k,l;
    for(int i=0;i<n;i++){
        int curr;
        for(int j=i+1;j<n;j++){
      curr=v[j]-v[i];
            if(curr>max_profit){
                max_profit=curr;
                k=i+1;
                l=j+1;
            }
        }
    }
return {k,l};
}
int main(){
    vector <int> v;
    int n;
    cout<<"enter no of days"<<endl;
    cin>>n;
    cout<<"enter prices for each day"<<endl;
    for(int i=0;i<n;i++){
        int price;
        cin>>price;
        v.push_back(price);
    }
    vector <int> b= sel(v);
    cout<<"Buy on day: "<<b[0]<<" Sell on day: "<<b[1]<<endl;
    return 0;

}