#ifndef NODE_H
#define NODE_H

#include <cstdint>
#include <format>
#include <memory>

class Node {
  public:
    Node(int32_t value);
    Node();
    int32_t value;
    std::unique_ptr<Node> next;
};

#endif