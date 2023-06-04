#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 20;
const int MAXSCORE = 100;

int n, sum;
int score[MAXN];
bool dp[MAXN][MAXSCORE];

int main()
{
    cin >> n;
    for (int i = 1; i <= n * 2; i++)
    {
        cin >> score[i];
        sum += score[i];
    }

    sort(score + 1, score + n * 2 + 1);
    dp[0][0] = true;

    for (int i = 1; i <= n * 2; i++)
    {
        dp[i][score[i]] = true;
        dp[i][0] = true;
    }

    for (int i = 1; i <= n * 2; i++)
    {
        for (int j = sum / 2; j >= score[i]; j--)
        {
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - score[i]];
        }
    }

    // for (int i = 1; i <= n * 2; i++)
    // {
    //     for (int j = sum / 2; j >= score[i]; j--)
    //     {
    //         dp[i][j] = dp[i - 1][j] || dp[i - 1][j - score[i]];
    //     }
    // }

    int diff = 0;
    for (int j = sum / 2; j >= 0; j--)
    {
        if (dp[n * 2 - 1][j])
        {
            diff = sum - j * 2;
            break;
        }
    }

    cout << diff << endl;

    return 0;
}
