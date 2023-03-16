#include <format>
#include <iostream>
#include "FuInterface.hpp"

#include "fmt/format.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    auto a = 2.14;
    auto b = 3.98;

    std::cout << "a=" << a << ", b=" << b << "\n\n";

    auto fubar = fubar::FuFactory::MakeFuTypeOne();

    std::cout << std::format(" foo test: {}\n", fubar->add(a,b));
    std::cout << " foo err: " << fubar->getErr() << "\n\n";

    fubar = fubar::FuFactory::MakeFuTypeTwo();

    std::cout << std::format(" foo test2: {}\n", fubar->add(a,b));
    std::cout << " foo2 err: " << fubar->getErr() << "\n\n";

    fubar = fubar::FuFactory::MakeFuNoop();

    std::cout << std::format(" foo test noop: {}\n", fubar->add(a,b));
    std::cout << " noop err: " << fubar->getErr() << "\n";

    return 0;
}
