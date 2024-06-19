#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<pair<int,int>> v;
ll n, m;

bool compare (const pair<int,int> &a, const pair<int,int> &b) {
    double x = (double)a.second / a.first;
    double y = (double)b.second / b.first;
    
    return x > y;
}

ll gcd(ll a, ll b) {
	while (b > 0) {
		ll c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    
    sort(v.begin(), v.end(), compare);
    
    ll ansa = 0, ansb = 1;
    for (int i = 0; i < v.size(); i++) {
        if (m >= v[i].first) {
            ansa += v[i].second;
            m -= v[i].first;
        }
        else {
            ansa = ansa * v[i].first + v[i].second * m;
            ansb = v[i].first;
            break;
        }
    }
    
    ll num = gcd(ansa, ansb);

    cout << (ansa / num) << "/" << (ansb / num);

    return 0;
}
