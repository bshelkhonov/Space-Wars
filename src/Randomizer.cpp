#include "Randomizer.hpp"


std::mt19937_64 Randomizer::rng_ = std::mt19937_64(
        std::chrono::high_resolution_clock::now().time_since_epoch().count());

int64_t Randomizer::randint(int64_t l, int64_t r) {
    std::uniform_int_distribution<int64_t> get(l, r);
    return get(rng_);
}
