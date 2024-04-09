#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int w, h;
char arr[105][105];
int dis[105][105];
bool visited[105][105][4] = { 0, };

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

struct point {
    int x, y, dir;
    bool operator<(const point& p) const {
        return dir > p.dir;
    }
};

void solve(int sx, int sy) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            dis[i][j] = 987654321;
        }
    }

    priority_queue<pair<int, point>> pq;
    pq.push({ 0,{sx,sy,-1} });
    dis[sx][sy] = 0;

    while (!pq.empty()) {
        int d = -pq.top().first;
        int x = pq.top().second.x;
        int y = pq.top().second.y;
        int dir = pq.top().second.dir;

        pq.pop();

        if (d > dis[x][y]) continue;

        for (int ndir = 0; ndir < 4; ndir++) {
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];

            if (dir == (ndir + 2) % 4) continue;
            if (arr[nx][ny] == '*') continue;
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

            int cost = (dir == ndir) ? 0 : 1;

            if (visited[nx][ny][ndir] && dis[nx][ny] <= dis[x][y] + cost) continue;
            if (dis[nx][ny] >= dis[x][y] + cost) {
                dis[nx][ny] = dis[x][y] + cost;
                pq.push({ -dis[nx][ny], {nx,ny,ndir} });
                visited[nx][ny][ndir] = true;
            }

        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> h;

    int idx = 0;
    pair<int, int> s[2];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'C') s[idx++] = { i,j };
        }
    }

    solve(s[0].first, s[0].second);

    /*for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (dis[i][j] == 987654321) cout << "* ";
            else cout << dis[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << dis[s[1].first][s[1].second] - 1;

    return 0;
}