#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Hello world" << std::endl;
    return 0;
}
