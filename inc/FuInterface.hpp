#ifndef SWIG_BOX_FUINTERFACE_HPP
#define SWIG_BOX_FUINTERFACE_HPP
#include <iostream>
#include <memory>

namespace fubar {

    enum class FuErr {
        None = 0,
        Unknown
    };

    std::ostream& operator<<(std::ostream& os, const FuErr& err);

    class IFu {
    public:
        virtual double add(double a, double b) = 0;

        virtual FuErr getErr() const = 0;

        virtual ~IFu() = default;
    };

    using FuPtr = std::unique_ptr<IFu>;

    class FuFactory {
    public:
        static FuPtr MakeFuTypeOne();
        static FuPtr MakeFuTypeTwo();
        static FuPtr MakeFuNoop();
    };

}

#endif //SWIG_BOX_FUINTERFACE_HPP
