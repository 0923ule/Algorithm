#include <iostream>
#include <algorithm>
using namespace std;

int arr[100'005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);


    int dif = 2'100'000'000;
    int start = 0, end = 0;

    while (start < n && end < n) {
        int res = arr[end] - arr[start];

        if (res < m) end++;
        else {
            dif = min(dif, res);
            start++;
        }
    }

    cout << dif;
    return 0;
}