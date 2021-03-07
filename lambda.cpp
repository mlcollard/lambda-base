/*
    lambda.cpp

    Examples of captures in lambda functions
*/

#include <functional>
#include <sstream>
#include <assert.h>

// NOTE: return type for C++ functions/methods
double average1(int n1, int n2);

// NOTE: trailing return type for C++ functions/methods
// NOTE: For non-lambda, requires auto


// runs code with argument 1
int run(std::function<int(int)> code) {

    return code(1);
}

class Application {
public:
    int apply(int n) {
        return n + 2;
    }

    static int applyApplication(int n) {
        return n + 2;
    }
};

int main(int argc, char* argv[]) {

    // empty capture
    {
        auto result = run(
            [](int n)->int {
                return n + 2;
            }
        );
        assert(result == 3);
    }

    // empty capture, use constant
    {
        constexpr int INCR = 2;
        auto result = run(
            [](int n)->int {
                return n + 2;
            }
        );
        assert(result == 3);
    }
    
    // capture variable because not constexpr
    {
        int size = 2;
        const int incr = size;
        auto result = run(
            [](int n)->int {
                return n + 2;
            }
        );
        assert(result == 3);
    }

    // non-const variable capture value
    {
        int incr = 2;
        auto result = run(
            [](int n)->int {
                return n + 2;
            }
        );
        assert(result == 3);
    }

    // non-const variable capture reference
    {
        const int INCR = 2;
        int numrun = 0;
        auto result = run(
            [](int n)->int {
                return n + 2;
            }
        );
        assert(result == 3);
    }

    // pass complex object
    {
        std::istringstream input("2");
        auto result = run(
            [](int n)->int {
                return n + 2;
            }
        );
        assert(result == 3);
    }

    // pass static method
    {
        auto result = run(
            [](int n)->int {
                return n + 2;
            }
        );
        assert(result == 3);
    }

    // pass method
    {
        Application application;
        auto result = run(
            [](int n)->int {
                return n + 2;
            }
        );
        assert(result == 3);
    }

    return 0;
}
