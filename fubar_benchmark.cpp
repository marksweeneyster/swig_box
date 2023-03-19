#include <benchmark/benchmark.h>
#include "FuInterface.hpp"

static void BM_SomeFunction(benchmark::State& state) {
    // Perform setup here

    auto a = 2.14;
    auto b = 3.98;

    auto fubar = fubar::FuFactory::MakeFuTypeOne();

    for (auto _ : state) {
        // This code gets timed
        fubar->add(a,b);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_SomeFunction);
// Run the benchmark
BENCHMARK_MAIN();