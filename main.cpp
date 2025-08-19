#include <iostream>
#include <format>
#include <array>
#include <random>

#include "LinkedList.h"

int main()
{

    LinkedList myList;

    for(auto i = 0; i < 25; i += 5)
    {
        myList.Add(i);
    }

    std::cout << std::format("{}\n", myList.GetList());

    myList.Reverse();

    std::cout << std::format("{}\n", myList.GetList());

    std::array<Node*, 3> selectedNodes;
    selectedNodes.at(0) = myList.GetNodeByValue(static_cast<int32_t>(10));
    selectedNodes.at(1) = myList.GetNodeByValue(static_cast<int32_t>(15));
    selectedNodes.at(2) = myList.GetNodeByValue(static_cast<int32_t>(0));
    for (auto i = 0; i < 3; ++i)
    {
        myList.Delete(selectedNodes.at(i));
        
    }
    selectedNodes.fill(nullptr);
    std::cout << std::format("{}\n", myList.GetList());

    myList.Add(100);
    myList.Add(400);
    myList.Add(800);

    std::cout << std::format("{}\n", myList.GetList());
    
    return 0;
}