#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

int R, C, M;

struct shark {
    int r, c, s, d, z;
};

int dr[5] = { 0,-1,1,0,0 };
int dc[5] = { 0,0,0,1,-1 };

int arr[105][105];
vector<shark> v;
vector<shark> tmp[105][105];

int ans = 0;

void catch_shark(int col) {
    for (int i = 1; i <= R; i++) {
        if (arr[i][col] == 1) {
            for (int fish = 0; fish < v.size(); fish++) {
                if (v[fish].r == i && v[fish].c == col) {
                    ans += v[fish].z;
                    v.erase(v.begin() + fish);
                    arr[i][col] = 0;
                    // cout << "냠" << i << col << "\n";
                    return;
                }
            }
        }
    }
}

void move_shark() {
    for (int i = 0; i < v.size(); i++) {
        int nr = v[i].r + dr[v[i].d] * v[i].s;
        int nc = v[i].c + dc[v[i].d] * v[i].s;

        while (1) {
            if (nr <= 0) {
                nr = -nr + 2;
                v[i].d = 2;
            }
            else if (nr > R) {
                nr = R - (nr - R);
                v[i].d = 1;
            }
            else if (nc <= 0) {
                nc = -nc + 2;
                v[i].d = 3;
            }
            else if (nc > C) {
                nc = C - (nc - C);
                v[i].d = 4;
            }
            else break;
        }

        arr[v[i].r][v[i].c]--;
        arr[nr][nc]++;
        v[i].r = nr;
        v[i].c = nc;
    }

    //for (int i = 0; i < v.size(); i++) {
    //    cout << v[i].r << v[i].c << v[i].z << "\n";
    //}
}

void eat_shark() {
    for (int i = v.size() - 1; i >= 0; i--) {
        if (arr[v[i].r][v[i].c] == 1) continue;

        tmp[v[i].r][v[i].c].push_back(v[i]);
        v.erase(v.begin() + i);
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (tmp[i][j].size() == 0) continue;

            int maxi=-1, midx = 0;
            for (int k = 0; k < tmp[i][j].size(); k++) {
                if (maxi < tmp[i][j][k].z) {
                    maxi = tmp[i][j][k].z;
                    midx = k;
                }
            }

            v.push_back(tmp[i][j][midx]);
            arr[i][j] = 1;
            tmp[i][j].clear();
        }
    }
    //for (int i = 0; i < v.size(); i++) {
    //    cout << v[i].r << v[i].c << v[i].z << "\n";
    //}
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> M;

    // input
    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        arr[r][c] = 1;
        v.push_back({ r,c,s,d,z });
    }

    // solve
    for (int i = 1; i <= C; i++) {
        catch_shark(i);
        move_shark();
        eat_shark();

        //for (int i = 1; i <= R; i++) {
        //    for (int j = 1; j <= C; j++) {
        //        cout << arr[i][j] << " ";
        //    }
        //    cout << "\n";
        //}
        //cout << "----------------------\n";

        //break;
    }

    cout << ans;
    return 0;
}