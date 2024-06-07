#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++){
		int s, e;
		cin >> s >> e;
		v.push_back({s,e});
	}

	sort(v.begin(), v.end());

	int start = v[0].second;
	int end = 0;

	for (auto k : v) {
		if (k.second < start) {
			start = k.second;
		}
		if (start < k.first) {
			end = k.first;
		}
		//cout<<k.first<<k.second<<"\n";
		//cout<<"se "<<start<<" "<<end<<"\n";
	}

	if (end == 0) cout << 0;
	else cout << end - start;
	
	return 0;
}