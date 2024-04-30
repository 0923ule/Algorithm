#include <iostream>

#include <vector>

#include <algorithm>
using namespace std;

int n;
int dp[1000005][2];
// 0 시민, 1 얼리어답터
vector<int> tree[1000005];


void solve(int parent) {
    dp[parent][1] = 1;

    for (int i = 0; i < tree[parent].size(); i++) {
        int child = tree[parent][i];
        if (dp[child][1]) continue;
        solve(child);

        dp[parent][1] += min(dp[child][0], dp[child][1]);
        dp[parent][0] += dp[child][1];
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    solve(1);
    cout << min(dp[1][1], dp[1][0]);
    return 0;
}