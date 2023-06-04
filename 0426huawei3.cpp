#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
using namespace std;


// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

void fenpei2(list<int>& pool, int num){
    for(list<int>::iterator it = pool.begin(); it != pool.end(); it++){
        if(*it == num){
            pool.erase(it);
            break;
        }
    }
    return;
}

void fenpei1(list<int>& pool, int count){
    if(count > pool.size()){
        return;
    }
    int i = 0;
    for(list<int>::iterator it = pool.begin(); i < count; i++){
        pool.erase(it);
        it++;
    }
    return;
}

int main()
{
    int start, end;
    cin >> start >> end;

    list<int> pool;

    for(int i = start; i <= end; i++){
        pool.push_back(i);
    }

    
    int N;
    cin >> N;
    
    int op[N][2];
    
    for(int i = 0; i < N; i++){
        cin >> op[i][0] >> op[i][1];
    }
    
    for(int i = 0; i < N; i++){
        if(op[i][0] == 1){
            fenpei1(pool,op[i][1]);
        }
        else if(op[i][0] == 2){
            fenpei2(pool,op[i][1]);
        }else if(op[i][0] == 3){
            pool.push_back(op[i][1]);
        }
    }
    
    cout << pool.front() << endl;
    
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;

    return 0;
}
