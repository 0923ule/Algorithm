#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[300], b[300];
int sumA[300] = { 0, };
int dp[300][90000] = { 0, };
// dp[idx][a가 일한 시간] = idx 까지 b가 일한 시간 최소
// knapsack


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		sumA[i] = sumA[i-1] + a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int atime = 0; atime < sumA[i]; atime++) {

			// a가 일 O : dp[i - 1][x - a[i]]
			// a가 일 X : dp[i - 1][x] + b[i] --> (b가 일할 때) 

			if (atime >= a[i]) 
				dp[i][atime] = min(dp[i - 1][atime - a[i]], dp[i - 1][atime] + b[i]);
			else
				dp[i][atime] = dp[i - 1][atime] + b[i];
		}
	}

	int ans = sumA[n];
	for (int atime = 0; atime <= sumA[n]; atime++) {
		ans = min(ans, max(atime, dp[n][atime]));
	}

	cout << ans;
	return 0;
}