#include <iostream>
#include <memory>
#include "calc.h"
#include "rng_mt19937.h"

int run() {
    auto rng = std::make_unique<RandomNumberGeneratorMt19937>();
    Calc c{rng.get()};

    std::cout << "2 + 2 = " << c.Sum(2, 2) << std::endl;
    std::cout << "3 * 3 = " << c.Multiply(3, 3) << std::endl;
    std::cout << "3 + random number = " << c.AddRandomNumber(3) << std::endl;
    return 0;
}
