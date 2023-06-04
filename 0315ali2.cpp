#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

int main(){

    int n;
    cin >> n;

    unordered_map<long long, int> freq;  //µ¹Ðð
    map<long long, int> freqq;

    for(int i = 0; i < n; i++){                       
        long long a;
        cin >> a;
        freq[a]++;
        freqq[a]++;
    }

    long long result = 0;

    for(const auto& entry : freq){
        long long a = entry.first;
        int count = entry.second;
        printf("%ld \n",a);
        //a a a + 1
        //a a + 1 a + 1
        if(freq.count(a + 1)){
            result = result + count * (count - 1) / 2 * freq[a + 1];
            result = result + count * freq[a + 1] * (freq[a + 1] - 1) / 2;
        }       
    }

    cout << result << endl;

    return 0;
}