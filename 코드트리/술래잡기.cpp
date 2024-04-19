#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct person {
	int x, y, dir;
};

int n, m, h, k;
person soolae;
vector<person> runners;

bool trees[105][105] = { 0, };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int spiral, idx, go;
int score;

void check(int k) {
	int x = soolae.x;
	int y = soolae.y;
	int dir = soolae.dir;

	vector<int> v;

	int sum = 0;
	while (1) {
		x = x + dx[dir];
		y = y + dy[dir];

		if (trees[x][y]) continue;
		if (x < 0 || y < 0 || x >= n || y >= n) break;

		for (int i = 0; i < runners.size(); i++) {
			if (x == runners[i].x && y == runners[i].y) {
				sum++;
				v.push_back(i);
			}
		}
	}
	for (int i = v.size()-1; i >= 0; i--) {
		runners.erase(runners.begin() + i);
	}
	score += sum * k;
}

void move_runners() {
	for (int i = 0; i < runners.size(); i++) {
		if (abs(runners[i].x - soolae.x) + abs(runners[i].y - soolae.y) > 3) continue;


		int dir = runners[i].dir;
		int x = runners[i].x + dx[dir];
		int y = runners[i].y + dy[dir];

		if (x < 0 || y < 0 || x >= n || y >= n) {
			dir = (dir + 2) % 4;
			x = runners[i].x + dx[dir];
			y = runners[i].y + dy[dir];
		}

		if (x == soolae.x && y == soolae.y) continue;
		runners[i] = { x,y,dir };
	}
	/*for (auto runner : runners) {
		cout << runner.x << " " << runner.y << " " << runner.dir << "\n";
	}*/
}

void move_soolae() {
	soolae.x += dx[soolae.dir];
	soolae.y += dy[soolae.dir];
	idx++;

	// back
	if ((soolae.x == 0 && soolae.y == 0)) {
		idx = 1;
		go = 0;
		soolae.dir = 2;
	}

	// go
	if (soolae.x == n / 2 && soolae.y == n / 2) {
		idx = 0;
		go = 1;
		soolae.dir = 0;
	}

	// back
	if (!go && idx == (spiral / 2 + 1)) {
		idx = 0;
		spiral--;
		soolae.dir = soolae.dir ? soolae.dir - 1 : 3;
	}

	// go
	if (go && idx == (spiral/2+1)) {
		idx = 0;
		spiral++;
		soolae.dir = (soolae.dir + 1) % 4;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	score = 0;
	cin >> n >> m >> h >> k;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		runners.push_back({ a-1,b-1,c });
	}

	for (int i = 0; i < h; i++) {
		int a, b;
		cin >> a >> b;
		trees[a - 1][b - 1] = 1;
	}

	soolae = { n / 2, n / 2, 0 };
	spiral = 0;
	go = 1;
	for (int i = 0; i < k; i++) {
		move_runners();
		move_soolae();
		check(i+1);
		//cout << soolae.x << " " << soolae.y << " " <<soolae.dir<< "\n";
	}
	cout << score;
	return 0;
}
