// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int min_val;

void dp(vector<int>&score, int index, int current_team_count, int target, int team_count){
    if(current_team_count == team_count){
        min_val = min(min_val, target);
    }
    if(index == score.size()) return;
    
    if(score[index] <= target && current_team_count < team_count){
        dp(score, index + 1, current_team_count + 1, target - score[index], team_count);
    }
}

void backtracking(vector<int>& score, int target, int sum, int index, int current_num, int num){
    if(target < sum) return;
    if(current_num == num && target >= sum){
        min_val = min(min_val, target - sum);
        return;
    }

    for(int i = index; i < score.size(); i ++){
        sum += score[i];
        current_num++;
        backtracking(score, target, sum, index + 1, current_num, num);
        sum -= score[i];
        current_num--;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> score(2 * n, 0);
    
    int sum_of_score = 0;
    for(int i = 0; i < 2 * n; i++){
        cin >> score[i];
        sum_of_score += score[i];
    }
    
    sort(score.begin(),score.end());
    
    int target = 0;
    target = sum_of_score / 2;
    
    min_val = INT32_MAX;
    
    // for(int i = 0; i < 2 * n; i++){
    //     for(int j = target; j >= score[i]; j--){

    //     }
    // }


    backtracking(score, target, 0, 0, 0, n);
    // dp(score, 0 , 0 ,target, n);
    
    int small_one = target - min_val;
    int big_one = sum_of_score - small_one;
    
    cout << big_one - small_one <<endl;
    
    return 0;
}