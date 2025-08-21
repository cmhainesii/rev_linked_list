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

    std::array<int32_t, 3> selectedNodes;
    selectedNodes.at(0) = 10;
    selectedNodes.at(1) = 15;
    selectedNodes.at(2) = 0;
    for (auto i = 0; i < 3; ++i)
    {
        myList.Delete(myList.GetNodeByValue(selectedNodes.at(i)));
        
    }
    selectedNodes = {};
    std::cout << std::format("{}\n", myList.GetList());

    myList.Add(100);
    myList.Add(400);
    myList.Add(800);

    std::cout << std::format("{}\n", myList.GetList());

    // Try clearing the list:
    myList.Clear();

    std::cout << std::format("Blank: {}\n", myList.GetList());

    myList.Add(420);
    myList.Add(69);

    std::cout << std::format("Not blank: {}\n", myList.GetList());
    
    return 0;
}