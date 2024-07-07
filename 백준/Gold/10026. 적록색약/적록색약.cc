#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
char board[105][105];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int solve() {
    queue<pair<int,int>> q;
    bool visited[105][105] = {0,};
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            cnt++;
            visited[i][j] = true;

            q.push({i,j});
            char tmp = board[i][j];

            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny]) continue;
                    if (tmp != board[nx][ny]) continue;

                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    cout << solve() << " ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'R') board[i][j] = 'G';
        }
    }
    cout << solve() << "\n";
    
    return 0;
}
