#include <iostream>

int main() {//需要注意，由于在此处输出了中文，请您为编译器提供中文编码环境，否则会出现乱码
    // 红色文本
    std::cout << "\033[31m此乃红色\033[0m" << std::endl;

    // 绿色文本，黄色背景
    std::cout << "\033[32;43m此乃绿色文本，黄色背景\033[0m" << std::endl;

    return 0;
}
