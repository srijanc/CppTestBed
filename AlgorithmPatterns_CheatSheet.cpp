// Algorithm Patterns Cheat Sheet
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

int algoPatternCheatSheet() {
    // 1. Prefix Sums
    int n = 10;
    std::vector<int> A = {1, 2, 3};
    std::vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i)
        prefix[i+1] = prefix[i] + A[i];

    // 2. Hash Maps for Counting / Lookups
    std::unordered_map<int, int> count;
    for (int x : A) count[x]++;

    // 3. Two Pointers (Sliding Window)
    int left = 0, sum = 0, target = 20;
    for (int right = 0; right < n; ++right) {
        sum += A[right];
        while (sum > target) sum -= A[left++];
    }

    // 4. Stack for Next Greater Element / Balanced Parentheses
    std::stack<int> stk;
    for (int x : A) {
        while (!stk.empty() && stk.top() < x) stk.pop();
        stk.push(x);
    }

    // 5. BFS/DFS on Graphs
    std::queue<int> q;
    std::vector<bool> visited(n, false);
    std::vector<std::vector<int>> adj = {
        {1, 2, 3},
        {2, 3, 4}
    };
    int start = 1;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // 6. Binary Search Template
    int l = 0, r = n-1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (A[mid] == target)
            return mid;
        else if (A[mid] < target)
            l = mid + 1;
        else r = mid - 1;
    }

    return 0;
}