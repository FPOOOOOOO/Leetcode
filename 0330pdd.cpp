// ����Ϊ���Ե��ж�����������淶ʾ���������ύ�����Ʒ֡�
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
const long N = 100;
 //<�����ĳ��У���·�û�>
long result = 0;

long dfs(long cur, long parent){    
    long now = 0;
    long temp = 0;

    for(auto &daolu : daolus[cur]){
        long neighbor = daolu.first;
        int haohuai = daolu.second;
        if(neighbor != parent){
            temp = dfs(neighbor, cur);
            now += temp;
            if(haohuai && !temp){
                now += 1;
            }
        }
    }
    return now;
}

int main() {
    long n;
    vector<pair<long, int> > daolus[N];
    cin >> n;
    for(long i = 0; i < n - 1; i++){
        long ai, bi;
        int ci;
        cin >> ai >> bi >> ci;
        daolus[ai].push_back(make_pair(bi, ci));
        daolus[bi].push_back(make_pair(ai, ci));
    }
    
    result = dfs(1, -1);
    
    cout << result << endl;

}