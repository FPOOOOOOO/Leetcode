#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 20;
const int MAXSCORE = 1000;

int n, sum;
int score[MAXN];


int main() {
    cin >> n;
    for (int i = 1; i <= n * 2; i++) {
        cin >> score[i];
        sum += score[i];
    }

    sort(score + 1, score + n * 2 + 1);

    int dp[MAXN][MAXSCORE][MAXN];
    //memset(dp, 0, sizeof(dp));

    int target = sum / 2;

    for (int i = 1; i <= n * 2; i++) {
        for (int j = 1; j <=i; j++) {
            for(int k = target; k >= score[i]; k--){
                dp[i][j][k] = max(dp[i - 1][j - 1][k - score[i]] + score[i], dp[i - 1][j][k]);
            }
        }
    }

    int diff = 0;
    int small_team = 0;

    for(int i = n; i < 2*n;i++){
        small_team = max(small_team, dp[i][n][target]);
    }


    diff = sum - 2 * small_team;

    // for (int j = sum / 2; j >= 0; j--) {
    //     if (dp[n*2][j]) {
    //         diff = sum - j*2;
    //         break;
    //     }
    // }

    cout << diff << endl;

    return 0;
}
