#include<iostream>
#include<vector>
using namespace std;

vector<int> majority(vector<int> v) {
    int n = v.size();
    vector<int> ans;
    if (n == 0) {
        ans.push_back(0);
        ans.push_back(-1);
        return ans;
    }

    int maxFreq = 1;
    int freq = 1;
    int majorityElement = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            freq++;
        } else {
            if (freq > maxFreq) {
                maxFreq = freq;
                majorityElement = v[i - 1];
            }
            freq = 1; // reset frequency for new element
        }
    }

    // Check the last group
    if (freq > maxFreq) {
        maxFreq = freq;
        majorityElement = v[n - 1];
    }

    ans.push_back(maxFreq);
    ans.push_back(majorityElement);
    return ans;
}

void pr(vector<int> v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v = {0,1,1,1,2,2,4,4,5,5,6,6,6,6,6};
    vector<int> c = majority(v);
    cout << "Most frequent [frequency, element]: ";
    pr(c);
    return 0;
}