#include "FuInterface.hpp"

namespace fubar {

    std::ostream& operator<<(std::ostream& os, const FuErr& err) {
        switch(err) {
            case FuErr::None:
                os << "None";
                break;
            case FuErr::Unknown:
            default:
                os << "Unknown";
        }
        return os;
    }

    class FubarOne : public IFu {
    public:
        constexpr FubarOne() : err(FuErr::None) {}

        constexpr double add(double a, double b) override {
            return a+b;
        }

        FuErr getErr() const override {return err;}
    private:
        FuErr err;
    };

    class FubarTwo : public IFu {
    public:
        constexpr FubarTwo() : err(FuErr::Unknown) {}

        constexpr double add(double a, double b) override {
            return a*b;
        }

        FuErr getErr() const override {return err;}
    private:
        FuErr err;
    };

    class FubarNoop : public IFu {
    public:
        constexpr double add(double a, double b) override {
            return 0.0;
        }

        FuErr getErr() const override {return FuErr::None;}
    };

    FuPtr FuFactory::MakeFuTypeOne() {
        return std::make_unique<FubarOne>();
    }
    FuPtr FuFactory::MakeFuTypeTwo() {
        return std::make_unique<FubarTwo>();
    }

    FuPtr FuFactory::MakeFuNoop() {
      return std::make_unique<FubarNoop>();
    }
}