#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int testcase = 10;
	for (int t = 1; t <= testcase; t++) {
		vector<int> v;

		int n, m;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			v.push_back(data);
		}
		
		cin >> m;
		for (int i = 0; i < m; i++) {
			char cmd;
			cin >> cmd;

			int x, y;
			if (cmd == 'I') {
				cin >> x >> y;
				for (int j = 0; j < y; j++){
					int data;
					cin >> data;
					v.insert(v.begin() + x + j, data);
				}
			}
			else if (cmd == 'D') {
				cin >> x >> y;
				for (int j = 0; j < y; j++)
					v.erase(v.begin() + x);
			}
			else if (cmd == 'A') {
				cin >> y;
				for (int j = 0; j < y; j++){
					int data;
					cin >> data;
					v.push_back(data);
				}
			}
		}
		
		cout << "#" << t << " ";
		for (int i = 0; i < 10; i++) cout << v[i] << " ";
		cout << "\n";
	}
	return 0;
}
