#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int arr[55];
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = -tmp;
	}

	sort(arr, arr + n);

	int ans = 0;
	int start = n;
	int end = -1;

	for (int i = 0; i < n; i++) {
		if (i + 1 < n  && -arr[i] > 1  && -arr[i + 1] > 1) {
			ans += (-arr[i] * -arr[i + 1]);
			i++;
		}
		else {
			start = i;
			break;
		}
		
	}
	for (int i = n-1; i >= 0; i--) {
		if (i - 1 >= 0 && arr[i] > 0 && arr[i - 1] > 0) {
			ans += (arr[i] * arr[i - 1]);
			i--;
		}
		else {
			end = i;
			break;
		}

	}

	for (int i = start; i <= end; i++) {
		if (arr[i] == 0)end--;
		ans += -arr[i];
	}

	cout << ans;
	return 0;
}