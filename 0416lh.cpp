#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

long long min_exchange_cost(vector<long long> &AJ, vector<long long> &AQ)
{
    map<long long, long long> countJ_Q;
    for (long long i = 0; i < AJ.size(); i++)
    {
        countJ_Q[AJ[i]]++;
        countJ_Q[AQ[i]]--;
    }

    long long cost = 0;
    long long positive_sum = 0;
    long long sum = 0;

    // 使用迭代器遍历map
    for (auto it = countJ_Q.begin(); it != countJ_Q.end(); ++it)
    {
        if (it->second % 2)
            return -1; // 有奇数就不行
        if (it->second > 0)
        {
            positive_sum += it->second;
        }
        sum += it->second;
    }

    if (sum != 0)
        return -1; // 总和不为0 也不行


    for (auto it = countJ_Q.begin(); it != countJ_Q.end(); ++it)
    {
        if (positive_sum == 0)
        {
            break;
        }
        if (it->second != 0)
        {
            positive_sum -= abs(it->second);
            cost += abs(it->first) * (it->second) / 2;
        }
    }

    return cost;
}

int main()
{

    long long n;
    cin >> n;
    vector<long long> AJ(n), AQ(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> AJ[i];
    }
    for (long long i = 0; i < n; i++)
    {
        cin >> AQ[i];
    }

    cout << min_exchange_cost(AJ, AQ) << endl;

    return 0;
}
