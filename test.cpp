#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int> > edges[N]; // 存储每个节点的边和对应权值


long long dp[N][2]; // dp[i][0]表示不选第i个节点，dp[i][1]表示选第i个节点

void dfs(int u, int parent) {
    long long temp = INT_MIN;
    long long u0 = 0;
    for (auto &edge : edges[u]) { // 遍历当前节点u的所有边
        int v = edge.first; // 相邻节点
        int w = edge.second; // 边的权值
        if (v != parent) { // 防止重复遍历，跳过父节点
            dfs(v, u); // 递归地遍历子节点
            dp[u][1] = max(dp[u][1], dp[v][0] + w); // 选择当前节点u的最大权值
            dp[u][0] = max(dp[u][0], max(dp[v][0], dp[v][1])); // 不选择当前节点u的最大权值
        }
    }
}

int main() {
    int n;
    cin >> n; // 输入节点数

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w; // 输入每条边的两个节点和权值
        edges[u].push_back(make_pair(v, w)); // 存储边和权值信息
        edges[v].push_back(make_pair(u, w));
    }

    dfs(1, -1); // 从第一个节点开始遍历树，并计算动态规划状态

    // 输出选与不选根节点的最大权值中的较大值
    cout << max(dp[1][0], dp[1][1]) << endl;

    return 0;
}
