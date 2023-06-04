#include <iostream>
using namespace std;
const int N = 1e4 + 10;
int a[N], w[N];
char v[N];
int f[N][N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> a[i];
        if (v[i] == 'm')
        {
            cin >> w[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v[i] == 'm')
                f[i][0] = max(f[i - 1][0], f[i - 1][j] + w[i]);
            else
                f[i][j] = max(f[i - 1][j], f[i - 1][0]);
        }
    }
    int res = 0;
    for (int i = 0; i <= m; i++)
    {
        res = max(f[n][i], res);
    }

    cout << res << endl;
    
    return 0;
}
