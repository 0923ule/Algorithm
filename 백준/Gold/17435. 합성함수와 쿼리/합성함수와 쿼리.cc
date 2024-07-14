#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int m, Q;
int dp[20][200'005]; // log2(500'000) = 18.93xxx

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> dp[0][i];
	}

	// Sparse Table
	// f(f(f(f(1))))  =  f(f(  f(f(1))  )) 
	//    f4(1)       =  f2(f2(1))
	for (int i = 0; i < 19; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i + 1][j] = dp[i][dp[i][j]];
		}
	}



	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int n, x;
		cin >> n >> x;

		// 비트마스킹
		for (int bit = 0; bit < 20; bit++) {
			if (n & (1 << bit)) {
				x = dp[bit][x];
			}
		}


		cout << x << "\n";
	}

	return 0;
}