#ifndef SWIG_BOX_FUINTERFACE_HPP
#define SWIG_BOX_FUINTERFACE_HPP
#include <memory>

namespace fubar {
    class IFu {
    public:
        virtual double add(double a, double b) = 0;

        virtual ~IFu() { };
    };

    using FuPtr = std::unique_ptr<IFu>;

    class FuFactory {
    public:
        static FuPtr MakeFuTypeOne();
        static FuPtr MakeFuTypeTwo();
    };

}

#endif //SWIG_BOX_FUINTERFACE_HPP
