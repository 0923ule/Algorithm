#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

int R, T, C;
int arr[1005][1005] = { 0, };
int tmp[1005][1005] = { 0, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int cleaner[2];

void dust() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] < 5) continue;

            int side = arr[i][j] / 5;
            int center = arr[i][j];

            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if (arr[nx][ny] == -1) continue;
                
                tmp[nx][ny] += side;
                center -= side;
            }
            arr[i][j] = center;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            arr[i][j] += tmp[i][j];
            tmp[i][j] = 0;
        }
    }
}

void clean() {
    // 위
    for (int i = cleaner[0] -1; i > 0; i--) 
        arr[i][0] = arr[i - 1][0];
    
    for (int j = 0; j < C-1; j++) 
        arr[0][j] = arr[0][j + 1];
    
    for (int i = 0; i < cleaner[0]; i++)
        arr[i][C - 1] = arr[i + 1][C - 1];

    for (int j = C - 1; j > 0; j--)
        arr[cleaner[0]][j] = arr[cleaner[0]][j - 1];
    arr[cleaner[0]][1] = 0;


    // 아래
    for (int i = cleaner[1]+1; i<R-1;i++)
        arr[i][0] = arr[i + 1][0];

    for (int j = 0; j < C - 1; j++)
        arr[R-1][j] = arr[R-1][j + 1];

    for (int i = R - 1; i > cleaner[1]; i--)
        arr[i][C - 1] = arr[i - 1][C - 1];

    for (int j = C - 1; j > 0; j--)
        arr[cleaner[1]][j] = arr[cleaner[1]][j - 1];
    arr[cleaner[1]][1] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> T;

    int idx = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) cleaner[idx++] = i;
        }
    }

    for (int i = 0; i < T; i++) {
        dust();
        clean();

        //for (int i = 0; i < R; i++) {
        //    for (int j = 0; j < C; j++) {
        //        cout << arr[i][j] << " ";
        //    }
        //    cout << "\n";
        //}
    }

    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ans += arr[i][j];
        }
    }

    cout << ans + 2;

    return 0;
}