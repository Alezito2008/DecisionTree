#include <iostream>
#include <vector>

#include "DecisionTree.h"

#include "Math.h"
#include <cmath>

void DecisionTree::Test() {
    std::vector<float> probs{3./8., 5./8.};
    std::cout << Math::Entropy(probs) << std::endl;
};
