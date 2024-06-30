#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    int ans = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }



    sort(v.begin(), v.end());

    int start = -1;

    for (int i = 0; i < n; i++) {
        start = max(start, v[i].first);
        
        if (start < v[i].second) {
            int cnt = (v[i].second - start) / m;
            if ((v[i].second - start) % m) cnt++;

            start = start + cnt * m;
            ans += cnt;
        }
    }


    cout << ans;
    
    return 0;
}