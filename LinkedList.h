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
    std::string GetList() const;
  private:
    Node *head;
};


#endif