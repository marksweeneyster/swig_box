#include "FuInterface.hpp"

namespace fubar {
    class FubarImpl : public IFu {
    public:
        FubarImpl() : err(FuErr::None) {}

        double add(double a, double b) override {
            return a+b;
        }

        FuErr getErr() const override {return err;}
    private:
        FuErr err;
    };

    class FubarProdImpl : public IFu {
    public:
        FubarProdImpl() : err(FuErr::Unknown) {}

        double add(double a, double b) override {
            return a*b;
        }

        FuErr getErr() const override {return err;}
    private:
        FuErr err;
    };

    FuPtr FuFactory::MakeFuTypeOne() {
        return std::make_unique<FubarImpl>();
    }
    FuPtr FuFactory::MakeFuTypeTwo() {
        return std::make_unique<FubarProdImpl>();
    }

}