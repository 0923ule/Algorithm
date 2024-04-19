#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct product {
    int id, revenue, dest, benefit;

    bool operator<(const product &r) const{
        if (benefit == r.benefit) {
            return id > r.id;
        }
        else {
            return benefit < r.benefit;
        }
    }
};

int n, m;
vector<pair<int, int>> graph[2005];
priority_queue<product> ppqq;
vector<product> tmp_vector;
int cost_arr[2005];
bool exist_arr[30005] = { 0, };
bool delete_arr[30005] = { 0, };

void dijkstra(int start);

int main() {
    int test_case;

    cin >> test_case;
    for (int t = 0; t < test_case; t++) {
        int cmd;
        cin >> cmd;
        if (cmd == 100) {
            int v, u, w;
            cin >> n >> m;
            for (int i = 0; i < m; i++) {
                cin >> v >> u >> w;
                graph[v].push_back({ u,w });
                graph[u].push_back({ v,w });
            }

            dijkstra(0);
        }
        else if (cmd == 200) {
            int id, revenue, dest;
            cin >> id >> revenue >> dest;

            int benefit = revenue - cost_arr[dest];

            product p = { id, revenue, dest, benefit };
            exist_arr[id] = true;
            ppqq.push(p);
        }
        else if (cmd == 300) {
            int id;
            cin >> id;
            if (exist_arr[id]) delete_arr[id] = true;
        }
        else if (cmd == 400) {
            while (1) {
                if (ppqq.empty()) {
                    cout << -1 << "\n";
                    break;
                }

                product tmp = ppqq.top();
                ppqq.pop();

                if (delete_arr[tmp.id]) {
                    delete_arr[tmp.id] = 0;
                    exist_arr[tmp.id] = 0;
                    continue;
                }
                if (tmp.benefit < 0) {
                    cout << -1 << "\n";
                    tmp_vector.push_back(tmp);
                    break;
                }

                exist_arr[tmp.id] = 0;
                cout << tmp.id << "\n";
                break;
            }

            for (auto tmp : tmp_vector) {
                ppqq.push(tmp);
            }
            tmp_vector.clear();
        }
        else if (cmd == 500) {
            int s;
            cin >> s;

            dijkstra(s);
            while (!ppqq.empty()) {
                product tmp = ppqq.top();
                ppqq.pop();

                tmp.benefit = tmp.revenue - cost_arr[tmp.dest];
                //cout << tmp.id<<" " << tmp.benefit << "\n";
                tmp_vector.push_back(tmp);
            }

            for (auto tmp : tmp_vector) {
                ppqq.push(tmp);
            }
            tmp_vector.clear();
        }
    }

    return 0;
}

void dijkstra(int start) {
    for (int i = 0; i < n; i++) cost_arr[i] = 987654321;
    
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
    cost_arr[start] = 0;

    while (!pq.empty()) {
        int d = -pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if (d > cost_arr[x]) continue;

        for (int i = 0; i < graph[x].size(); i++) {
            int nx = graph[x][i].first;
            int cost = graph[x][i].second;

            if (cost_arr[nx] >= cost_arr[x] + cost) {
                cost_arr[nx] = cost_arr[x] + cost;
                pq.push({ -cost_arr[nx] , nx });
            }
        }
    }

    //for (int i = 0; i < n; i++) cout << cost_arr[i] << "\n";
}
