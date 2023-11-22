#include <iostream>
#include <iomanip> // 头文件用于格式设置

using namespace std;

int main() {
    int number = 42;
    double pi = 3.14159265359;

    // 控制整数位数和填充
    cout << setfill('0') << setw(5) << number << endl; // 输出 "00042"

    // 控制小数位数
    cout << fixed << setprecision(2) << pi << endl; // 输出 "3.14"

    // 科学计数法
    cout << scientific << pi << endl; // 输出 "3.141593e+00"

    // 输出不同进制
    int hexNumber = 255;
    cout << hex << hexNumber << endl; // 输出 "ff"，16进制
    cout << oct << hexNumber << endl; // 输出 "377"，8进制

    // 控制对齐方式
    cout << left << setw(10) << "Hello" << right << "World" << endl; // 输出 "Hello     World"

    return 0;
}
