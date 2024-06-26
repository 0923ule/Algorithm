#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> v[100'005];
int visited[100'005];

pair<int,int> solve(int start) {
    for (int i = 1; i <= n; i++) visited[i] = 0;

    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < v[x].size(); i++) {
            int nx = v[x][i].first;
            int dis = v[x][i].second;

            if (nx == start) continue;
            if (visited[nx]) continue;
            visited[nx] = visited[x] + dis;
            q.push(nx);
        }
    }

    int res = -1;
    int idx = -1;
    for (int i = 1; i <= n; i++) {
        if (res < visited[i]) {
            res = visited[i];
            idx = i;
        }
    }
    return { res, idx };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int node, a, b;
        cin >> node;

        while (1) {
            cin >> a;
            if (a == -1) break;
            cin >> b;

            v[node].push_back({ a,b });
            v[a].push_back({ node,b });
        }
    }

    pair<int, int> tmp = solve(1);
    pair<int, int> ans = solve(tmp.second);

    cout << ans.first;

    return 0;
}