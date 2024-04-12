#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int n, m, k;
int tx, ty;
int arr[30][30];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct taxi {
    int sx, sy, ex, ey;
};
vector<taxi> v;

void start_taxi(int tx, int ty);
void move_taxi(int sx, int sy, int ex, int ey);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> tx >> ty;

    for (int i = 0; i < m; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        v.push_back({ sx,sy,ex,ey });
    }

    start_taxi(tx, ty);

    cout << k;
    return 0;
}

void start_taxi(int tx, int ty) {
    queue<pair<int, int>> q;
    int visited[30][30] = { 0, };
    q.push({ tx,ty });
    visited[tx][ty] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
            if (arr[nx][ny] == 1) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({ nx,ny });
        }
    }

    int mini = 987654321, midx = -1;
    for (int i = 0; i < v.size(); i++) {
        int val = visited[v[i].sx][v[i].sy];
        if (val == 0) continue;
        if (mini > val) {
            mini = val;
            midx = i;
        }
        else if (mini == val) {
            if (v[midx].sx > v[i].sx) {
                mini = val;
                midx = i;
            }
            else if (v[midx].sx == v[i].sx) {
                if (v[midx].sy > v[i].sy) {
                    mini = val;
                    midx = i;
                }
            }
        }
    }
    if (midx == -1) {
        cout << -1;
        exit(0);
    }
    int sx = v[midx].sx;
    int sy = v[midx].sy;
    int ex = v[midx].ex;
    int ey = v[midx].ey;
    v.erase(v.begin() + midx);
    k -= mini - 1;

    if (k <= 0) {
        cout << -1;
        exit(0);
    }

    move_taxi(sx, sy, ex, ey);
    return;
}

void move_taxi(int sx, int sy, int ex, int ey) {
    queue<pair<int, int>> q;
    int visited[30][30] = { 0, };
    q.push({ sx,sy });
    visited[sx][sy] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();


        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
            if (arr[nx][ny] == 1) continue;
            if (visited[nx][ny]) continue;
            // 도착
            if (nx == ex && ny == ey) {
                int val = visited[x][y];
                if (k < val) {
                    cout << -1;
                    exit(0);
                }
                k += val;

                if (v.size()) {
                    start_taxi(ex, ey);
                    return;
                }
                else return;
            }

            visited[nx][ny] = visited[x][y] + 1;
            q.push({ nx,ny });
        }
    }
    
    cout << -1;
    exit(0);
}

