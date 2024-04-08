#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int arr[15][15] = { 0, };
int game[3][25] = { 0, };
bool visited[15] = { 0, };

bool check() {
	int score[3] = { 0, };
	int idx[3] = { 0, };

	int p1 = 0, p2 = 1;
	while(1) {
		int p1_hand = game[p1][idx[p1]++];
		int p2_hand = game[p2][idx[p2]++];
		//cout << p1_hand << p2_hand << "\n";
		
		int winner;
		if (arr[p1_hand][p2_hand] == 0) winner = p2;
		else if (arr[p1_hand][p2_hand] == 1) winner = p1 > p2 ? p1 : p2;
		else if (arr[p1_hand][p2_hand] == 2) winner = p1;

		score[winner]++;

		//cout <<"p1 "<<p1<<","<<p1_hand << " p2 " << p2 << "," << p2_hand << " winner " << winner << "\n";
		for (int i = 0; i < 3; i++) {
			if (score[i] == k && i == 0) return true;
			if (score[i] == k && i != 0) return false;
		}
		if (idx[0] >= n) return false;

		p2 = 3 - (p1 + p2);
		p1 = winner;

	}
	return false;
}

void solve(int idx) {
	if (idx == n) {
		//for (int i = 0; i < idx; i++) {
		//	cout << game[0][i];
		//}
		//cout << "\n";
		if (check()) {
			//cout << "\n^^";
			cout << 1;
			exit(0);
		}
		//cout << "\n------\n";
		return;
	}


	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		
		game[0][idx] = i;
		visited[i] = true;
		solve(idx + 1);
		game[0][idx] = 0;
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= 2; i++) {
		for (int j = 0; j < 20; j++) {
			cin >> game[i][j];
		}
	}
	solve(0);
	cout << 0;
	return 0;
}
