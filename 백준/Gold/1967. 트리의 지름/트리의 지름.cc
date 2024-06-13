#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> v[10005];

int maxi = -1, max_node = -1;

bool visited[10005] = {0,};
void dfs(int node, int dist) {
	visited[node] = true;

	for (int i = 0; i < v[node].size(); i++){
		int n_node = v[node][i].first;
		int d = v[node][i].second;

		if (visited[n_node]) continue;
		dfs(n_node, dist + d);
	}

	if (dist > maxi) {
		maxi = dist;
		max_node = node;
	}
	
	visited[node] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}

	// 루트노드에서 가장 깊은 노드 a 찾기
	dfs(1, 0);
	int a = max_node;

	max_node = -1, maxi = -1;
	for (int i = 1; i <= n; i++) visited[i] = 0;
	
	// 노드 a에서 가장 먼 노드 b 찾기 (지름 구하기)
	dfs(a, 0);

	cout << maxi;
	return 0;
}