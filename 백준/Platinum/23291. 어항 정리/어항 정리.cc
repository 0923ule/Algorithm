#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int cnt;
int arr[200];
int tmp[200][200];
int movement[200][200];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void addFish();
void rollFishbowl();
void devideFish(int width, int height, int flag);
void makeOneline(int width, int height, int flag);
void stackFishbowl();
void checkFish();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cnt = 0;
    addFish();
    cout << cnt;
    return 0;
}

void addFish() {
    // 물고기 추가
    int mini = 987654321;
    for (int i = 0; i < n; i++)
        mini = min(mini, arr[i]);

    for (int i = 0; i < n; i++)
        if (mini == arr[i])
            arr[i]++;

    rollFishbowl();
}

void rollFishbowl() {
    // 어항 쌓기
    memset(tmp, -1, sizeof(tmp));
    for (int i = 0; i < n; i++) tmp[0][i] = arr[n - 1 - i];

    int len = n;
    int width = 1;
    int height = 1;
    while (len - height >= width) {
        for (int i = 0, b = len - width - 1; i < height; i++, b--) {
            for (int j = len - width, a = 1; j < len; j++, a++) {
                tmp[a][b] = tmp[i][j];
                tmp[i][j] = -1;
            }
        }
        int tmp = width;
        len = len - width;
        width = height;
        height = tmp + 1;
    }
    devideFish(len, height, 0);
}

void devideFish(int width, int height, int flag) {
    // 물고기 수 조절
    memset(movement, 0, sizeof(movement));

    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            if (tmp[x][y] == -1) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || tmp[nx][ny] == -1) continue;

                int d = abs(tmp[nx][ny] - tmp[x][y]) / 5;
                if (d > 0) {
                    if (tmp[nx][ny] < tmp[x][y]) d = -d;
                    movement[nx][ny] -= d;
                    movement[x][y] += d;
                }
            }
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tmp[i][j] == -1) continue;
            tmp[i][j] += movement[i][j] / 2;
        }
    }
    makeOneline(width, height, flag);
}

void makeOneline(int width, int height, int flag) {
    // 일렬로 놓기
    int idx = 0;
    for (int x = width - 1; x >= 0; x--) {
        for (int y = 0; y < height; y++) {
            if (tmp[y][x] == -1) continue;
            arr[idx++] = tmp[y][x];
        }
    }
    if (!flag) stackFishbowl();
    else checkFish();
}

void stackFishbowl() {
    // n/2 어항 쌓기
    memset(tmp, -1, sizeof(tmp));
    for (int i = 0; i < n; i++) tmp[0][i] = arr[n - 1 - i];

    int width = n;
    int height = 1;
    for (int x = 0; x < 2; x++) {
        for (int i = 0, a = height+height-1; i <height; i++, a--) {
            for (int j = width/2, b = width/2-1; j < width; j++, b--) {
                tmp[a][b] = tmp[i][j];
                tmp[i][j] = -1;
            }
        }
        width /= 2;
        height *= 2;
    }
    devideFish(width, height, 1);
}

void checkFish() {
    cnt++;
    int maxi = -1;
    int mini = 987654321;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    if (maxi - mini <= k) return;
    addFish();
}