#include<iostream>
#include<vector>
using namespace std;
vector <int>  majority(vector <int> v){
    int n=v.size();
    vector <int> ans;
        int mxfq=0;
        int idex;
        for(int i=0;i<n;i++){
            int fre=1;
        for(int j=i+1;j<n;j++){
            if(v[i]==v[j]){
            fre++;
            }
            else{
            }
        }
        if(fre>mxfq){
            mxfq=fre;
            idex=v[i];
        }
        }
        ans.push_back(mxfq);
        ans.push_back(idex);
        return ans;
    }
    void pr(vector <int> v){
        for(int i: v){
            cout<<i<<" ";
        }

    }
    
    int main(){
        int n;
        cout<<"enter n";
        cin>>n;
        vector <int> v(n);
        for(int i=0;i<n;i++){
            cout<<"enter data";
            cin>>v[i];
        }
        vector <int> c=majority(v);
        cout << "Most frequent [frequency, element]: ";
        pr(c);
        return 0;
    }
