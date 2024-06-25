#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }
    sort(v.begin(), v.end());

    priority_queue<int> pq;
    pq.push(-v[0].second);
    for (int i = 1; i < n; i++) {
        if (v[i].first >= -pq.top()) {
            pq.pop(); 
            pq.push(-v[i].second);
        }
        else pq.push(-v[i].second);
    }

    cout << pq.size() << "\n";


    return 0;
}