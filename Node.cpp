#include "Node.h"


Node::Node(int32_t value)
{
    this->value = value;
    this->next = nullptr;
}

Node::Node()
{
    this->value = 0;
    this->next = nullptr;
}