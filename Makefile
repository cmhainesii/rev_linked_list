CXX := clang++
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -Wpedantic

rev_linked_list: Node.cpp LinkedList.cpp main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@


.PHONY: clean
clean:
	rm -f rev_linked_list