#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int> > edges[N]; // �洢ÿ���ڵ�ıߺͶ�ӦȨֵ


long long dp[N][2]; // dp[i][0]��ʾ��ѡ��i���ڵ㣬dp[i][1]��ʾѡ��i���ڵ�

void dfs(int u, int parent) {
    long long temp = INT_MIN;
    long long u0 = 0;
    for (auto &edge : edges[u]) { // ������ǰ�ڵ�u�����б�
        int v = edge.first; // ���ڽڵ�
        int w = edge.second; // �ߵ�Ȩֵ
        if (v != parent) { // ��ֹ�ظ��������������ڵ�
            dfs(v, u); // �ݹ�ر����ӽڵ�
            dp[u][1] = max(dp[u][1], dp[v][0] + w); // ѡ��ǰ�ڵ�u�����Ȩֵ
            dp[u][0] = max(dp[u][0], max(dp[v][0], dp[v][1])); // ��ѡ��ǰ�ڵ�u�����Ȩֵ
        }
    }
}

int main() {
    int n;
    cin >> n; // ����ڵ���

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w; // ����ÿ���ߵ������ڵ��Ȩֵ
        edges[u].push_back(make_pair(v, w)); // �洢�ߺ�Ȩֵ��Ϣ
        edges[v].push_back(make_pair(u, w));
    }

    dfs(1, -1); // �ӵ�һ���ڵ㿪ʼ�������������㶯̬�滮״̬

    // ���ѡ�벻ѡ���ڵ�����Ȩֵ�еĽϴ�ֵ
    cout << max(dp[1][0], dp[1][1]) << endl;

    return 0;
}
