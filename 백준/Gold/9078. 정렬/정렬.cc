#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int testcase;
    cin >> testcase;
    
    for (int t = 0; t < testcase; t++) {
        int n;
        cin >> n;

        int arr[105];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (arr[i] > arr[j]) cnt++;
            }
        }
        if (cnt % 2 == 0) cout << "YES\n";
        else cout << "NO\n";

    }
    
    return 0;
}
