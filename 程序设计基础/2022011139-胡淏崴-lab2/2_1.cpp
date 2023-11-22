#include <iostream>
#include <conio.h>  // 用于 _getch() 函数的头文件

int main() {
    char userInput;
    std::cout << "Press a key (q to quit): ";

    while (true) {
        userInput = _getch();  // 使用 _getch() 无需回车即时读入字符
        std::cout << userInput << std::endl;

        if (userInput == 'q') {
            std::cout << "Exiting the program." << std::endl;
            break;
        }
    }

    return 0;
}
