#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int k, m;
int arr[10][10];
int tmp[10][10];
int block[305];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int block_idx = 0;
int ans = 0;

vector<pair<int, int>> vv;
vector<pair<int, int>> change;

void tmp_init();
void s_90(int i, int j);
void s_180(int i, int j);
void s_270(int i, int j);
int check(int i, int j);
int spin();
void get_score();

int main() {
    cin >> k >> m;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> block[i];
    }

    for (int i = 0; i < k; i++) {
        ans = 0;
        int flag = spin();
        if (flag) break;
        cout << ans << " ";
    }

    return 0;
}

void tmp_init() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tmp[i][j] = arr[i][j];
        }
    }
}

void s_90(int i, int j) {
    for (int x = i - 1, a = j - 1; x <= i + 1; x++, a++) {
        for (int y = j - 1, b = i + 1; y <= j + 1; y++, b--) {
            tmp[x][y] = arr[b][a];
        }
    }
}

void s_180(int i, int j) {
    for (int x = i - 1, a = i+1; x <= i + 1; x++, a--) {
        for (int y = j - 1, b = j+1; y <= j + 1; y++, b--) {
            tmp[x][y] = arr[a][b];
        }
    }
}

void s_270(int i, int j) {
    for (int x = i - 1, a = j + 1; x <= i + 1; x++, a--) {
        for (int y = j - 1, b = i - 1; y <= j + 1; y++, b++) {
            tmp[x][y] = arr[b][a];
        }
    }
}

int check(int i, int j) {
    bool visited[10][10] = { 0, };
    queue<pair<int, int>> q;

    int res = 0;

    for (int x = i - 1; x <= i + 1; x++) {
        for (int y = j - 1; y <= j + 1; y++) {
            if (visited[x][y]) continue;
            int val = tmp[x][y];

            q.push({ x,y });
            visited[x][y] = 1;
            int cnt = 1;

            while (!q.empty()) {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int na = a + dx[dir];
                    int nb = b + dy[dir];
                    if (na < 0 || nb < 0 || na >= 5 || nb >= 5) continue;
                    if (tmp[na][nb] != val) continue;
                    if (visited[na][nb]) continue;

                    visited[na][nb] = true;
                    cnt++;
                    q.push({ na,nb });
                }
            }

            if (cnt >= 3) res += cnt;
        }
    }

    return res;
}

int spin() {
    int angle = 100, col = 100, row = 100;
    int mmax = -1;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 0; k < 3; k++) {
                tmp_init();

                if (k == 0) s_90(i, j);
                else if (k == 1) s_180(i, j);
                else if (k == 2) s_270(i, j);

                int res = check(i, j);
                int flag = 0;
                if (res > mmax) flag = 1;
                else if (res == mmax) {
                    if (k < angle) flag = 1;
                    else if (k == angle) {
                        if (j < col) flag = 1;
                        else if (j == col) {
                            if (i < row) flag = 1;
                        }
                    }
                }

                if (flag) {
                    mmax = res;
                    angle = k;
                    col = j;
                    row = i;
                }

                /*cout << "-----------------\n";
                cout << k << " " << i << "," << j << "\n";
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        cout << tmp[i][j] << " ";
                    }
                    cout << "\n";
                }*/
            }
        }
    }

    if (mmax == 0) {
        // 즉시 종료
        return 1;
    }


    // 최종 스핀
    tmp_init();
    if (angle == 0) s_90(row, col);
    else if (angle == 1) s_180(row, col);
    else if (angle == 2) s_270(row, col);

    for (int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            arr[i][j] = tmp[i][j];
            vv.push_back({ i,j });
        }
    }


    /*cout << "final\n";
    cout << angle << " " << row << col << "\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }*/
    get_score();
    return 0;
}



void get_score() {
    int visited[10][10] = { 0, };
    queue<pair<int, int>> q;

    int res = 0;

    for (auto v : vv) {
        int x = v.first;
        int y = v.second;

        if (visited[x][y]) continue;
        int val = arr[x][y];

        q.push({ x,y });
        visited[x][y] =  x * 5 + y + 1;
        int cnt = 1;

        while (!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int na = a + dx[dir];
                int nb = b + dy[dir];
                if (na < 0 || nb < 0 || na >= 5 || nb >= 5) continue;
                if (arr[na][nb] != val) continue;
                if (visited[na][nb]) continue;

                visited[na][nb] = x * 5 + y + 1;
                cnt++;
                q.push({ na,nb });
            }
        }

        if (cnt >= 3) res += cnt;
        else {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (visited[i][j] == x * 5 + y + 1)
                        visited[i][j] = -1;
                }
            }
        }
    }
    /*cout << " ------------------------ \n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (visited[i][j] != -1 && visited[i][j] != 0) {
                cout << "@" << " ";
            }
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }*/
    for (int j = 0; j < 5; j++) {
        for (int i = 4; i >= 0; i--) {
            if (visited[i][j] != -1 && visited[i][j] != 0) {
                arr[i][j] = block[block_idx++];
                change.push_back({ i, j });
            }
        }
    }
    if (change.empty()) return;
    else {
        ans += res;
        vv.clear();
        vv = change;
        change.clear();
        get_score();
    }
    
    return;
}
