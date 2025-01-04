#include <iostream>
#include "calc.h"

int main() {
    Calc c;
    std::cout << "2 + 2 = " << c.Sum(2, 2) << std::endl;
    std::cout << "3 * 3 = " << c.Multiply(3, 3) << std::endl;
    return 0;
}
