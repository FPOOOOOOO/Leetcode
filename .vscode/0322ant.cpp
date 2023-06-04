#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10][10];
int dp[10][10];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        dp[n][i] = a[n][i];
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
        }
    }
    cout << dp[1][1] << endl;
    return 0;
}
