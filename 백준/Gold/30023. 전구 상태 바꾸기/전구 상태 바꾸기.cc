#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

string str;

void change(int idx) {
	for (int i = idx; i < idx+3; i++){
		if (str[i] == 'R') str[i] = 'G';
		else if (str[i] == 'G') str[i] = 'B';
		else if (str[i] == 'B') str[i] = 'R';
	}
}

int solve(string input, int n) {
	int result = -1;

	for (int i = 0; i < 3; i++){
		str = input;
		int check = 0;

		// 시작색 바꾸기
		for (int j = 0; j < i; j++){
			change(0);
			check++;
		}
		char color = str[0];

		// 나머지 바꾸기
		for (int i = 1; i < n-2; i++){
			while (str[i] != color) {
				change(i);
				check++;
			}
		}

		// 확인
		if (str[0] == str[n-2] && str[0] == str[n-1]) {
			if (result == -1) result = check;
			else result = min(result, check);
		}
	}

	
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	string input;
	cin >> input;

	int ans = solve(input, n);

	cout << ans;

	return 0;
}