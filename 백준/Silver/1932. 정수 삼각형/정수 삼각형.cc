#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int triangle[505][505] = { 0, };
int sum[505][505] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    sum[0][0] = triangle[0][0];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= i; j++) {
            sum[i + 1][j] = max(sum[i + 1][j], sum[i][j] + triangle[i + 1][j]);
            sum[i + 1][j + 1] = max(sum[i + 1][j + 1], sum[i][j] + triangle[i + 1][j + 1]);
        }
    }

    int ans = -1;
    for (int j = 0; j < n; j++) {
        ans = max(ans, sum[n - 1][j]);
    }
    cout << ans;

    return 0;
}