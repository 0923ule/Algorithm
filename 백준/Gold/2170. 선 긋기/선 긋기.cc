#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }
    sort(v.begin(), v.end());

    int start = -1'000'000'000;
    int end = -1'000'000'000;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        if (end < v[i].first) {
            ans += end - start;
            start = v[i].first;
            end = v[i].second;
        }

        end = max(end, v[i].second);
    }

    ans += end - start;
    cout << ans;
    return 0;
}