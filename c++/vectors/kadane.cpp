/* kadane's algorithm says that current sum of array is < than 0 then replace its value to 0 then sum it after*/
#include <iostream>
#include <vector>
using namespace std;

// int kadane(vector<int> v, int n) {
//     int currsum = 0;
//     int maxsum = v[0]; 

//     for (int i = 0; i < n; i++) {
//         currsum = currsum + v[i];

//         if (currsum > maxsum)
//             maxsum = currsum;

//         if (currsum < 0)
//             currsum = 0;
//     }
//     return maxsum;
// }
int kadane(vector<int> v, int n) {
    int maxsum = v[0]; 

    for (int i = 0; i < n; i++) {
        int currsum=0;
        currsum = currsum + v[i];

        if (currsum > maxsum)
            maxsum = currsum;
    }
    return maxsum;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> v[i];
    }

    int maxsum = kadane(v, n);
    cout << "Maximum subarray sum: " << maxsum << endl;

    return 0;
}
