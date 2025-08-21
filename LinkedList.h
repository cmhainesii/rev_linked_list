#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>

class LinkedList
{
  public:
    LinkedList();
    ~LinkedList();

    LinkedList(const LinkedList&    ) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void Add(int32_t value);
    void Delete(Node *doomedNode);
    void Reverse();
    Node* GetNodeByValue(int32_t value);
    std::string GetList() const;
    void Clear();
  private:
    std::unique_ptr<Node> head;
};


#endif