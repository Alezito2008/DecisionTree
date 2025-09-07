#include <iostream>

#include "CSVReader.h"
#include "DecisionTree.h"

int main() {
    std::cout << "Corriendo tests" << std::endl;
    // DecisionTree::Test();
    CSVReader csvr("../../data.csv");
    Serial heritage = csvr.GetColumn("heritage");
    std::cout << heritage;

    return 0;
}
