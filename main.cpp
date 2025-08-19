#include <iostream>
#include <format>
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



    // Ok, now let's have some real fun!
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distInt(69, 420);
    std::uniform_real_distribution<double> distDouble(0.0, 1.0);
    LinkedList myBrandNewList = LinkedList();
    for (auto i = 0; i < 20000000; i++)
    {
        myBrandNewList.Add(distInt(gen));
    }
    std::cout << "done\n";
    std::cin.get();

    return 0;
}