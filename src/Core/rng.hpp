//
//  rng.hpp
//  MedievalCombat
//
//  Created by Austin Horn on 1/9/23.
//

#ifndef rng_hpp
#define rng_hpp

#include <random>

static const unsigned random_ranged_uint(unsigned min, unsigned max) noexcept {
    std::mt19937 gen32(std::random_device{}());
    std::uniform_int_distribution<unsigned> distrib(min, max);
    return distrib(gen32);
}
static const signed random_ranged_int(signed min, signed max) noexcept {
    std::mt19937 gen32(std::random_device{}());
    std::uniform_int_distribution<signed> distrib(min, max);
    return distrib(gen32);
}

#endif /* rng_hpp */
