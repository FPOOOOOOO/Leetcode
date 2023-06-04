#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int N = 100;

int main()
{
    int n, m;
    cin >> n >> m;
    int x[n + 1];
    int y[n + 1];
    vector<int> dp(n + 1, 0);
    vector<pair<int, int> > nums[n + 1]; //<type, price>
    unordered_map<int, int> last;       //<type, pos>

    for (int i = 1; i <= n; i++)
    {
        char a;
        int type, price;
        cin >> a;
        cin >> type;
        if (a == 'b')
        {
            price = 0;
            nums[i].push_back(make_pair(type, price));
            last[type] = -1;
        }
        else
        {
            cin >> price;
            nums[i].push_back(make_pair(type, price));
        }
    }

    for (int i = 1; i <= n; i++)
    {
        //进行dp，同时保证last[type]存在
        if(last[nums[i][0].first] != -1){
            dp[i] = max(dp[i - 1], dp[last[nums[i][0].first]] + nums[i][0].second);
        }
        //如果是b关，那么更新last[type]
        if (nums[i][0].second == 0)
        {
            last[nums[i][0].first] = i;
        }
    }

    cout << dp[n] << endl;

    return 0;
}
