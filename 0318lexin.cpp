// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int min_val;

void dp(unordered_map<int, int>&score_2_count, vector<int>&score_number, int index, int target, int team_count, int current_team_count){
    if(current_team_count == team_count){
        min_val = min(min_val, target);
    }
    if(index == score_number.size()) return;
    
    int score = score_number[index];
    int number_of_people = score_2_count[score];
    
    for(int i = 0; i <= number_of_people; i++){
        if(score * i <= target && current_team_count + i <= team_count){
            dp(score_2_count, score_number, index+1, target - score * i, team_count, current_team_count + i);
        }
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
    
    unordered_map<int, int> score_2_count;
    for(const auto& item : score){
        score_2_count[item] = score_2_count[item] + 1;
    }
    
    vector<int> score_number;
    for(const auto& item : score_2_count){
        score_number.push_back(item.first);
    }
    
    min_val = INT32_MAX;
    
    dp(score_2_count, score_number, 0 ,target, n, 0);
    
    int small_one = target - min_val;
    int big_one = sum_of_score - small_one;
    
    cout << big_one - small_one <<endl;
    
    return 0;
}