#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int sum = 0;
vector<int> v;

bool dp[100][100][100][100] = {0,};

void calc() {
	dp[0][0][0][0] = 1;
	for (int i = 0; i < n; i++) {

		// dp 채우기
		for (int a = 80-v[i]; a >= 0; a--) {
			for (int b = 80-v[i]; b >= 0; b--) {
				for (int c = 80-v[i]; c >= 0; c--) {
					for (int d = 80-v[i]; d >= 0; d--) {
						if (dp[a][b][c][d]) {
							dp[a+v[i]][b][c][d] = 1;
							dp[a][b+v[i]][c][d] = 1;
							dp[a][b][c+v[i]][d] = 1;
							dp[a][b][c][d+v[i]] = 1;
						}
					}
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		sum += tmp;
	}
	calc();

	// v[0] <= width <= height
	// width <= sum / 4, width + height <= sum / 2
	int maxi = -1;
	for (int w = v[0]; w <= 80; w++) {
		for (int h = w; h <= 80 ; h++) {
			if (dp[w][w][h][h]) maxi = max(maxi, w * h);
		}
	}

	cout << maxi;
	return 0;
}