#include "FuInterface.hpp"
#include "fmt/format.h"

template <> struct fmt::formatter<fubar::FuErr> {
    // boilerplate for this simple case
    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const fubar::FuErr& err, FormatContext& ctx) const -> decltype(ctx.out()) {
        // ctx.out() is an output iterator to write to.
        switch(err) {
            case fubar::FuErr::None:
                return fmt::format_to(ctx.out(), "None");
            case fubar::FuErr::Unknown:
            default:
                return fmt::format_to(ctx.out(), "Unknown");
        }
    }
};

int main() {
    auto a = 2.14;
    auto b = 3.98;

    fmt::print("Fubar \"add\" {0:#} and {1:#}\n\n",a,b);

    auto fubar = fubar::FuFactory::MakeFuTypeOne();

    fmt::print(" foo test: {0:#}\n", fubar->add(a,b));
    fmt::print(" foo err: {}\n\n", fubar->getErr());

    fubar = fubar::FuFactory::MakeFuTypeTwo();

    fmt::print(" foo test2: {0:#}\n", fubar->add(a,b));
    fmt::print(" foo err: {}\n\n", fubar->getErr());

    fubar = fubar::FuFactory::MakeFuNoop();

    fmt::print(" foo noop: {0:#}\n", fubar->add(a,b));
    fmt::print(" foo err: {}\n", fubar->getErr());

    return 0;
}
