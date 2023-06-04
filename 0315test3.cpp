// 货币数值的规范化是金融公司的一个问题，现在你需要写一个程序来解决这一问题：
// 1.货币数值的整数部分要求每3位加一个英文逗号','（不含引号）。例如12345678应该规范化为12,345,678
// 2.货币数值最多只有两位小数，如果有多余的小数位数应当舍去。注意，不是四舍五入。
// 3.负数代表欠款，在规范化后应当在数值两端加上括号 '(' 和 ')' ，然后省略掉负号。
// 4.应当在数值前面，前括号后面（如果有括号的话）加上金钱符号'$'（不含引号）
// 现在给你一个数字，请你规范化这一数字

// 输入描述
// 输入包含多种数据，每组数据一行一个数字，可能为小数，整数，负整数，负小数或者零。
// 数据保证数字没有前导0，保证不会出现欠0元的情况
// 输出描述
// 输出规范化后的内容

// 样例输入
// 203323
// 0.0
// 0.000000
// 0.009212121
// 343444323.32432
// -12344.1
// -12345678.9
// 样例输出
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
        
        //有小数点:
        if(dot != -1){
            if(input.size() - 1 - dot > 2){
                input = input.substr(0, dot + 3); //小数点后保留
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
        }else if(dot == -1){ //没有小数点
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