#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 987654321

int n;
int arr[16][16];
int cost[16][1 << 16];
//cost[현재 위치][방문 상태]
int dfs(int cur, int status);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	memset(cost, -1, sizeof(cost));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cout << dfs(0, 1);
	return 0;
}

int dfs(int cur, int status) {
	if (status == (1 << n) - 1) {
		if (arr[cur][0] == 0) return INF;
		return arr[cur][0];
	}
	if (cost[cur][status] != -1) return cost[cur][status];
	cost[cur][status] = INF;

	for (int i = 0; i < n; i++) {
		//현재 노드
		if (arr[cur][i] == 0) continue;
		//이미 방문한 노드
		if ((status & (1 << i)) == (1 << i)) continue;

		cost[cur][status] = min(cost[cur][status], arr[cur][i] + dfs(i, status | (1 << i)));
	}

	return cost[cur][status];
}