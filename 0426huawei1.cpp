// #include <bits/stdc++.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

int main()
{
    int n;
    cin >> n;
    int yilai[n][n];
    int index[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            yilai[i][j] = -1;
            index[i][j] = -1;
        }
    }

    int startnum = 0;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> yilai[i][j];
        }
        if (yilai[i][0] == -1)
        {
            index[0][startnum] = i;
            startnum++;
        }
    }

    //有循环，所以跳出
    if(index[0][0] == -1){
        cout << -1 << endl;
        return 0;
    }

    // while(1){  
    //     for(int i = 0; i < n; i++){
    //         for(int j = 0; yilai[i][j]!= -1; j++){
    //             if(yilai[i][j] == index[0][])
    //         }
    //     }
    // }

    int result = 0;

    cout<< result << endl;
    return 0;
}
