#include "LinkedList.h"
#include <sstream>

LinkedList::LinkedList()
{
    head = nullptr;
}

void LinkedList::Add(int32_t value)
{
    std::unique_ptr<Node> newNode = std::make_unique<Node>(value);


    // Welocome the new node to the list by steralizing it
    newNode->next = nullptr;
    // Special proceedure for welcoming the very first node:
    if (head == nullptr)
    {
        head = std::move(newNode);
        return;
    }

    // Procedure for slightly less important nodes that come after the first because
    // the first node is already experiencing true bliss.
    Node *current = head.get();

    while(current->next != nullptr) // Find a nice spot at the very end of the list!
    {
        current = current->next.get();
    }
    current->next = std::move(newNode); 
}

void LinkedList::Delete(Node *doomedNode)
{
    // Traverse the list until the doomed node is found. If it's hiding here. 
    // It will be found and... dealt with.
    Node *current = head.get();
    Node* previous = nullptr;
    while(current != nullptr)
    {
        if(current->value == doomedNode->value)
        {
            if(previous == nullptr) // This means head node is to be detained immediately.
            {
                head = std::move(head->next);
            }
            else
            {
                previous->next = std::move(current->next);
            }
            return;
        }
        // Not the right node, keep moving forward!
        previous = current;
        current = current->next.get();
    }
}

std::string LinkedList::GetList() const
{
    std::ostringstream output;

    Node* current = head.get();
    while(current != nullptr)
    {
        output << current->value << " ";
        current = current->next.get();
    }
    return output.str();
}

void LinkedList::Reverse()
{
    std::unique_ptr<Node> prev = nullptr;
    std::unique_ptr<Node> current = std::move(head);
    while(current)
    {
        std::unique_ptr<Node> next = std::move(current->next);
        current->next = std::move(prev);
        prev = std::move(current);
        current = std::move(next);
    }
    head = std::move(prev);
}

LinkedList::~LinkedList()
{
    Clear();
}

Node* LinkedList::GetNodeByValue(int32_t value)
{
    Node *result = nullptr;
    
    // Traverse starting at head
    Node *current = head.get();

    while(current)
    {
        if(current->value == value) {
            result = current;
            break;
        }
        current = current->next.get();

    }

    return result;
}

void LinkedList::Clear()
{
    // Traverse the list and delete every node on the way!
    std::unique_ptr<Node> current = std::move(head);
    while(current)
    {
        std::unique_ptr<Node> next = std::move(current->next);
        current = std::move(next);
    }
    head = nullptr;
}