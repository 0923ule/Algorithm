#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, ans = -1;
int board[15][15];
vector<pair<int,int>> virus;
vector<pair<int,int>> space;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs() {
	bool visited[15][15] = {0,};

	queue<pair<int,int>> q;
	for (auto v : virus) q.push(v);
	

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 0 && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 && visited[i][j] == false) cnt++;
		}
	}

	return cnt;
}

void select3(int idx, int cnt) {
	if (cnt == 3) {
		int res = bfs();
		ans = max(ans, res);
		return;
	}

	for (int i = idx + 1; i < space.size(); i++) {
		int x = space[i].first;
		int y = space[i].second;

		board[x][y] = 1;
		select3(i, cnt+1);
		board[x][y] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) virus.push_back({i, j});
			if (board[i][j] == 0) space.push_back({i, j});
		}
	}
	
	select3(-1,0);
	cout << ans;
	return 0;
}