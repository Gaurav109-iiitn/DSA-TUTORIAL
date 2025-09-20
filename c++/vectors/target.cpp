#include<iostream>
#include<vector>
using namespace std;

void pr(vector <int> v){
    int n=v.size();
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}

vector <int> fun1(vector <int> v,int target){
    vector <int> ans;
    int i=0,j=v.size()-1;
    while(i<j){
        int ps=v[i]+v[j];
        if(ps<target){
            i++;
        }
        else if(ps>target){
        j--;
        }
        else{
            ans.push_back(i);
            ans.push_back(j);
            break;
        }

    }
    return ans;
}
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    vector <int> v(n);
    cout<<"enter sorted array\n";
    for(int i=0;i<n;i++){
        cout<<"data:";
        cin>>v[i];
    }
    int target;
    cout<<"enter target";
    cin>>target;
    vector <int> c=fun1(v,target);
    if(c.empty()){
        cout << "No pair found with the given target.\n";
    } else {
        cout << "Indices of elements that sum to target: ";
        pr(c);
    }
    return 0;
}