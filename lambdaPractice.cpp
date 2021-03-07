/*
    lambdaPractice.cpp

    Practice for writing lambda functions
*/

#include <iostream>
#include <functional>
#include <assert.h>

int main(int argc, char* argv[]) {

    // conversion lamda that adds 2 to a number
    {
        std::function<int(int)> conversion = [](int n)->int { return n + 2; };

        if (conversion != nullptr) {
            int result = conversion(1);

            assert(result == 3);

            std::cout << "Add 2 to a number\n";
        }
    }

    // conversion lamda that subtracts 2 from a number
    {
        std::function<int(int)> conversion;

        if (conversion != nullptr) {
            int result = conversion(3);

            assert(result == 1);

            std::cout << "Subtract 2 from a number\n";
        }
    }

    // conversion lamda that adds 2 numbers
    {
        std::function<int(int, int)> conversion;

        if (conversion != nullptr) {
            int result = conversion(1, 2);

            assert(result == 3);

            std::cout << "Add 2 numbers\n";
        }
    }

    // conversion lamda that subtracts the second number from the first
    {
        std::function<int(int, int)> conversion;

        if (conversion != nullptr) {
            int result = conversion(3, 1);

            assert(result == 1);

            std::cout << "Subtract 2 numbers\n";
        }
    }

    return 0;
}
