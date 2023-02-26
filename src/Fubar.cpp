#include "FuInterface.hpp"

namespace fubar {
    class FubarImpl : public IFu {
    public:
        double add(double a, double b) override {
            return a+b;
        }
    };

    class FubarProdImpl : public IFu {
    public:
        double add(double a, double b) override {
            return a*b;
        }
    };

    FuPtr FuFactory::MakeFuTypeOne() {
        return std::make_unique<FubarImpl>();
    }
    FuPtr FuFactory::MakeFuTypeTwo() {
        return std::make_unique<FubarProdImpl>();
    }

}