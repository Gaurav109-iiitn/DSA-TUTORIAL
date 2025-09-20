#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int stock(vector <int> v){
    int n=v.size();
    int buying_price=v[0];
    int mp=0;
    for(int i=1;i<n;i++){
        if(v[i]>buying_price){
            mp=max(mp,v[i]-buying_price);
        }
        buying_price=min(buying_price,v[i]);
    }
    return mp;
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
    int b=stock(v);
    cout<<b<<endl;
    return 0;
}