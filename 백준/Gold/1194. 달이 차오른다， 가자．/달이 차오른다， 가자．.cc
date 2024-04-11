#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int n, m;
char arr[55][55];
int visited[55][55]= {0,};
vector<int> have_key[55][55];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

struct minsic {
    int x, y;
    int key;
};

int solve(int sx, int sy) {
    queue<minsic> q;
    q.push({ sx,sy,0 });
    visited[sx][sy] = 1;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int key = q.front().key;

        // cout << x << y <<key<<" "<< visited[x][y] << "\n";
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nkey = key;

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) {
                int flag = 0;
                for (int i = 0; i < have_key[nx][ny].size(); i++) {
                    if (have_key[nx][ny][i] == nkey) {
                        flag = 1; break;
                    }
                }
                if (flag) continue;
            }
            //if (visited[nx][ny] && have_key[nx][ny] == nkey) continue;

            if (arr[nx][ny] == '#') continue;
            if (arr[nx][ny] == '1') {
                // 도착
                return visited[nx][ny] = visited[x][y] + 1 - 1;
            }

            
            if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'z') {
                int num = arr[nx][ny] - 'a';
                nkey = nkey | (1 << num);
            }
            if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z') {
                int num = arr[nx][ny] - 'A';
                if (!(nkey & (1 << num))) continue;
            }
 
            visited[nx][ny] = visited[x][y] + 1;
            have_key[nx][ny].push_back(nkey);
            q.push({ nx,ny,nkey });
            // cout << "@@" << nx << " " << ny << " " << nkey << "\n";
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int sx=0, sy=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '0') {
                sx = i;
                sy = j;
            }
        }
    }

    cout << solve(sx,sy);

    return 0;
}
