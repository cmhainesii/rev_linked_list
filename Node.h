#ifndef NODE_H
#define NODE_H

#include <cstdint>
#include <format>

class Node {
  public:
    Node(int32_t value);
    Node();
    int32_t value;
    Node *next;
};

#endif