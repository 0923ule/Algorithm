#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int tmp[100'005];
int init[100'005];
int infection[100'005];

vector<int> v[100'005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> infection[i];
        tmp[i] = infection[i];
    }

    for (int i = m - 1; i >= 0; i--) {
        bool flag = 0;
        for (auto k : v[i]) 
            if (tmp[k] == 0) flag = 1;
        
        if (flag) 
            for (auto k : v[i]) tmp[k] = 0;
    }

    for (int i = 1; i <= n; i++) init[i] = tmp[i];
    

    for (int i = 0; i < m; i++) {
        bool flag = 0;
        for (auto k : v[i]) 
            if (tmp[k] == 1) flag = 1;
        
        if (flag) 
            for (auto k : v[i]) tmp[k] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (tmp[i] != infection[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << init[i] << " ";
    }

    return 0;
}
