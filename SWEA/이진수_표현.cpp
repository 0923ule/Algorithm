#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		int n, m;
		cin >> n >> m;
		
		int bitmask = (1 << n) - 1;
		if (bitmask == (m & bitmask)) 
			cout << "#" << t << " ON\n";
		else 
			cout << "#" << t << " OFF\n";
	}
	return 0;
}
