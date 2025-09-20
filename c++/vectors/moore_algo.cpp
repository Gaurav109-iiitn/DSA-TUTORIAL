// moore algorithm says if same element occurs freqency ++ otherwise frequency --
#include<iostream>
#include<vector>
using namespace std;
void pr(vector <int> v){
    for(int i : v){
        cout<<"majority element\n";
        cout<<i<<" ";
    }
    cout<<endl;
}
 vector <int> moore(vector <int> v){
    int n=v.size();
    vector <int> ans;
    int maj=v[0];
    int freq=1;
    for(int i=0;i<n;i++){
        if(freq==0){
            maj=v[i];
            freq=1;
        }
        else{
        if(v[i]==maj){
            freq++;
        }
        else{
            freq--;
            }
        }
    }
    ans.push_back(maj);
    return ans;
 }
int main(){
    int n;
    cout<<"enter n: "; 
    cin>>n;
    vector <int> c(n);
    cout<<"enter elements: ";
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    vector <int> ans=moore(c);
    pr(ans);
    return 0;
}