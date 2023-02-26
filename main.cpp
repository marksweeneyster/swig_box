#include <iostream>
#include "FuInterface.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    auto fubar = fubar::FuFactory::MakeFuTypeOne();

    std::cout << " foo test: " << fubar->add(2.14,3.98) << std::endl;

    fubar = fubar::FuFactory::MakeFuTypeTwo();

    std::cout << " foo test2: " << fubar->add(2.14,3.98) << std::endl;

    return 0;
}
