// ������ֵ�Ĺ淶���ǽ��ڹ�˾��һ�����⣬��������Ҫдһ�������������һ���⣺
// 1.������ֵ����������Ҫ��ÿ3λ��һ��Ӣ�Ķ���','���������ţ�������12345678Ӧ�ù淶��Ϊ12,345,678
// 2.������ֵ���ֻ����λС��������ж����С��λ��Ӧ����ȥ��ע�⣬�����������롣
// 3.��������Ƿ��ڹ淶����Ӧ������ֵ���˼������� '(' �� ')' ��Ȼ��ʡ�Ե����š�
// 4.Ӧ������ֵǰ�棬ǰ���ź��棨��������ŵĻ������Ͻ�Ǯ����'$'���������ţ�
// ���ڸ���һ�����֣�����淶����һ����

// ��������
// ��������������ݣ�ÿ������һ��һ�����֣�����ΪС��������������������С�������㡣
// ���ݱ�֤����û��ǰ��0����֤�������Ƿ0Ԫ�����
// �������
// ����淶���������

// ��������
// 203323
// 0.0
// 0.000000
// 0.009212121
// 343444323.32432
// -12344.1
// -12345678.9
// �������
// $203,323.00
// $0.00
// $0.00
// $0.00
// $343,444,323.32
// ($12,344.10)
// ($12,345,678.90)

#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;

    while(cin >> input){
        bool negetive = false;
        string output;

        if(input[0] == '-'){
            negetive = true;
            input = input.substr(1);
        }

        printf("input size %d \n", input.size());

        int dot = -1;
        dot = input.find('.');
        
        //��С����:
        if(dot != -1){
            if(input.size() - 1 - dot > 2){
                input = input.substr(0, dot + 3); //С�������
            }else if(input.size() - 1 - dot == 1){
                input += '0';
            }else if(input.size() - 1 - dot == 0){
                input += '0';
                input += '0';
            }
            
            for(int i = 0; i < input.size(); i++){
                output += input[i];
                if(i < dot && i != (dot - 1) && (dot - i - 1) % 3 == 0){
                    output += ',';
                }
            }
        }else if(dot == -1){ //û��С����
            for(int i = 0; i < input.size(); i++){
                output += input[i];
                if(i != (input.size() - 1) && (input.size() - 1 - i) % 3 == 0){
                    output += ',';
                }
            }
        }

        if(negetive){
            output = '(' + output + ')';
        }

        output = '$' + output;

        cout << output << endl;
    }
    
    return 0 ;

}