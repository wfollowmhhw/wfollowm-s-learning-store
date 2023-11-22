#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <chrono>

int main() {
    char userInput;
    bool testing = false;
    bool correctResponse = false;
    srand(static_cast<unsigned>(time(nullptr)));

    std::cout << "Press 's' to start the test or 'q' to quit." << std::endl;

    while (true) {
        userInput = _getch();

        if (userInput == 'q') {
            std::cout << "Exiting the program." << std::endl;
            break;
        }
        else if (userInput == 's') {
            std::cout << "Test started. Press 'a' for 'Left' and 'd' for 'Right'." << std::endl;
            testing = true;
        }

        if (testing) {
            std::cout << "Get ready..." << std::endl;

            // Generate a random time delay between 2 and 5 seconds
            int delay = 2 + rand() % 4;
            sleep(delay);  // Sleep for the generated delay

            // Generate a random direction
            int direction = rand() % 2;
            std::string prompt = (direction == 0) ? "Left" : "Right";
            std::cout << prompt << std::endl;

            auto start_time = std::chrono::high_resolution_clock::now();  // Start timing

            while (!correctResponse) {
                userInput = _getch();
                if (userInput == 'a' && direction == 0) {
                    auto end_time = std::chrono::high_resolution_clock::now();  // Stop timing
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
                    correctResponse = true;
                    std::cout << "Reaction time: " << duration.count() << " microseconds" << std::endl;
                }
                else if (userInput == 'd' && direction == 1) {
                    auto end_time = std::chrono::high_resolution_clock::now();  // Stop timing
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
                    correctResponse = true;
                    std::cout << "Reaction time: " << duration.count() << " microseconds" << std::endl;
                }
            }

            correctResponse = false;
        }
    }

    return 0;
}
