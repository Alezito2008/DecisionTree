#include "Math.h"

#include <cmath>

float Math::Entropy(const std::vector<float>& probabilities) {
    float entropy = 0;

    for (auto p : probabilities) {
        entropy += p * log10(p);
    }

    return -entropy;
}
