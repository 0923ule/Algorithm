#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

ll n, k;

bool check(int num) {
    ll res = 0;
    for (ll i = 1; i <= n; i++) {
        res += min((num / i), n);
    }

    if (res >= k) return true;
    else return false;
}

ll parametric_search(ll start, ll end) {
    ll mid;
    ll res = -1;
    while (start <= end) {
        mid = (start + end) / 2;
        // cout << mid << "\n";
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

    cin >> n >> k;

    ll ans = parametric_search(1, 1000000000);
    cout << ans;
    return 0;
}