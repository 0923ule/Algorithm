#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;

using namespace std;

int main() {
	int N;
	cin >> N;
	ll a, b;
	ll ans = 0;
	ll end = -1123456789;
	
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if (a > end) {
			ans += b - a;
			end = b;
		}
		else {
			if (b > end) {
				ans += b - end;
				end = b;
			}
		}
	}

	cout << ans;
	return 0;
}