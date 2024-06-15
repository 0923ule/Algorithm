#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		int n, ans = 0;
		cin >> n;

		
		int total = (1 << 10) - 1;
		int visited = 0;

		int cnt = 1;
		while(true) {
			int k = n * cnt;
			while(k) {
				visited |= (1 << (k % 10));
				k /= 10;
			}

			if (total == visited) break;

			cnt++;
		}

		ans = n * cnt;
		cout << "#" << t << " " << ans << "\n";
	}

	
	return 0;
}
