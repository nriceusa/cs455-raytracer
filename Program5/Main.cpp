#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>

class MyClass {
public:
    int value = 7;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Tangent of pi/4: " << tan(M_PI / 4) << std::endl;

    std::vector<int> test_vector;

    MyClass object;
    std::cout << object.value;

    return 0;
}