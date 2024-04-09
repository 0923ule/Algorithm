#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

map<pair<int, int>, int> visited;
vector<pair<int, int>> v;

int n, t;

int solve(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({ sx, sy });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                if (i == 0 && j == 0) continue;
                if (visited.find({ x + i,y + j }) == visited.end()) continue;
                if (visited[{x + i, y + j}]) continue;

                visited[{x + i, y + j}] = visited[{x, y}] + 1;
                if (y + j >= t) return visited[{x + i, y + j}];
                
                q.push({ x + i, y + j });
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x,y });
        visited[{x, y}] = 0;
    }

    cout << solve(0,0);
    return 0;
}