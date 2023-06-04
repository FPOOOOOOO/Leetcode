#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

int main(){
    int n;
    int k;

    cin >> n >> k;

    vector<long long> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int result = 0;

    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < k; i++){
        
    }

    return 0;
}