#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
const int SOURCE = 888, SINK = 999;

vector<int> v[1000];
int capacity[1000][1000] = { 0, };
int flow[1000][1000] = { 0, };

int parent[1000] = { 0, };
int dis[1000] = { 0, };
bool inQ[1000] = { 0, };

int cost[1000][1000] = { 0, };
int minCost = 0;
int jobCnt = 0;

// Min Cost Max Flow = 최소 비용 최대 유량
void MCMF(int source, int sink) {
    while (true) {
        for (int i = 0; i < 1000; i++) parent[i] = -1;
        for (int i = 0; i < 1000; i++) dis[i] = 987654321;
        for (int i = 0; i < 1000; i++) inQ[i] = 0;
        dis[SOURCE] = 0;

        queue<int> q;
        q.push(source);
        parent[SOURCE] = SOURCE;

        // SPFA = Shortest Path Faster Algorithm (그래프 최단 경로 구하기)
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            inQ[x] = 0; // 큐에서 꺼냄

            for (int i = 0; i < v[x].size(); i++) {
                int nx = v[x][i];

                // 잔여 용량이 있고, 최단 거리 갱신이 가능하면 방문한다.
                if (capacity[x][nx] - flow[x][nx] > 0 && dis[x] + cost[x][nx] < dis[nx]) {
                    dis[nx] = dis[x] + cost[x][nx];
                    parent[nx] = x;
                    
                    // 큐에 있지 않으면 큐에 넣음
                    if (!inQ[nx]) {
                        q.push(nx);
                        inQ[nx] = 1;
                    }
                }
            }
        }

        // 경로가 없음
        if (parent[SINK] == -1) break;
        
        int minflow = 987654321;

        // 증가 경로에서 흐를 수 있는 유량 구하기
        for (int i = SINK; i != SOURCE; i = parent[i]) {
            minflow = min(minflow, capacity[parent[i]][i] - flow[parent[i]][i]);
        }

        // 경로를 따라 유량 추가
        for (int i = SINK; i != SOURCE; i = parent[i]) {
            minCost += minflow * cost[parent[i]][i];
            flow[parent[i]][i] += minflow; // 양의 유량
            flow[i][parent[i]] -= minflow; // 음의 유량
        }
        jobCnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int staff = 1; staff <= n; staff++) {
        int size;
        cin >> size;

        v[SOURCE].push_back(staff);
        v[staff].push_back(SOURCE);
        capacity[SOURCE][staff] = 1;

        for (int j = 0; j < size; j++) {
            int job, pay;
            cin >> job >> pay;
            job += n;

            v[staff].push_back(job);
            v[job].push_back(staff);
            capacity[staff][job] = 1;

            cost[staff][job] = pay;
            cost[job][staff] = -pay;
        }
    }

    for (int job = n + 1; job <= n + m; job++) {
        v[job].push_back(SINK);
        v[SINK].push_back(job);
        capacity[job][SINK] = 1;
    }

    MCMF(SOURCE, SINK);
    cout << jobCnt << "\n" << minCost;
    return 0;
}