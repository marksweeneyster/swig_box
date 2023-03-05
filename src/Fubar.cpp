#include "FuInterface.hpp"

namespace fubar {
    class FubarOne : public IFu {
    public:
      FubarOne() : err(FuErr::None) {}

        double add(double a, double b) override {
            return a+b;
        }

        FuErr getErr() const override {return err;}
    private:
        FuErr err;
    };

    class FubarTwo : public IFu {
    public:
        FubarTwo() : err(FuErr::Unknown) {}

        double add(double a, double b) override {
            return a*b;
        }

        FuErr getErr() const override {return err;}
    private:
        FuErr err;
    };

    class FubarNoop : public IFu {
    public:
      double add(double a, double b) override {
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