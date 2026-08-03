#ifndef GENERATOR_H
#define GENERATOR_H

#include <random>

/**
 * @class Generator
 * @brief Class providing functions for random number generation.
 * 
 * This class contains static methods to generate random numbers within a specified range.
 * It uses the Mersenne Twister engine (std::mt19937) for high-quality pseudo-random number generation.
 */
class Generator {
public:
    /**
     * @brief Generates a random integer within a specified range.
     * 
     * This function generates a random integer in the range [min, max].
     * If the `min` value is greater than `max`, the values are automatically swapped.
     * 
     * @param min The minimum value of the range (inclusive).
     * @param max The maximum value of the range (inclusive).
     * @return A random integer within the range [min, max].
     * 
     * @note This function uses a hardware-based random number generator 
     * (std::random_device) and the Mersenne Twister engine (std::mt19937).
     */
    static int randomNumber(int min, int max) {
        // Swap values if min is greater than max
        if (min > max) {
            std::swap(min, max);
        }

        // Hardware-based random number generator
        static std::random_device rd;

        // Mersenne Twister engine initialized with the random device
        static std::mt19937 gen(rd());

        // Uniform distribution in the range [min, max]
        std::uniform_int_distribution<int> dist(min, max);

        // Generate and return the random number
        return dist(gen);
    }
};

#endif