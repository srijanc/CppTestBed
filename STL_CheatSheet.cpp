// STL Cheat Sheet
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

void stlCheatSheet() {
    // 1. Vectors and Iteration
    std::vector<int> v = {1, 2, 3};
    for (int x : v) {
        std::cout << x;
    }

    // 2. Sets and Maps
    std::set<int> s;
    s.insert(1);
    s.count(1); // check existence

    std::map<std::string, int> m;
    m["a"] = 1;

    // 3. Unordered Maps/Sets
    std::unordered_map<int, int> um;
    um[1] = 100;

    // 4. Priority Queue
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    // 5. Algorithms
    std::sort(v.begin(), v.end());
    std::reverse(v.begin(), v.end());
    std::binary_search(v.begin(), v.end(), 3);
}