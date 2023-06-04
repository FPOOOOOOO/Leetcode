// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
// 4
// RWWW
// 1 2
// 2 3
// 2 4
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100001;
// vector<char> color(N, '0');
// string color;
char color[N];
vector<vector<int> > map(N, vector<int>(N, 0));

void dfs(int u, int parent, char c)
{
    color[u] = c;
    for (int v : map[u])
    {
        if (v == parent)
            continue;
        dfs(v, u, c == 'R' ? 'W' : 'R');
    }
}

int main()
{
    int n;
    int result = 0;
    cin >> n;

    // n个颜色

    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
    }

    // n - 1个链接
    for (int i = 1; i < n; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }

    dfs(1, 0, 'R');

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 'R')
        {
            result += (i % 2 == 0);
        }
        else
        {
            result += (i % 2 == 1);
        }
    }

    if (result > n)
    {
        result = 0;
        dfs(1, 0, 'W');
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 'W')
            {
                result += (i % 2 == 0);
            }
            else
            {
                result += (i % 2 == 1);
            }
        }
    }

    cout << result << endl;
}