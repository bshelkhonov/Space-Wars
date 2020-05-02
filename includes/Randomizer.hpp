#ifndef SPACE_WARS_RANDOMIZER_HPP
#define SPACE_WARS_RANDOMIZER_HPP


#include <random>
#include <numeric>
#include <chrono>
#include <cstdint>


class Randomizer {
private:
    static std::mt19937_64 rng_;
public:
    static int64_t randint(int64_t = 0, int64_t = std::numeric_limits<int64_t>::max());
};


#endif //SPACE_WARS_RANDOMIZER_HPP
