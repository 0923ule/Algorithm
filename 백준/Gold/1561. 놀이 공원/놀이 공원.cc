#include <iostream>
using namespace std;
typedef long long ll;

int n, m;
int arr[10005];

bool isValid(ll x) {
	ll tmp = m;
	for (int i = 0; i < m; i++) {
		tmp += x / arr[i];
	}
	if (tmp >= n) return true;
	else return false;
}

ll solve() {
	ll start = 0, mid, end = 60000000000;
	ll ans = 0;

	while (start <= end) {
		mid = (start + end) / 2;
		if (isValid(mid)) {
			end = mid - 1;
			ans = mid;
		}
		else {
			start = mid + 1;
		}
	}
	return ans;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	ll tmp = solve();
	if (tmp == 0) {
		cout << n;
		return 0;
	}

	int idx = 0;
	for (int i = 0; i < m; i++) {
		idx += ((tmp - 1) / arr[i]) + 1;
	}
	for (int i = 0; i < m; i++) { 
		if (tmp % arr[i] == 0) idx++;
		if (idx == n) {
			cout << i + 1 << "\n"; break;
		}
	}
	return 0;
}
