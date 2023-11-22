#include <stdio.h>

int main() {
    int number = 42;
    double pi = 3.14159265359;

    // 控制整数位数和填充
    printf("%05d\n", number); // 输出 "00042"

    // 控制小数位数
    printf("%.2f\n", pi); // 输出 "3.14"

    // 科学计数法
    printf("%.2e\n", pi); // 输出 "3.14e+00"

    // 输出不同进制
    int hexNumber = 255;
    printf("%x\n", hexNumber); // 输出 "ff"，16进制
    printf("%o\n", hexNumber); // 输出 "377"，8进制

    // 控制对齐方式
    printf("%-10s%10s\n", "Hello", "World"); // 输出 "Hello     World"

    return 0;
}
