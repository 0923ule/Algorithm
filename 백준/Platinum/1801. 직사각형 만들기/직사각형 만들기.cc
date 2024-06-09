#include <iostream>
#include <vector>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
vector<int> v;
int longStick[1<<16] = {0,}; // longStick[state] 상태가 state일 때 가장 긴 스틱의 길이(2)

void calc() {
    for (int i = 1; i < (1<<n); i++) {
		vector<int> subset;
		int sum  = 0;

		// 부분수열의 집합 구하기
		for (int j = 0; j < n; j++) {
			if (i & (1<<j)) {
				subset.push_back(v[j]);
				sum += v[j];
			}
		}
		if (sum % 2 == 1) continue;

		// 부분수열의 부분수열 구하기
		// 길이가 sum/2가 되는 부분수열이 있다 ==> sum/2 길이의 2개의 막대를 만들 수 있음
		int flag = 0;
		for (int a = 1; a < (1<<subset.size()); a++) {
			int subsum = 0;
			for (int b = 0; b < subset.size(); b++) {
				if (a & (1<<b)) subsum += subset[b];
			}
			if (subsum == sum/2) {
				flag = 1;
				break;
			}
		}

		if (flag) longStick[i] = sum/2;
	}

	// longStick 배열 채우기
	for (int i = 0; i < (1<<n); i++) {
		for (int j = 0; j < n; j++) {
			// 현재 상태가 j막대를 포함하면, j막대가 없을 때랑 비교
			if ((i>>j) & 1) {
				longStick[i] = max(longStick[i], longStick[i ^ (1<<j)]);
			}
		}
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	calc();

	int maxi = -1;
	int full_bits = (1<<n)-1;

	for (int state = 0; state < (1<<n); state++) {
		int area = longStick[state] * longStick[full_bits ^ state];
		maxi = max(maxi, area);
	}

	if (maxi == 0) cout << -1;
	else cout << maxi;

	return 0;
}