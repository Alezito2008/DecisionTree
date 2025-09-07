//
// Created by alezito on 9/5/25.
//

#pragma once

#include <vector>

struct NodeCondition {
    int passes;
    float entropy;
};

struct Node {
    NodeCondition isTrue;
    NodeCondition isFalse;
    std::vector<Node> childNodes;
};

class Tree {
public:
    inline const std::vector<Node>& GetNodes() const { return m_nodes; }
private:
    std::vector<Node> m_nodes;
};
