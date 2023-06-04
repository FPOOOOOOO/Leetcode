#include <iostream>
#include <map>
using namespace std;

long long min_exchange_cost(int n, int AJ[], int AQ[]) {
    long long sum_J = 0, sum_Q = 0;
    map<int, int> count_J, count_Q;
    for (int i = 0; i < n; i++) {
        sum_J += AJ[i];
        count_J[AJ[i]]++;
        sum_Q += AQ[i];
        count_Q[AQ[i]]++;
    }
    // if (sum_J != sum_Q) {
    //     return -1;
    // }
    long long cost = 0;
    for (auto& [j, count_j] : count_J) {
        auto it = count_Q.find(j);
        while (it != count_Q.end() && count_j > 0) {
            int exchange_count = min(count_j, it->second);
            cost += exchange_count * j;
            count_j -= exchange_count;
            it->second -= exchange_count;
            if (it->second == 0) {
                count_Q.erase(it);
            }
            it = count_Q.find(j);
        }
    }
    return cost;
}

int main() {
    long long n;
    cin >> n;
    int AJ[n], AQ[n];
    for (int i = 0; i < n; i++) {
        cin >> AJ[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> AQ[i];
    }
    cout << min_exchange_cost(n, AJ, AQ) << endl;
    return 0;
}
