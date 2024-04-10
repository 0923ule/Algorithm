#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

int arr[100005];
int n, m;

bool check(int k) {
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > k) return false;
        if (sum + arr[i] <= k) {
            sum += arr[i];
        }
        else {
            cnt++;
            sum = arr[i];
        }
    }

    if (cnt <= m) return true;
    else return false;
}

int prametric_search(int start, int end) {
    int mid;
    int res = -1;
    while (start <= end) {
        mid = (start + end) / 2;
        if (check(mid)) {
            end = mid - 1;
            res = mid;
        }
        else {
            start = mid + 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = prametric_search(1, 1000000005);
    cout << ans;
    return 0;
}