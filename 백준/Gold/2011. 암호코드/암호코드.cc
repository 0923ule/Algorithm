#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dp[5005] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string n;
    cin >> n;
    n = "0" + n;

    dp[0] = 1;
    if (n[1] != '0') dp[1] = 1;

    for (int i = 2; i < n.size(); i++) {
        int aa = 1;
        if (n[i] == '0' && (n[i] - '0') <= 2) aa = 0;

        int bb = 0;
        int tmp = (n[i - 1] - '0') * 10 + (n[i] - '0');
        if (n[i - 1] != '0' && tmp <= 26) bb = 1;

        
        dp[i] = ((dp[i - 1] * aa) + (dp[i - 2] * bb)) % 1'000'000;
    }

    cout << dp[n.size() - 1];

    return 0;
}