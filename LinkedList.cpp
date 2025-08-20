#include "LinkedList.h"
#include <sstream>

LinkedList::LinkedList()
{
    head = nullptr;
}

void LinkedList::Add(int32_t value)
{
    Node *newNode = new Node(value);


    // Welocome the new node to the list by neutering it
    newNode->next = nullptr;
    // Special proceedure for welcoming the very first node:
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    // Procedure for slightly less important nodes that come after the first because
    // the first node is already experiencing true bliss.
    Node *current = head;
    while(current->next != nullptr) // Find a nice spot at the very end of the list!
    {
        current = current->next;
    }
    current->next = newNode; 
}

void LinkedList::Delete(Node *doomedNode)
{
    // Traverse the list until the doomed node is found. If it's hiding here. 
    // It will be found and... dealt with.
    Node *current = head;
    Node *previous = nullptr;
    while(current != nullptr)
    {
        if(current->value == doomedNode->value)
        {
            if(previous == nullptr) // This means head node is to be detained immediately.
            {
                head = head->next;
            }
            else
            {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        // Not the right node, keep moving forward!
        previous = current;
        current = current->next;
    }
}

std::string LinkedList::GetList() const
{
    std::ostringstream output;

    Node* current = head;
    while(current != nullptr)
    {
        output << current->value << " ";
        current = current->next;
    }
    return output.str();
}

void LinkedList::Reverse()
{
    Node *prev = nullptr;
    Node *current = head;
    while(current != nullptr)
    {
        Node *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
}

LinkedList::~LinkedList()
{
    Clear();
}

Node* LinkedList::GetNodeByValue(int32_t value)
{
    Node *result = nullptr;
    
    // Traverse starting at head
    Node *current = head;

    while(current)
    {
        if(current->value == value) {
            result = current;
            break;
        }
        current = current->next;

    }

    return result;
}

void LinkedList::Clear()
{
    // Traverse the list and delete every node on the way!
    Node* current = head;
    while(current)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}