#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string king, rock;
    int n;

    cin >> king >> rock >> n;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        string tmp_king = king;
        if (cmd == "R") {
            tmp_king[0]++;
        }
        else if (cmd == "L") {
            tmp_king[0]--;
        }
        else if (cmd == "B") {
            tmp_king[1]--;
        }
        else if (cmd == "T") {
            tmp_king[1]++;
        }
        else if (cmd == "RT") {
            tmp_king[0]++;
            tmp_king[1]++;
        }
        else if (cmd == "LT") {
            tmp_king[0]--;
            tmp_king[1]++;
        }
        else if (cmd == "RB") {
            tmp_king[0]++;
            tmp_king[1]--;
        }
        else if (cmd == "LB") {
            tmp_king[0]--;
            tmp_king[1]--;
        }

        if (tmp_king[0] < 'A' || tmp_king[0] > 'H') continue;
        if (tmp_king[1] < '1' || tmp_king[1] > '8') continue;

        if (tmp_king != rock) {
            king = tmp_king;
            continue;
        }

        string tmp_rock = rock;
        if (cmd == "R") {
            tmp_rock[0]++;
        }
        else if (cmd == "L") {
            tmp_rock[0]--;
        }
        else if (cmd == "B") {
            tmp_rock[1]--;
        }
        else if (cmd == "T") {
            tmp_rock[1]++;
        }
        else if (cmd == "RT") {
            tmp_rock[0]++;
            tmp_rock[1]++;
        }
        else if (cmd == "LT") {
            tmp_rock[0]--;
            tmp_rock[1]++;
        }
        else if (cmd == "RB") {
            tmp_rock[0]++;
            tmp_rock[1]--;
        }
        else if (cmd == "LB") {
            tmp_rock[0]--;
            tmp_rock[1]--;
        }

        if (tmp_rock[0] < 'A' || tmp_rock[0] > 'H') continue;
        if (tmp_rock[1] < '1' || tmp_rock[1] > '8') continue;

        king = tmp_king;
        rock = tmp_rock;
        
    }
    cout << king << "\n" << rock;
    return 0;
}
