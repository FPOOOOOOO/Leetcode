// ����ôһ��α����
// input a,b,m,x
// while true:
//   x=(a*x+b)%m
//   print(x)
// end while
// �����x��������ȡģ�����µģ����Ի����ѭ����
// ���磬a=2, b=1, m=5, x=2��ʱ����������н������£�
// 0,1,3,2,0,1,3,2,0,1,3,2....
// ���У�0,1,3,2 ��Ϊ��̵�ѭ���ڡ�
// ���ڸ���a,b,m,x��ֵ������������ѭ���ڵĳ��ȡ�

// ��������
// ����4������a,b,m,x
// �������
// ���һ���������ѭ���ڵĳ���
// 2 1 5 2
// 4

#include <iostream>
#include <set>
using namespace std;

int main(){
    int a, b, m, x;
    cin >> a >> b >> m >> x;

    set<int> map;

    x = (a * x + b) % m;

    int count = 0;
    while(true){
        x = (a * x + b) % m;
        if(map.count(x)){
            cout << count;
            return 0;
        }
        map.insert(x);
        count++;
    }

}

//int ���У���long����ȫ��ͨ��